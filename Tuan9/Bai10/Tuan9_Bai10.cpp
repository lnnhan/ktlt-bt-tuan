#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
#include <cctype>
#include <sstream>
#include <iomanip>
#include <cmath>
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
    ifstream idx("index.txt");
    if (!idx)
    {
        cerr << "Cannot open index.txt\n";
        return 1;
    }
    vector<string> files;
    string name;
    while (getline(idx, name))
    {
        name = trim(name);
        if (!name.empty())
            files.push_back(name);
    }
    int N = files.size();
    vector<unordered_map<string, int>> fs(N);
    vector<int> totals(N);
    unordered_map<string, int> df;
    for (int i = 0; i < N; i++)
    {
        ifstream fin(files[i]);
        string line;
        set<string> seen;
        while (getline(fin, line))
            for (auto &w : tokenize(normalizeLine(line)))
            {
                fs[i][w]++;
                totals[i]++;
                seen.insert(w);
            }
        for (auto &w : seen)
            df[w]++;
    }
    ofstream out("tfidf.csv");
    out << "file,word,tfidf\n"
        << fixed << setprecision(6);
    for (int i = 0; i < N; i++)
    {
        vector<pair<string, double>> v;
        for (auto &p : fs[i])
        {
            double tf = (double)p.second / max(1, totals[i]);
            double idf = log((double)N / df[p.first]);
            v.push_back({p.first, tf * idf});
        }
        sort(v.begin(), v.end(), [](const pair<string, double> &a, const pair<string, double> &b)
             { return a.second != b.second ? a.second > b.second : a.first < b.first; });
        for (int k = 0; k < (int)v.size() && k < 5; k++)
            out << files[i] << "," << v[k].first << "," << v[k].second << "\n";
    }
}
