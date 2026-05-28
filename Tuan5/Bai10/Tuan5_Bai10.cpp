#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <unordered_map>
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

    int n, K;
    fin >> n >> K;

    vector<int> a(n);
    set<int> all;
    for (int i = 0; i < n; ++i) {
        fin >> a[i];
        all.insert(a[i]);
    }

    if (K > static_cast<int>(all.size())) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    unordered_map<int, int> freq;
    int distinct = 0;
    int l = 0;
    int bestLen = n + 1;
    int bestL = -1;
    int bestR = -1;

    for (int r = 0; r < n; ++r) {
        if (freq[a[r]]++ == 0)
            distinct++;
        while (distinct >= K) {
            int len = r - l + 1;
            if (len < bestLen) {
                bestLen = len;
                bestL = l;
                bestR = r;
            }
            if (--freq[a[l]] == 0)
                distinct--;
            l++;
        }
    }

    cout << "len=" << bestLen << " / l=" << bestL << " / r=" << bestR << "\n";
    return 0;
}
