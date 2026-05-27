// ============================================================
// Tuan 10 - Bai 3: Polynomial records + evaluate
// Doc polynomials.csv va x_values.csv. Tinh P(x) bang Horner.
// Ghi report.csv: id,x,P(x). Cuoi: valid/invalid count.
// Module io: readPoly, readX, writeReport. Module processing: evalHorner.
// ============================================================
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct Poly {
    string id;
    int deg;
    vector<double> a;
};

string trim(const string& s) {
    size_t st = s.find_first_not_of(" \t\r\n");
    size_t en = s.find_last_not_of(" \t\r\n");
    if (st == string::npos) return "";
    return s.substr(st, en - st + 1);
}

// --- IO module ---

// Read polynomials from CSV (id, degree, a0..an).
bool readPoly(const string& path, vector<Poly>& polys, int& invalid) {
    ifstream fin(path);
    if (!fin) { cerr << "Error: cannot open " << path << "\n"; return false; }
    invalid = 0;
    string line;
    getline(fin, line); // skip header
    while (getline(fin, line)) {
        if (trim(line).empty()) continue;
        istringstream ss(line);
        string token;
        Poly p;
        if (!getline(ss, token, ',')) continue;
        p.id = trim(token);
        if (!getline(ss, token, ',')) { invalid++; continue; }
        p.deg = stoi(trim(token));
        if (p.deg < 0) { invalid++; continue; }
        p.a.assign(p.deg + 1, 0.0);
        for (int i = 0; i <= p.deg; i++) {
            if (!getline(ss, token, ',')) break;
            string t = trim(token);
            if (!t.empty()) p.a[i] = stod(t);
        }
        polys.push_back(p);
    }
    return true;
}

// Read x values (one per line).
bool readX(const string& path, vector<double>& xs) {
    ifstream fin(path);
    if (!fin) { cerr << "Error: cannot open " << path << "\n"; return false; }
    double x;
    while (fin >> x) xs.push_back(x);
    return true;
}

// Write report CSV and separator + counts.
void writeReport(const string& path, const vector<Poly>& polys,
                 const vector<double>& xs, int invalid) {
    ofstream fout(path);
    if (!fout) { cerr << "Error: cannot open " << path << "\n"; return; }
    fout << "id,x,P(x)\n";
    fout << fixed << setprecision(6);

    // --- Processing module ---
    auto evalHorner = [](const vector<double>& a, double x) -> double {
        if (a.empty()) return 0.0;
        int n = static_cast<int>(a.size()) - 1;
        double res = a[n];
        for (int i = n - 1; i >= 0; i--) res = res * x + a[i];
        return res;
    };

    for (const Poly& p : polys)
        for (double x : xs)
            fout << p.id << "," << x << "," << evalHorner(p.a, x) << "\n";

    fout << "---\n";
    fout << "valid_count="   << polys.size() << "\n";
    fout << "invalid_count=" << invalid      << "\n";
}

int main() {
    vector<Poly> polys;
    int invalid = 0;
    if (!readPoly("polynomials.csv", polys, invalid)) return 1;

    vector<double> xs;
    if (!readX("x_values.csv", xs)) return 1;

    writeReport("report.csv", polys, xs, invalid);

    cout << "Done. Written to report.csv\n";
    return 0;
}
