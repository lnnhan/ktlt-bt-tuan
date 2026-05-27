// ============================================================
// Tuan 8 - Bai 1: Doc danh sach da thuc tu CSV
// Doc polynomials.csv (id,degree,a0..an). Thieu he so -> 0. degree<0 -> invalid.
// Ghi summary.txt: valid=<n> / invalid=<m> / max_degree=<d>.
// Case bien: degree=0 (hang so); degree > so he so con lai trong dong.
// ============================================================
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

struct Poly {
    string id;
    int deg;
    vector<double> a; // a[0] + a[1]*x + ... + a[deg]*x^deg
};

// Trim leading/trailing whitespace from a string.
string trim(const string& s) {
    size_t start = s.find_first_not_of(" \t\r\n");
    size_t end   = s.find_last_not_of(" \t\r\n");
    if (start == string::npos) return "";
    return s.substr(start, end - start + 1);
}

// Read polynomial list from CSV. Returns true on file open success.
// invalid counts lines with degree < 0.
bool readPolysCSV(const string& path, vector<Poly>& polys, int& invalid) {
    ifstream fin(path);
    if (!fin) {
        cerr << "Error: cannot open file " << path << "\n";
        return false;
    }
    invalid = 0;
    string line;
    // Skip header line
    getline(fin, line);
    while (getline(fin, line)) {
        if (trim(line).empty()) continue;
        istringstream ss(line);
        string token;
        Poly p;

        // id
        if (!getline(ss, token, ',')) continue;
        p.id = trim(token);

        // degree
        if (!getline(ss, token, ',')) { invalid++; continue; }
        p.deg = stoi(trim(token));
        if (p.deg < 0) { invalid++; continue; }

        // coefficients a0..an (missing -> 0)
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
    int invalid = 0;
    if (!readPolysCSV("polynomials.csv", polys, invalid)) return 1;

    int maxDeg = -1;
    for (const Poly& p : polys)
        if (p.deg > maxDeg) maxDeg = p.deg;

    ofstream fsum("summary.txt");
    if (!fsum) { cerr << "Error: cannot open summary.txt\n"; return 1; }
    fsum << "valid="       << polys.size() << "\n";
    fsum << "invalid="     << invalid      << "\n";
    fsum << "max_degree="  << (maxDeg >= 0 ? maxDeg : 0) << "\n";

    cout << "Done. Summary written to summary.txt\n";
    return 0;
}
