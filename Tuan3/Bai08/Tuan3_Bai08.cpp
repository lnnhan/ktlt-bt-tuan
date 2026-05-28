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

long long modpow(long long a, long long e, long long m) {
    long long result = 1 % m;
    long long base = a % m;
    while (e > 0) {
        if (e & 1)
            result = (long long)((__int128)result * base % m);
        base = (long long)((__int128)base * base % m);
        e >>= 1;
    }
    return result;
}

int main() {
    ifstream fa("array.txt");
    ifstream fq("queries.txt");
    if (!fa || !fq) {
        cerr << "Cannot open input file\n";
        return 1;
    }

    int n;
    long long M;
    fa >> n >> M;

    vector<long long> pre(n + 1, 1);
    vector<int> zero(n + 1, 0);
    for (int i = 0; i < n; i++) {
        long long x;
        fa >> x;
        pre[i + 1] = pre[i] * (x % M) % M;
        zero[i + 1] = zero[i] + (x == 0);
    }

    int l, r;
    while (fq >> l >> r) {
        if (l < 0 || r >= n || l > r) {
            cout << "INVALID\n";
            continue;
        }
        if (zero[r + 1] - zero[l] > 0) {
            cout << "INVALID\n";
            continue;
        }
        long long result = pre[r + 1] * modpow(pre[l], M - 2, M) % M;
        cout << result << "\n";
    }

    return 0;
}
