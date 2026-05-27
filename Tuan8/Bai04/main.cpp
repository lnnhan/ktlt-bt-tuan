// ============================================================
// Tuan 8 - Bai 4: Cong hai da thuc
// Doc poly_pairs.csv: moi dong la 2 da thuc (id1,deg1,a0..an, id2,deg2,b0..bm).
// Tinh tong 2 da thuc (he so cong theo luy thua tuong ung, bac = max(deg1,deg2)).
// Ghi sum.csv: id, degree_sum, c0..cm.
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
    size_t start = s.find_first_not_of(" \t\r\n");
    size_t end   = s.find_last_not_of(" \t\r\n");
    if (start == string::npos) return "";
    return s.substr(start, end - start + 1);
}

// Parse one polynomial from the remaining tokens in stringstream.
// Returns false if degree < 0 or format error.
bool parsePoly(istringstream& ss, Poly& p) {
    string token;
    if (!getline(ss, token, ',')) return false;
    p.id = trim(token);
    if (!getline(ss, token, ',')) return false;
    p.deg = stoi(trim(token));
    if (p.deg < 0) return false;
    p.a.assign(p.deg + 1, 0.0);
    for (int i = 0; i <= p.deg; i++) {
        if (!getline(ss, token, ',')) break;
        string t = trim(token);
        if (!t.empty()) p.a[i] = stod(t);
    }
    return true;
}

// Add two polynomials. Result degree = max(p.deg, q.deg).
Poly addPoly(const Poly& p, const Poly& q) {
    int maxDeg = (p.deg > q.deg) ? p.deg : q.deg;
    Poly result;
    result.id  = p.id + "+" + q.id;
    result.deg = maxDeg;
    result.a.assign(maxDeg + 1, 0.0);
    for (int i = 0; i <= p.deg; i++) result.a[i] += p.a[i];
    for (int i = 0; i <= q.deg; i++) result.a[i] += q.a[i];
    return result;
}

int main() {
    ifstream fin("poly_pairs.csv");
    if (!fin) { cerr << "Error: cannot open poly_pairs.csv\n"; return 1; }

    ofstream fout("sum.csv");
    if (!fout) { cerr << "Error: cannot open sum.csv\n"; return 1; }
    fout << "id,degree_sum";
    // dynamic header — write data directly
    fout << fixed << setprecision(6);

    string line;
    getline(fin, line); // skip header
    while (getline(fin, line)) {
        if (trim(line).empty()) continue;
        istringstream ss(line);
        Poly p, q;
        if (!parsePoly(ss, p)) continue;
        if (!parsePoly(ss, q)) continue;
        Poly s = addPoly(p, q);
        fout << "\n" << s.id << "," << s.deg;
        for (double v : s.a) fout << "," << v;
    }
    fout << "\n";

    cout << "Done. Sums written to sum.csv\n";
    return 0;
}
