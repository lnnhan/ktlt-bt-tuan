
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
    ifstream fin("array.txt");
    if (!fin) {
        cerr << "Cannot open array.txt\n";
        return 1;
    }

    int n;
    long long S;
    fin >> n >> S;
    vector<long long> a(n);
    for (auto& x : a)
        fin >> x;

    if (n == 0) {
        cout << "NONE\n";
        return 0;
    }
    if (S == 0) {
        cout << "len=1 / l=0 / r=0\n";
        return 0;
    }

    long long sum = 0;
    int l = 0;
    int bestL = -1;
    int bestR = -1;
    int bestLen = n + 1;
    for (int r = 0; r < n; ++r) {
        sum += a[r];
        while (l <= r && sum >= S) {
            int len = r - l + 1;
            if (len < bestLen) {
                bestLen = len;
                bestL = l;
                bestR = r;
            }
            sum -= a[l++];
        }
    }

    if (bestL == -1)
        cout << "NONE\n";
    else
        cout << "len=" << bestLen << " / l=" << bestL << " / r=" << bestR << "\n";

    return 0;
}
