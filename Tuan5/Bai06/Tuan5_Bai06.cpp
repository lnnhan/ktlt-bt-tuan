
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>
#include <sstream>
#include <cmath>
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
    ifstream fin("array.txt");
    if (!fin) {
        cerr << "Cannot open array.txt\n";
        return 1;
    }

    int n, k;
    fin >> n >> k;
    vector<double> a(n);
    for (auto& x : a)
        fin >> x;

    ofstream out("rolling_std.csv");
    if (!out) {
        cerr << "Cannot open rolling_std.csv\n";
        return 1;
    }

    out << "i,std_i\n";
    out << fixed << setprecision(6);
    if (k <= 0 || k > n)
        return 0;

    long double sum = 0;
    long double sum2 = 0;
    for (int i = 0; i < k; ++i) {
        sum += a[i];
        sum2 += a[i] * a[i];
    }

    for (int i = 0; i + k <= n; ++i) {
        if (i > 0) {
            sum += a[i + k - 1] - a[i - 1];
            sum2 += a[i + k - 1] * a[i + k - 1] - a[i - 1] * a[i - 1];
        }
        long double mean = sum / k;
        long double var = sum2 / k - mean * mean;
        if (var < 0 && var > -1e-12)
            var = 0;
        out << i << "," << sqrt((double)var) << "\n";
    }

    return 0;
}
