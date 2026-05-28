#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cctype>
#include <iomanip>
#include <math.h.>

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
    ifstream fc("config.txt");
    if (!fa || !fc) {
        cerr << "Cannot open input file\n";
        return 1;
    }

    int n;
    fa >> n;
    vector<double> a(n);
    vector<double> pre(n + 1, 0.0);
    for (int i = 0; i < n; i++) {
        fa >> a[i];
        pre[i + 1] = pre[i] + a[i];
    }

    int minLen;
    fc >> minLen;

    double best = -1e300;
    int bestL = 0;
    int bestR = -1;
    int bestLen = 0;

    for (int l = 0; l < n; l++) {
        for (int r = l + minLen - 1; r < n; r++) {
            int len = r - l + 1;
            double mean = (pre[r + 1] - pre[l]) / len;
            if (mean > best + 1e-12 || (fabs(mean - best) <= 1e-12 && (len > bestLen || (len == bestLen && l < bestL)))) {
                best = mean;
                bestL = l;
                bestR = r;
                bestLen = len;
            }
        }
    }

    cout << fixed << setprecision(6);
    if (bestR == -1)
        cout << "IMPOSSIBLE\n";
    else
        cout << "mean=" << best << " / l=" << bestL << " / r=" << bestR << " / length=" << bestLen << "\n";

    return 0;
}
