// ============================================================
// Tuan 8 - Bai 7: Tim nghiem nguyen cua da thuc
// Doc polynomials.csv. Voi moi da thuc he so nguyen,
// tim tat ca nghiem nguyen x trong [-50, 50].
// Ghi roots.csv: id, root (moi nghiem 1 dong). Neu khong co -> 'id,NONE'.
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
        if (p.deg < 0) continue;
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

// Evaluate polynomial at integer x using Horner (exact with int arithmetic).
long long evalInt(const vector<double>& a, int x) {
    int n = static_cast<int>(a.size()) - 1;
    long long res = static_cast<long long>(a[n]);
    for (int i = n - 1; i >= 0; i--)
        res = res * x + static_cast<long long>(a[i]);
    return res;
}

int main() {
    vector<Poly> polys;
    if (!readPolysCSV("polynomials.csv", polys)) return 1;

    ofstream fout("roots.csv");
    if (!fout) { cerr << "Error: cannot open roots.csv\n"; return 1; }
    fout << "id,root\n";

    for (const Poly& p : polys) {
        bool found = false;
        for (int x = -50; x <= 50; x++) {
            if (evalInt(p.a, x) == 0) {
                fout << p.id << "," << x << "\n";
                found = true;
            }
        }
        if (!found) fout << p.id << ",NONE\n";
    }

    cout << "Done. Roots written to roots.csv\n";
    return 0;
}
