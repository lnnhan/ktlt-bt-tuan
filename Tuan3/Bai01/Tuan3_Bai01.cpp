#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
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

vector<long long> buildPrefix(const vector<long long>& a) {
    vector<long long> pre(a.size());
    for (size_t i = 0; i < a.size(); ++i)
        pre[i] = a[i] + (i ? pre[i - 1] : 0);
    return pre;
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

    auto pre = buildPrefix(a);

    ofstream out("prefix.txt");
    if (!out) {
        cerr << "Cannot open prefix.txt\n";
        return 1;
    }

    for (size_t i = 0; i < pre.size(); ++i)
        out << i << ": " << pre[i] << "\n";

    return 0;
}
