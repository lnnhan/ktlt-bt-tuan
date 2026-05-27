// ============================================================
// Tuan 10 - Bai 9: Phat hien outlier IQR
// Doc values.csv (1 cot so thuc, khong missing). Tinh Q1, Q3, IQR = Q3-Q1.
// Outlier: x < Q1 - 1.5*IQR hoac x > Q3 + 1.5*IQR.
// Ghi outliers.csv: index, value. Ghi summary: Q1, Q3, IQR, n_outliers (setprecision(6)).
// ============================================================
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

string trim(const string& s) {
    size_t st = s.find_first_not_of(" \t\r\n");
    size_t en = s.find_last_not_of(" \t\r\n");
    if (st == string::npos) return "";
    return s.substr(st, en - st + 1);
}

// Read values from CSV (one per line, no header assumed or single column header).
bool readValues(const string& path, vector<double>& vals) {
    ifstream fin(path);
    if (!fin) { cerr << "Error: cannot open " << path << "\n"; return false; }
    string line;
    while (getline(fin, line)) {
        string t = trim(line);
        if (t.empty()) continue;
        // Skip non-numeric header
        try { vals.push_back(stod(t)); } catch (...) {}
    }
    return true;
}

// Simple insertion sort (for small arrays).
void insertionSort(vector<double>& v) {
    for (int i = 1; i < static_cast<int>(v.size()); i++) {
        double key = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > key) { v[j + 1] = v[j]; j--; }
        v[j + 1] = key;
    }
}

// Compute percentile using linear interpolation.
// idx in [0, n-1] for sorted array.
double percentile(const vector<double>& sorted, double p) {
    int n = static_cast<int>(sorted.size());
    double pos = p * (n - 1);
    int lo = static_cast<int>(pos);
    int hi = lo + 1;
    if (hi >= n) return sorted[n - 1];
    double frac = pos - lo;
    return sorted[lo] * (1.0 - frac) + sorted[hi] * frac;
}

int main() {
    vector<double> vals;
    if (!readValues("values.csv", vals)) return 1;

    if (vals.empty()) {
        cout << "EMPTY\n";
        return 0;
    }

    // Keep original for index tracking, sort a copy.
    vector<double> sorted = vals;
    insertionSort(sorted);

    double Q1  = percentile(sorted, 0.25);
    double Q3  = percentile(sorted, 0.75);
    double IQR = Q3 - Q1;
    double lower = Q1 - 1.5 * IQR;
    double upper = Q3 + 1.5 * IQR;

    // Write outliers.csv
    ofstream fout("outliers.csv");
    if (!fout) { cerr << "Error: cannot open outliers.csv\n"; return 1; }
    fout << "index,value\n";
    fout << fixed << setprecision(6);
    int nOutliers = 0;
    for (int i = 0; i < static_cast<int>(vals.size()); i++) {
        if (vals[i] < lower || vals[i] > upper) {
            fout << i << "," << vals[i] << "\n";
            nOutliers++;
        }
    }

    // Write summary
    ofstream fsum("summary.txt");
    if (!fsum) { cerr << "Error: cannot open summary.txt\n"; return 1; }
    fsum << fixed << setprecision(6);
    fsum << "Q1="         << Q1        << "\n";
    fsum << "Q3="         << Q3        << "\n";
    fsum << "IQR="        << IQR       << "\n";
    fsum << "n_outliers=" << nOutliers << "\n";

    cout << "Done. outliers.csv and summary.txt written.\n";
    return 0;
}
