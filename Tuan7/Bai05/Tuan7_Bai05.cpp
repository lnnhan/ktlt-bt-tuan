#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
#include <cctype>
#include <sstream>
#include <algorithm>

using namespace std;
string trim(const string &s)
{
    size_t b = s.find_first_not_of(" \t\r\n");
    if (b == string::npos)
        return "";
    size_t e = s.find_last_not_of(" \t\r\n");
    return s.substr(b, e - b + 1);
}
string lowerStr(string s)
{
    for (char &c : s)
        c = (char)tolower((unsigned char)c);
    return s;
}
bool isMissing(string s)
{
    s = lowerStr(trim(s));
    return s.empty() || s == "na" || s == "nan" || s == "n/a";
}
vector<string> splitCSV(const string &line)
{
    vector<string> res;
    string cell;
    stringstream ss(line);
    while (getline(ss, cell, ','))
        res.push_back(trim(cell));
    if (!line.empty() && line.back() == ',')
        res.push_back("");
    if (line.empty())
        res.push_back("");
    return res;
}

struct Fraction
{
    long long num, den;
};
long long gcdll(long long a, long long b)
{
    a = llabs(a);
    b = llabs(b);
    while (b)
    {
        long long t = a % b;
        a = b;
        b = t;
    }
    return a ? a : 1;
}
bool normalize(Fraction &f)
{
    if (f.den == 0)
        return false;
    if (f.num == 0)
    {
        f.den = 1;
        return true;
    }
    if (f.den < 0)
    {
        f.num = -f.num;
        f.den = -f.den;
    }
    long long g = gcdll(f.num, f.den);
    f.num /= g;
    f.den /= g;
    return true;
}
Fraction addFrac(Fraction a, Fraction b)
{
    Fraction r{a.num * b.den + b.num * a.den, a.den * b.den};
    normalize(r);
    return r;
}
Fraction subFrac(Fraction a, Fraction b)
{
    Fraction r{a.num * b.den - b.num * a.den, a.den * b.den};
    normalize(r);
    return r;
}
Fraction mulFrac(Fraction a, Fraction b)
{
    Fraction r{a.num * b.num, a.den * b.den};
    normalize(r);
    return r;
}
int cmpFrac(Fraction a, Fraction b)
{
    __int128 L = (__int128)a.num * b.den, R = (__int128)b.num * a.den;
    return (L < R) ? -1 : (L > R);
}
string str(Fraction f) { return to_string(f.num) + "/" + to_string(f.den); }
int main()
{
    ifstream fin("fractions.csv"), fc("config.txt");
    if (!fin || !fc)
    {
        cerr << "Cannot open input file\n";
        return 1;
    }
    Fraction lo, hi;
    fc >> lo.num >> lo.den >> hi.num >> hi.den;
    normalize(lo);
    normalize(hi);
    vector<Fraction> in;
    string line;
    int valid = 0, outR = 0;
    while (getline(fin, line))
    {
        auto c = splitCSV(line);
        if (c.size() < 2)
            continue;
        Fraction f{stoll(c[0]), stoll(c[1])};
        if (!normalize(f))
            continue;
        valid++;
        if (cmpFrac(lo, hi) <= 0 && cmpFrac(lo, f) <= 0 && cmpFrac(f, hi) <= 0)
            in.push_back(f);
        else
            outR++;
    }
    sort(in.begin(), in.end(), [](Fraction a, Fraction b)
         { return cmpFrac(a, b) < 0; });
    ofstream out("filtered.csv");
    for (auto f : in)
        out << f.num << "," << f.den << "\n";
    cout << "total_valid=" << valid << " / in_range=" << in.size() << " / out_of_range=" << outR;
}
