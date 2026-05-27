// ============================================================
// Tuan 10 - Bai 2: Fraction List tong hop
// Doc fractions.csv. Loc invalid, normalize, sort tang, tinh tong.
// Ghi fraction_out.csv: valid_count, invalid_count, sum; sau do danh sach da sort.
// Ham: readFractions(), filterAndNormalize(), sortFractions(), writeFractionReport().
// Case bien: khong co phan so hop le -> sum=0/1.
// ============================================================
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

struct Frac {
    long long num, den;
    bool valid;
};

long long gcd(long long a, long long b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    while (b) { long long t = b; b = a % b; a = t; }
    return a;
}

Frac normalize(Frac f) {
    if (!f.valid) return f;
    if (f.den == 0) { f.valid = false; return f; }
    if (f.den < 0) { f.num = -f.num; f.den = -f.den; }
    if (f.num == 0) { f.den = 1; return f; }
    long long g = gcd(f.num < 0 ? -f.num : f.num, f.den);
    f.num /= g; f.den /= g;
    return f;
}

Frac addFrac(Frac a, Frac b) {
    return normalize({a.num * b.den + b.num * a.den, a.den * b.den, true});
}

string trim(const string& s) {
    size_t st = s.find_first_not_of(" \t\r\n");
    size_t en = s.find_last_not_of(" \t\r\n");
    if (st == string::npos) return "";
    return s.substr(st, en - st + 1);
}

// Read fractions from CSV (one per line, format "num/den" or just "num").
vector<Frac> readFractions(const string& path) {
    vector<Frac> result;
    ifstream fin(path);
    if (!fin) { cerr << "Error: cannot open " << path << "\n"; return result; }
    string line;
    getline(fin, line); // skip header if present (optional)
    // Try to detect if it was a header
    string t = trim(line);
    // If it looks like "num/den" or a number, reparse it
    bool isNumeric = (!t.empty() && (t[0] == '-' || (t[0] >= '0' && t[0] <= '9')));
    if (isNumeric) {
        // Process first line as data
        Frac f;
        f.valid = true;
        size_t pos = t.find('/');
        if (pos == string::npos) {
            try { f.num = stoll(t); f.den = 1; }
            catch (...) { f.valid = false; }
        } else {
            try {
                f.num = stoll(t.substr(0, pos));
                f.den = stoll(t.substr(pos + 1));
            } catch (...) { f.valid = false; }
        }
        if (f.den == 0) f.valid = false;
        result.push_back(f);
    }
    while (getline(fin, line)) {
        t = trim(line);
        if (t.empty()) continue;
        Frac f;
        f.valid = true;
        size_t pos = t.find('/');
        if (pos == string::npos) {
            try { f.num = stoll(t); f.den = 1; }
            catch (...) { f.valid = false; }
        } else {
            try {
                f.num = stoll(t.substr(0, pos));
                f.den = stoll(t.substr(pos + 1));
            } catch (...) { f.valid = false; }
        }
        if (f.den == 0) f.valid = false;
        result.push_back(f);
    }
    return result;
}

// Filter invalid fractions, normalize valid ones.
void filterAndNormalize(const vector<Frac>& in,
                        vector<Frac>& valid, int& invalidCount) {
    invalidCount = 0;
    for (Frac f : in) {
        if (!f.valid) { invalidCount++; continue; }
        Frac n = normalize(f);
        if (!n.valid) { invalidCount++; continue; }
        valid.push_back(n);
    }
}

// Simple insertion sort by value (num/den) ascending.
void sortFractions(vector<Frac>& v) {
    for (int i = 1; i < static_cast<int>(v.size()); i++) {
        Frac key = v[i];
        int j = i - 1;
        // Compare a/b < c/d using cross-multiplication
        while (j >= 0 && v[j].num * key.den > key.num * v[j].den) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = key;
    }
}

// Write fraction report CSV.
void writeFractionReport(const string& path, int validCount, int invalidCount,
                         const Frac& sum, const vector<Frac>& sorted) {
    ofstream fout(path);
    if (!fout) { cerr << "Error: cannot open " << path << "\n"; return; }
    fout << "valid_count=" << validCount << "\n";
    fout << "invalid_count=" << invalidCount << "\n";
    fout << "sum=" << sum.num << "/" << sum.den << "\n";
    fout << "---\n";
    for (const Frac& f : sorted)
        fout << f.num << "/" << f.den << "\n";
}

int main() {
    vector<Frac> raw = readFractions("fractions.csv");

    vector<Frac> valid;
    int invalidCount = 0;
    filterAndNormalize(raw, valid, invalidCount);

    sortFractions(valid);

    Frac sum = {0, 1, true};
    for (const Frac& f : valid) sum = addFrac(sum, f);

    writeFractionReport("fraction_out.csv", static_cast<int>(valid.size()),
                        invalidCount, sum, valid);

    cout << "Done. Written to fraction_out.csv\n";
    return 0;
}
