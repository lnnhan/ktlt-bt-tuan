#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>
#include <sstream>

using namespace std;

string trim(const string& s) {
    size_t b = s.find_first_not_of(" \t\r\n");
    if (b == string::npos)
        return "";
    size_t e = s.find_last_not_of(" \t\r\n");
    return s.substr(b, e - b + 1);
}

string lowerStr(string s) {
    for (char& c : s)
        c = (char)tolower((unsigned char)c);
    return s;
}

bool isMissing(string s) {
    s = lowerStr(trim(s));
    return s.empty() || s == "na" || s == "nan" || s == "n/a";
}

vector<string> splitCSV(const string& line) {
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

bool sumRange(const vector<long long>& pre, int l, int r, long long& ans) {
    int n = (int)pre.size();
    if (l < 0 || r >= n || l > r)
        return false;
    ans = pre[r] - (l ? pre[l - 1] : 0);
    return true;
}

int main() {
    ifstream fa("array.txt");
    ifstream fq("queries.txt");
    if (!fa || !fq) {
        cerr << "Cannot open input file\n";
        return 1;
    }

    int n;
    fa >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i)
        fa >> a[i];

    vector<long long> pre(n);
    for (int i = 0; i < n; ++i)
        pre[i] = a[i] + (i ? pre[i - 1] : 0);

    ofstream out("output.txt");
    if (!out) {
        cerr << "Cannot open output.txt\n";
        return 1;
    }

    int l, r;
    while (fq >> l >> r) {
        long long ans;
        if (sumRange(pre, l, r, ans))
            out << ans << "\n";
        else
            out << "INVALID\n";
    }

    return 0;
}
