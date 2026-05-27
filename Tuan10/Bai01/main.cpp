// ============================================================
// Tuan 10 - Bai 1: Pipeline M0 hoan chinh: CSV Cleaning
// Doc data.csv (id, value). Missing: NA/blank. Tinh mean bo missing;
// impute missing = mean; tinh Z-score.
// Ghi report.csv: id, value_imputed, zscore (setprecision(6)).
// Ghi summary.txt: count_valid, count_missing, mean, std.
// Case bien: tat ca missing -> mean=0, std=0, moi z=0.
// ============================================================
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

struct Record {
    string id;
    bool missing;
    double value;
};

string trim(const string& s) {
    size_t st = s.find_first_not_of(" \t\r\n");
    size_t en = s.find_last_not_of(" \t\r\n");
    if (st == string::npos) return "";
    return s.substr(st, en - st + 1);
}

bool isMissing(const string& s) {
    string t = trim(s);
    if (t.empty()) return true;
    // Case-insensitive "na" or "nan"
    string low = t;
    for (char& c : low) if (c >= 'A' && c <= 'Z') c = c - 'A' + 'a';
    return (low == "na" || low == "nan");
}

// Parse CSV into records. First line is header.
vector<Record> parseCSV(const string& path) {
    vector<Record> records;
    ifstream fin(path);
    if (!fin) { cerr << "Error: cannot open " << path << "\n"; return records; }
    string line;
    getline(fin, line); // skip header
    while (getline(fin, line)) {
        if (trim(line).empty()) continue;
        istringstream ss(line);
        string sid, sval;
        if (!getline(ss, sid, ',')) continue;
        if (!getline(ss, sval)) continue;
        Record r;
        r.id = trim(sid);
        r.missing = isMissing(sval);
        r.value = r.missing ? 0.0 : stod(trim(sval));
        records.push_back(r);
    }
    return records;
}

// Compute mean and std from records (ignoring missing).
void computeStats(const vector<Record>& recs, double& mean, double& std_) {
    double sum = 0.0;
    int cnt = 0;
    for (const Record& r : recs)
        if (!r.missing) { sum += r.value; cnt++; }
    mean = (cnt > 0) ? sum / cnt : 0.0;

    if (cnt <= 0) { std_ = 0.0; return; }
    long double acc = 0.0;
    for (const Record& r : recs)
        if (!r.missing) {
            long double d = r.value - mean;
            acc += d * d;
        }
    std_ = static_cast<double>(sqrtl(acc / cnt));
}

// Impute missing and compute z-scores. Write report.csv.
void imputeAndScore(const vector<Record>& recs, double mean, double std_,
                    const string& reportPath) {
    ofstream fout(reportPath);
    if (!fout) { cerr << "Error: cannot open " << reportPath << "\n"; return; }
    fout << "id,value_imputed,zscore\n";
    fout << fixed << setprecision(6);
    for (const Record& r : recs) {
        double val = r.missing ? mean : r.value;
        double z   = (std_ == 0.0) ? 0.0 : (val - mean) / std_;
        fout << r.id << "," << val << "," << z << "\n";
    }
}

int main() {
    vector<Record> recs = parseCSV("data.csv");
    if (recs.empty()) {
        cerr << "No records loaded.\n";
        return 1;
    }

    double mean, std_;
    computeStats(recs, mean, std_);
    imputeAndScore(recs, mean, std_, "report.csv");

    int cntValid   = 0, cntMissing = 0;
    for (const Record& r : recs) (r.missing ? cntMissing : cntValid)++;

    ofstream fsum("summary.txt");
    if (!fsum) { cerr << "Error: cannot open summary.txt\n"; return 1; }
    fsum << fixed << setprecision(6);
    fsum << "count_valid="   << cntValid   << "\n";
    fsum << "count_missing=" << cntMissing << "\n";
    fsum << "mean="          << mean       << "\n";
    fsum << "std="           << std_       << "\n";

    cout << "Done. report.csv and summary.txt written.\n";
    return 0;
}
