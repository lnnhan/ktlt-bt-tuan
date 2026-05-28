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

int main() {
    ifstream fa("array.txt");
    ifstream fq("queries.txt");
    if (!fa || !fq) {
        cerr << "Cannot open input file\n";
        return 1;
    }

    int n;
    fa >> n;
    vector<int> a(n);
    vector<vector<int>> cnt(101, vector<int>(n + 1, 0));
    for (int i = 0; i < n; i++) {
        fa >> a[i];
        for (int v = 0; v <= 100; v++)
            cnt[v][i + 1] = cnt[v][i] + (a[i] == v);
    }

    int l, r;
    while (fq >> l >> r) {
        if (l < 0 || r >= n || l > r) {
            cout << "INVALID\n";
            continue;
        }

        int bestValue = 0;
        int bestCount = -1;
        for (int v = 0; v <= 100; v++) {
            int c = cnt[v][r + 1] - cnt[v][l];
            if (c > bestCount) {
                bestCount = c;
                bestValue = v;
            }
        }

        cout << bestValue << " " << bestCount << "\n";
    }

    return 0;
}
