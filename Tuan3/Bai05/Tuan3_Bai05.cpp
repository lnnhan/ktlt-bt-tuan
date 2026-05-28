#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>
#include <sstream>
#include <unordered_map>

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

long long countRangesEqK(const vector<long long>& a, long long K, int& firstL, int& firstR) {
    unordered_map<long long, long long> freq;
    unordered_map<long long, vector<int>> pos;
    long long pre = 0;
    long long cnt = 0;
    freq[0] = 1;
    pos[0].push_back(-1);
    firstL = -1;
    firstR = -1;

    for (int i = 0; i < (int)a.size(); ++i) {
        pre += a[i];
        long long need = pre - K;
        if (freq.count(need)) {
            cnt += freq[need];
            if (firstL == -1) {
                firstL = pos[need][0] + 1;
                firstR = i;
            }
        }
        freq[pre]++;
        pos[pre].push_back(i);
    }

    return cnt;
}

int main() {
    ifstream fin("array.txt");
    if (!fin) {
        cerr << "Cannot open array.txt\n";
        return 1;
    }

    int n;
    fin >> n;
    vector<long long> a(n);
    for (auto& x : a)
        fin >> x;

    long long K;
    fin >> K;

    int l, r;
    long long c = countRangesEqK(a, K, l, r);
    cout << "count=" << c;
    if (c > 0)
        cout << " / example=" << l << "," << r;
    cout << "\n";

    return 0;
}
