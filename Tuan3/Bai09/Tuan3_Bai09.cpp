#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cctype>

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

long long rangeSum(const vector<long long>& pre, int l, int r) {
    return pre[r + 1] - pre[l];
}

int main() {
    ifstream fin("commands.txt");
    if (!fin) {
        cerr << "Cannot open commands.txt\n";
        return 1;
    }

    int n;
    fin >> n;
    vector<long long> a(n);
    vector<long long> pre(n + 1, 0);
    for (int i = 0; i < n; i++) {
        fin >> a[i];
    }

    auto rebuild = [&]() {
        pre.assign(n + 1, 0);
        for (int i = 0; i < n; i++)
            pre[i + 1] = pre[i] + a[i];
    };

    rebuild();

    char type;
    while (fin >> type) {
        if (type == 'U') {
            int i;
            long long val;
            fin >> i >> val;
            if (0 <= i && i < n) {
                a[i] = val;
                rebuild();
            }
        } else if (type == 'Q') {
            int l, r;
            fin >> l >> r;
            if (l < 0 || r >= n || l > r)
                cout << "INVALID\n";
            else
                cout << rangeSum(pre, l, r) << "\n";
        }
    }

    return 0;
}
