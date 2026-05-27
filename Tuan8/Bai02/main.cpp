// ============================================================
// Tuan 8 - Bai 2: Tinh P(x) va ghi report
// Doc polynomials.csv va x_values.csv.
// Tinh P(x) bang Horner cho moi da thuc hop le.
// Ghi report.csv: id, x, P(x) (setprecision(6)).
// Cuoi: valid_count, invalid_count.
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

// Read polynomial CSV (id, degree, a0..an). Returns invalid count.
bool readPolysCSV(const string& path, vector<Poly>& polys, int& invalid) {
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
bool readXValues(const string& path, vector<double>& xs) {
    ifstream fin(path);
    if (!fin) { cerr << "Error: cannot open " << path << "\n"; return false; }
    double x;
    while (fin >> x) xs.push_back(x);
    return true;
}

// Evaluate polynomial using Horner's method.
double evalHorner(const vector<double>& a, double x) {
    if (a.empty()) return 0.0;
    int n = static_cast<int>(a.size()) - 1;
    double res = a[n];
    for (int i = n - 1; i >= 0; i--) res = res * x + a[i];
    return res;
}

int main() {
    vector<Poly> polys;
    int invalid = 0;
    if (!readPolysCSV("polynomials.csv", polys, invalid)) return 1;

    vector<double> xs;
    if (!readXValues("x_values.csv", xs)) return 1;

    ofstream fout("report.csv");
    if (!fout) { cerr << "Error: cannot open report.csv\n"; return 1; }
    fout << "id,x,P(x)\n";
    fout << fixed << setprecision(6);
    for (const Poly& p : polys)
        for (double x : xs)
            fout << p.id << "," << x << "," << evalHorner(p.a, x) << "\n";

    fout << "---\n";
    fout << "valid_count=" << polys.size() << "\n";
    fout << "invalid_count=" << invalid << "\n";

    cout << "Done. Results written to report.csv\n";
    return 0;
}
