
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
    fin >> n;
    if (n == 0) {
        cout << "max_len=0\n";
        return 0;
    }

    vector<long long> a(n);
    for (auto& x : a)
        fin >> x;

    int start = 0;
    int bestL = 0;
    int bestR = 0;
    int bestLen = 1;

    for (int i = 1; i < n; ++i) {
        if (a[i] < a[i - 1])
            start = i;
        int len = i - start + 1;
        if (len > bestLen) {
            bestLen = len;
            bestL = start;
            bestR = i;
        }
    }

    cout << "max_len=" << bestLen << " / l=" << bestL << " / r=" << bestR << "\n";
    return 0;
}
