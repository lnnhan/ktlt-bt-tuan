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
int main()
{
    ifstream fin("text.txt");
    if (!fin)
    {
        cerr << "Cannot open text.txt\n";
        return 1;
    }
    vector<long long> c(26);
    char ch;
    while (fin.get(ch))
    {
        unsigned char u = ch;
        if (isalpha(u))
        {
            char l = tolower(u);
            if (l >= 'a' && l <= 'z')
                c[l - 'a']++;
        }
    }
    ofstream out("char_freq.csv");
    out << "char,count\n";
    for (int i = 0; i < 26; i++)
        out << (char)('a' + i) << "," << c[i] << "\n";
}
