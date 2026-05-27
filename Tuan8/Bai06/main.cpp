// ============================================================
// Tuan 8 - Bai 6: Dao ham va danh gia da thuc
// Doc polynomials.csv va x_values.csv.
// Voi moi da thuc hop le, tinh P'(x) tai moi x.
// Ghi deriv_report.csv: id, x, P(x), dP(x).
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

// Compute derivative coefficients: deriv[i] = (i+1)*a[i+1].
vector<double> computeDerivCoeffs(const vector<double>& a) {
    int n = static_cast<int>(a.size()) - 1;
    if (n == 0) return {};
    vector<double> deriv(n);
    for (int i = 0; i < n; i++) deriv[i] = (i + 1) * a[i + 1];
    return deriv;
}

int main() {
    vector<Poly> polys;
    if (!readPolysCSV("polynomials.csv", polys)) return 1;
    vector<double> xs;
    if (!readXValues("x_values.csv", xs)) return 1;

    ofstream fout("deriv_report.csv");
    if (!fout) { cerr << "Error: cannot open deriv_report.csv\n"; return 1; }
    fout << "id,x,P(x),dP(x)\n";
    fout << fixed << setprecision(6);

    for (const Poly& p : polys) {
        vector<double> deriv = computeDerivCoeffs(p.a);
        for (double x : xs) {
            double px  = evalHorner(p.a, x);
            double dpx = evalHorner(deriv, x);
            fout << p.id << "," << x << "," << px << "," << dpx << "\n";
        }
    }

    cout << "Done. Written to deriv_report.csv\n";
    return 0;
}
