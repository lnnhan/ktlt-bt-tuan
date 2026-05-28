
#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
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

    int n, k;
    fin >> n >> k;
    vector<double> a(n);
    for (auto& x : a)
        fin >> x;

    ofstream out("rolling_max.csv");
    if (!out) {
        cerr << "Cannot open rolling_max.csv\n";
        return 1;
    }

    out << "i,max_i\n";
    if (k <= 0 || k > n)
        return 0;

    deque<int> dq;
    for (int i = 0; i < n; ++i) {
        while (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();
        while (!dq.empty() && a[dq.back()] <= a[i])
            dq.pop_back();
        dq.push_back(i);
        if (i >= k - 1)
            out << i - k + 1 << "," << a[dq.front()] << "\n";
    }

    return 0;
}
