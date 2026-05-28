#include <iostream>
#include <fstream>
#include <limits>
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

int main() {
    ifstream fin("array.txt");
    if (!fin) {
        cerr << "Cannot open array.txt\n";
        return 1;
    }

    int n;
    fin >> n;
    if (n == 0) {
        cout << "EMPTY\n";
        return 0;
    }

    long long pre = 0;
    long long minPre = 0;
    long long best = numeric_limits<long long>::min();
    int minIdx = -1;
    int bestL = 0;
    int bestR = 0;

    for (int i = 0; i < n; i++) {
        long long x;
        fin >> x;
        pre += x;
        if (pre - minPre > best) {
            best = pre - minPre;
            bestL = minIdx + 1;
            bestR = i;
        }
        if (pre < minPre) {
            minPre = pre;
            minIdx = i;
        }
    }

    cout << "max_sum=" << best << " / l=" << bestL << " / r=" << bestR << "\n";
    return 0;
}
