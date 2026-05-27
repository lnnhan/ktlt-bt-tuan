// ============================================================
// Tuan 8 - Bai 3: Thong ke he so da thuc
// Doc polynomials.csv. Voi moi da thuc hop le, tinh max|a_i|, min|a_i|, so he so = 0.
// Ghi stats.csv: id, degree, max_abs, min_abs, zero_count.
// Case bien: degree=0 -> 1 he so; neu tat ca = 0 thi min_abs=0.
// ============================================================
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

struct Poly {
    string id;
    int deg;
    vector<double> a;
};

string trim(const string& s) {
    size_t start = s.find_first_not_of(" \t\r\n");
    size_t end   = s.find_last_not_of(" \t\r\n");
    if (start == string::npos) return "";
    return s.substr(start, end - start + 1);
}

bool readPolysCSV(const string& path, vector<Poly>& polys) {
    ifstream fin(path);
    if (!fin) { cerr << "Error: cannot open " << path << "\n"; return false; }
    string line;
    getline(fin, line); // skip header
    while (getline(fin, line)) {
        if (trim(line).empty()) continue;
        istringstream ss(line);
        string token;
        Poly p;
        if (!getline(ss, token, ',')) continue;
        p.id = trim(token);
        if (!getline(ss, token, ',')) continue;
        p.deg = stoi(trim(token));
        if (p.deg < 0) continue; // skip invalid
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

int main() {
    vector<Poly> polys;
    if (!readPolysCSV("polynomials.csv", polys)) return 1;

    ofstream fout("stats.csv");
    if (!fout) { cerr << "Error: cannot open stats.csv\n"; return 1; }
    fout << "id,degree,max_abs,min_abs,zero_count\n";
    fout << fixed << setprecision(6);

    for (const Poly& p : polys) {
        double maxAbs = fabs(p.a[0]);
        double minAbs = fabs(p.a[0]);
        int zeroCount = 0;

        for (double v : p.a) {
            double av = fabs(v);
            if (av > maxAbs) maxAbs = av;
            if (av < minAbs) minAbs = av;
            if (v == 0.0) zeroCount++;
        }
        fout << p.id << "," << p.deg << "," << maxAbs << ","
             << minAbs << "," << zeroCount << "\n";
    }

    cout << "Done. Stats written to stats.csv\n";
    return 0;
}
