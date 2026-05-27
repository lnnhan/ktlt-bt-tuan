// ============================================================
// Tuan 10 - Bai 6: Dashboard tong hop 1 file
// Doc data.csv (id, value1, value2, ..., valueN - N cot so, co the missing).
// Voi moi cot: tinh count, missing, min, max, mean, std.
// Ghi dashboard.csv (1 hang = 1 cot thong ke).
// To chuc theo M0: 1 ham cho moi buoc, goi tu main().
// ============================================================
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

string trim(const string& s) {
    size_t st = s.find_first_not_of(" \t\r\n");
    size_t en = s.find_last_not_of(" \t\r\n");
    if (st == string::npos) return "";
    return s.substr(st, en - st + 1);
}

bool isMissing(const string& s) {
    string t = trim(s);
    if (t.empty()) return true;
    string low = t;
    for (char& c : low) if (c >= 'A' && c <= 'Z') c = c - 'A' + 'a';
    return (low == "na" || low == "nan");
}

// Read CSV into a 2D vector of strings. First row = header.
// Returns the header and values (each row is a vector of strings).
vector<vector<string>> readCSV(const string& path, vector<string>& header) {
    vector<vector<string>> data;
    ifstream fin(path);
    if (!fin) { cerr << "Error: cannot open " << path << "\n"; return data; }
    string line;
    if (!getline(fin, line)) return data;
    istringstream hss(line);
    string h;
    while (getline(hss, h, ',')) header.push_back(trim(h));

    while (getline(fin, line)) {
        if (trim(line).empty()) continue;
        istringstream ss(line);
        string cell;
        vector<string> row;
        while (getline(ss, cell, ',')) row.push_back(trim(cell));
        data.push_back(row);
    }
    return data;
}

struct ColStats {
    string name;
    int countValid, countMissing;
    double min_, max_, mean, std_;
};

// Compute statistics for one column (column index col, skipping column 0 = id).
ColStats computeColStats(const string& name, const vector<vector<string>>& data, int col) {
    ColStats s;
    s.name = name;
    s.countValid = 0; s.countMissing = 0;
    s.min_ = 0; s.max_ = 0; s.mean = 0; s.std_ = 0;

    vector<double> vals;
    for (const auto& row : data) {
        if (col >= static_cast<int>(row.size()) || isMissing(row[col])) {
            s.countMissing++;
        } else {
            vals.push_back(stod(row[col]));
            s.countValid++;
        }
    }

    if (vals.empty()) return s;

    s.min_ = vals[0]; s.max_ = vals[0];
    double sum = 0;
    for (double v : vals) {
        if (v < s.min_) s.min_ = v;
        if (v > s.max_) s.max_ = v;
        sum += v;
    }
    s.mean = sum / vals.size();

    long double acc = 0;
    for (double v : vals) { long double d = v - s.mean; acc += d * d; }
    s.std_ = static_cast<double>(sqrtl(acc / vals.size()));

    return s;
}

// Write dashboard CSV.
void writeDashboard(const string& path, const vector<ColStats>& stats) {
    ofstream fout(path);
    if (!fout) { cerr << "Error: cannot open " << path << "\n"; return; }
    fout << "column,count,missing,min,max,mean,std\n";
    fout << fixed << setprecision(6);
    for (const ColStats& s : stats)
        fout << s.name << "," << s.countValid << "," << s.countMissing
             << "," << s.min_ << "," << s.max_
             << "," << s.mean << "," << s.std_ << "\n";
}

int main() {
    vector<string> header;
    vector<vector<string>> data = readCSV("data.csv", header);

    // Columns 1..N are numeric (column 0 is id)
    vector<ColStats> stats;
    for (int col = 1; col < static_cast<int>(header.size()); col++)
        stats.push_back(computeColStats(header[col], data, col));

    writeDashboard("dashboard.csv", stats);

    cout << "Done. Written to dashboard.csv\n";
    return 0;
}
