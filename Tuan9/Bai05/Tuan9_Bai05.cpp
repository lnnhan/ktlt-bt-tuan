#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
#include <cctype>
#include <sstream>

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
string normalizeLine(const string &s)
{
    string out;
    bool sp = false;
    for (unsigned char ch : s)
    {
        if (isalnum(ch))
        {
            out.push_back((char)tolower(ch));
            sp = false;
        }
        else
        {
            if (!sp && !out.empty())
            {
                out.push_back(' ');
                sp = true;
            }
        }
    }
    if (!out.empty() && out.back() == ' ')
        out.pop_back();
    return out;
}
vector<string> tokenize(const string &s)
{
    vector<string> v;
    string w;
    stringstream ss(s);
    while (ss >> w)
        v.push_back(w);
    return v;
}
unordered_map<string, int> freqFile(string path)
{
    ifstream fin(path);
    unordered_map<string, int> f;
    string line;
    while (getline(fin, line))
        for (auto &w : tokenize(normalizeLine(line)))
            f[w]++;
    return f;
}
int main()
{
    auto a = freqFile("file1.txt"), b = freqFile("file2.txt");
    set<string> keys;
    for (auto &p : a)
        keys.insert(p.first);
    for (auto &p : b)
        keys.insert(p.first);
    ofstream out("comparison.csv");
    out << "word,count_file1,count_file2\n";
    int only1 = 0, only2 = 0, both = 0;
    for (auto &w : keys)
    {
        int x = a[w], y = b[w];
        out << w << "," << x << "," << y << "\n";
        if (x && y)
            both++;
        else if (x)
            only1++;
        else
            only2++;
    }
    cout << "only_in_1=" << only1 << " / only_in_2=" << only2 << " / in_both=" << both;
}
