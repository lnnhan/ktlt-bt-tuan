// ============================================================
// Tuan 10 - Bai 10: Mini-project - Huong A (KHDL)
// Doc dataset nhieu cot -> cleaning -> normalize Z-score -> xuat report + histogram ASCII.
// File: data.csv (id, col1, col2, ..., colN - co the co missing).
// Ghi: cleaned.csv (da impute bang mean), normalized.csv (Z-score),
//      histogram.txt (ASCII histogram cho cot dau tien), summary.txt.
// Bao gom >= 4 module ham.
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

// --- Module 1: IO ---

struct Dataset {
    vector<string> header;        // column names (col 0 = id)
    vector<string> ids;           // row ids
    vector<vector<double>> vals;  // vals[row][col] (col starts at 0 = first numeric col)
    vector<vector<bool>> missing; // missing[row][col]
    int nRows, nCols;
};

// Read CSV dataset.
Dataset readDataset(const string& path) {
    Dataset ds;
    ds.nRows = 0; ds.nCols = 0;
    ifstream fin(path);
    if (!fin) { cerr << "Error: cannot open " << path << "\n"; return ds; }
    string line;
    if (!getline(fin, line)) return ds;
    istringstream hss(line);
    string h;
    while (getline(hss, h, ',')) ds.header.push_back(trim(h));
    ds.nCols = static_cast<int>(ds.header.size()) - 1; // exclude id column

    while (getline(fin, line)) {
        if (trim(line).empty()) continue;
        istringstream ss(line);
        string cell;
        vector<string> row;
        while (getline(ss, cell, ',')) row.push_back(trim(cell));

        string id = row.empty() ? "" : row[0];
        ds.ids.push_back(id);

        vector<double> rowVals(ds.nCols, 0.0);
        vector<bool> rowMiss(ds.nCols, false);
        for (int c = 0; c < ds.nCols; c++) {
            int colIdx = c + 1;
            if (colIdx >= static_cast<int>(row.size()) || isMissing(row[colIdx])) {
                rowMiss[c] = true;
            } else {
                rowVals[c] = stod(row[colIdx]);
            }
        }
        ds.vals.push_back(rowVals);
        ds.missing.push_back(rowMiss);
        ds.nRows++;
    }
    return ds;
}

// --- Module 2: Cleaning (impute missing with column mean) ---

// Compute column mean ignoring missing.
double colMean(const Dataset& ds, int col) {
    double sum = 0; int cnt = 0;
    for (int r = 0; r < ds.nRows; r++)
        if (!ds.missing[r][col]) { sum += ds.vals[r][col]; cnt++; }
    return (cnt > 0) ? sum / cnt : 0.0;
}

// Impute missing values with column mean. Returns cleaned dataset.
Dataset cleanDataset(Dataset ds) {
    for (int c = 0; c < ds.nCols; c++) {
        double mean = colMean(ds, c);
        for (int r = 0; r < ds.nRows; r++)
            if (ds.missing[r][c]) { ds.vals[r][c] = mean; ds.missing[r][c] = false; }
    }
    return ds;
}

// --- Module 3: Z-score normalization ---

// Compute column std (population) after cleaning.
double colStd(const Dataset& ds, int col, double mean) {
    long double acc = 0;
    for (int r = 0; r < ds.nRows; r++) {
        long double d = ds.vals[r][col] - mean;
        acc += d * d;
    }
    return (ds.nRows > 0) ? static_cast<double>(sqrtl(acc / ds.nRows)) : 0.0;
}

// Normalize dataset to Z-scores. Returns normalized values.
vector<vector<double>> zscoreNormalize(const Dataset& cleaned,
                                        vector<double>& means, vector<double>& stds) {
    means.resize(cleaned.nCols);
    stds.resize(cleaned.nCols);
    vector<vector<double>> normed(cleaned.nRows, vector<double>(cleaned.nCols, 0.0));
    for (int c = 0; c < cleaned.nCols; c++) {
        means[c] = colMean(cleaned, c);
        stds[c]  = colStd(cleaned, c, means[c]);
        for (int r = 0; r < cleaned.nRows; r++) {
            normed[r][c] = (stds[c] == 0.0) ? 0.0
                          : (cleaned.vals[r][c] - means[c]) / stds[c];
        }
    }
    return normed;
}

// --- Module 4: Write outputs ---

void writeCleaned(const string& path, const Dataset& ds) {
    ofstream fout(path);
    if (!fout) { cerr << "Error: cannot open " << path << "\n"; return; }
    for (int i = 0; i < static_cast<int>(ds.header.size()); i++) {
        if (i > 0) fout << ",";
        fout << ds.header[i];
    }
    fout << "\n";
    fout << fixed << setprecision(6);
    for (int r = 0; r < ds.nRows; r++) {
        fout << ds.ids[r];
        for (int c = 0; c < ds.nCols; c++) fout << "," << ds.vals[r][c];
        fout << "\n";
    }
}

void writeNormalized(const string& path, const Dataset& ds,
                     const vector<vector<double>>& normed) {
    ofstream fout(path);
    if (!fout) { cerr << "Error: cannot open " << path << "\n"; return; }
    for (int i = 0; i < static_cast<int>(ds.header.size()); i++) {
        if (i > 0) fout << ",";
        fout << ds.header[i];
    }
    fout << "\n";
    fout << fixed << setprecision(6);
    for (int r = 0; r < ds.nRows; r++) {
        fout << ds.ids[r];
        for (int c = 0; c < ds.nCols; c++) fout << "," << normed[r][c];
        fout << "\n";
    }
}

// ASCII histogram for column 0 (first numeric column).
void writeHistogram(const string& path, const Dataset& ds, int bins) {
    if (ds.nRows == 0 || ds.nCols == 0) return;
    double mn = ds.vals[0][0], mx = ds.vals[0][0];
    for (int r = 0; r < ds.nRows; r++) {
        if (ds.vals[r][0] < mn) mn = ds.vals[r][0];
        if (ds.vals[r][0] > mx) mx = ds.vals[r][0];
    }
    double range = mx - mn;
    vector<int> counts(bins, 0);
    for (int r = 0; r < ds.nRows; r++) {
        int idx = (range == 0) ? 0 : static_cast<int>((ds.vals[r][0] - mn) / range * bins);
        if (idx >= bins) idx = bins - 1;
        counts[idx]++;
    }

    ofstream fout(path);
    if (!fout) return;
    fout << "ASCII Histogram for column: " << ds.header[1] << "\n";
    fout << fixed << setprecision(2);
    double bw = (range == 0) ? 1.0 : range / bins;
    for (int i = 0; i < bins; i++) {
        double lo = mn + i * bw;
        double hi = mn + (i + 1) * bw;
        fout << "[" << lo << "," << hi << "): ";
        for (int j = 0; j < counts[i]; j++) fout << "*";
        fout << " (" << counts[i] << ")\n";
    }
}

void writeSummary(const string& path, const Dataset& cleaned,
                  const vector<double>& means, const vector<double>& stds, int nMissing) {
    ofstream fout(path);
    if (!fout) return;
    fout << "rows=" << cleaned.nRows << "\n";
    fout << "cols=" << cleaned.nCols << "\n";
    fout << "total_missing_imputed=" << nMissing << "\n";
    fout << fixed << setprecision(6);
    for (int c = 0; c < cleaned.nCols; c++) {
        fout << "col=" << cleaned.header[c + 1]
             << " mean=" << means[c] << " std=" << stds[c] << "\n";
    }
}

int main() {
    Dataset ds = readDataset("data.csv");
    if (ds.nRows == 0) { cerr << "No data loaded.\n"; return 1; }

    // Count missing before cleaning
    int nMissing = 0;
    for (int r = 0; r < ds.nRows; r++)
        for (int c = 0; c < ds.nCols; c++)
            if (ds.missing[r][c]) nMissing++;

    Dataset cleaned = cleanDataset(ds);
    writeCleaned("cleaned.csv", cleaned);

    vector<double> means, stds;
    vector<vector<double>> normed = zscoreNormalize(cleaned, means, stds);
    writeNormalized("normalized.csv", cleaned, normed);

    writeHistogram("histogram.txt", cleaned, 10);
    writeSummary("summary.txt", cleaned, means, stds, nMissing);

    cout << "Done. cleaned.csv, normalized.csv, histogram.txt, summary.txt written.\n";
    return 0;
}
