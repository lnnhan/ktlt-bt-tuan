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

    int currentLen = 0;
    int start = 0;
    int bestLen = 0;
    int bestL = 0;
    int bestR = -1;

    for (int i = 0; i < n; ++i) {
        long long x;
        fin >> x;
        if (x >= 0) {
            if (currentLen == 0)
                start = i;
            currentLen++;
            if (currentLen > bestLen) {
                bestLen = currentLen;
                bestL = start;
                bestR = i;
            }
        } else {
            currentLen = 0;
        }
    }

    cout << "max_len=" << bestLen;
    if (bestLen > 0)
        cout << " / l=" << bestL << " / r=" << bestR;
    cout << "\n";
    return 0;
}
