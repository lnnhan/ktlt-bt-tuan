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
    ifstream fin("text.txt", ios::binary);
    if (!fin)
    {
        cerr << "Cannot open text.txt\n";
        return 1;
    }
    string s((istreambuf_iterator<char>(fin)), {});
    int total = 0, nonascii = 0, letters = 0;
    for (unsigned char ch : s)
    {
        if (!isspace(ch))
        {
            total++;
            if (ch < 32 || ch > 126)
                nonascii++;
            if (isalpha(ch))
                letters++;
        }
    }
    ofstream out("lang.txt");
    if (total == 0)
        out << "UNKNOWN";
    else if (nonascii * 100 > 5 * total)
        out << "VI_SIMPLE";
    else if (nonascii == 0 && letters > 0)
        out << "EN";
    else
        out << "UNKNOWN";
}
