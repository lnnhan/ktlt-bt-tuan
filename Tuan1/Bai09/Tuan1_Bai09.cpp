#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cctype>
#include <set>
#include <map>

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
    ifstream fa("fileA.csv");
    ifstream fb("fileB.csv");
    if (!fa || !fb) {
        cerr << "Cannot open input files\n";
        return 1;
    }

    map<string, double> A;
    map<string, double> B;
    string line;

    while (getline(fa, line)) {
        auto c = splitCSV(line);
        if (c.size() >= 2 && !isMissing(c[1]))
            A[c[0]] = stod(c[1]);
    }

    while (getline(fb, line)) {
        auto c = splitCSV(line);
        if (c.size() >= 2 && !isMissing(c[1]))
            B[c[0]] = stod(c[1]);
    }

    ofstream out("merged.csv");
    if (!out) {
        cerr << "Cannot open merged.csv\n";
        return 1;
    }

    int joined = 0;
    int only = 0;
    out << "id,score_A,score_B,diff\n";

    for (auto& p : A) {
        auto it = B.find(p.first);
        if (it != B.end()) {
            out << p.first << "," << p.second << "," << it->second << "," << p.second - it->second << "\n";
            joined++;
        } else {
            only++;
        }
    }

    for (auto& p : B) {
        if (!A.count(p.first))
            only++;
    }

    cout << "joined=" << joined << " / only_one_file=" << only << "\n";
    return 0;
}

