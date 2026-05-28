#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>
#include <sstream>
#include <iomanip>

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

int main() {
    ifstream fa("array.txt");
    ifstream fq("queries.txt");
    if (!fa || !fq) {
        cerr << "Cannot open input file\n";
        return 1;
    }

    int n;
    fa >> n;
    vector<long long> pre(n);
    for (int i = 0; i < n; i++) {
        long long x;
        fa >> x;
        pre[i] = x + (i ? pre[i - 1] : 0);
    }

    cout << fixed << setprecision(6);
    int l, r;
    while (fq >> l >> r) {
        if (l < 0 || r >= n || l > r)
            cout << "INVALID\n";
        else {
            long long s = pre[r] - (l ? pre[l - 1] : 0);
            cout << (double)s / (r - l + 1) << "\n";
        }
    }

    return 0;
}
