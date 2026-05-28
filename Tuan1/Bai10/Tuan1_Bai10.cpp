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
    ifstream fin("log.txt");
    if (!fin) {
        cerr << "Cannot open log.txt\n";
        return 1;
    }

    map<string, int> cnt{{"INFO", 0}, {"WARN", 0}, {"ERROR", 0}};
    string line;
    string first = "NONE";
    string last = "NONE";

    while (getline(fin, line)) {
        size_t lb = line.find('[');
        size_t rb = line.find(']');
        if (lb == string::npos || rb == string::npos || rb < lb)
            continue;

        string lev = line.substr(lb + 1, rb - lb - 1);
        if (cnt.count(lev))
            cnt[lev]++;

        if (lev == "ERROR") {
            string ts = line.substr(0, 19);
            if (first == "NONE")
                first = ts;
            last = ts;
        }
    }

    ofstream out("summary.txt");
    if (!out) {
        cerr << "Cannot open summary.txt\n";
        return 1;
    }

    out << "INFO=" << cnt["INFO"]
        << " / WARN=" << cnt["WARN"]
        << " / ERROR=" << cnt["ERROR"]
        << " / first_error=" << first
        << " / last_error=" << last
        << "\n";

    return 0;
}

