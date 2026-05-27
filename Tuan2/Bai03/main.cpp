// ============================================================
// Tuan 2 - Bai 3: Tinh da thuc tai nhieu diem (Horner)
// Doc poly.csv: 1 dong chua degree, a0, a1, ..., an.
// Doc x_values.csv: moi dong 1 gia tri x.
// Ghi output.csv: x, P(x) (setprecision(6)).
// Ham: double evalHorner(vector<double> a, double x).
// Case bien: degree=0 (hang so); x_values rong -> output chi co header.
// ============================================================
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

// Parse comma-separated polynomial: degree, a0, a1, ..., an.
// Returns false if file cannot be opened or format is invalid.
bool readPoly(const string& path, int& degree, vector<double>& a) {
    ifstream fin(path);
    if (!fin) {
        cerr << "Error: cannot open file " << path << "\n";
        return false;
    }
    string line;
    if (!getline(fin, line)) return false;

    istringstream ss(line);
    string token;

    // First token is degree
    if (!getline(ss, token, ',')) return false;
    degree = stoi(token);
    if (degree < 0) return false;

    // Remaining tokens are coefficients a0..an
    a.assign(degree + 1, 0.0);
    for (int i = 0; i <= degree; i++) {
        if (!getline(ss, token, ',')) break; // missing => 0
        if (!token.empty()) a[i] = stod(token);
    }
    return true;
}

// Read x query values (one per line) from file.
bool readXValues(const string& path, vector<double>& xs) {
    ifstream fin(path);
    if (!fin) {
        cerr << "Error: cannot open file " << path << "\n";
        return false;
    }
    double x;
    while (fin >> x) xs.push_back(x);
    return true;
}

// Evaluate polynomial at x using Horner's method.
// a[0] + a[1]*x + ... + a[n]*x^n
// Horner: res = a[n]; for i=n-1..0: res = res*x + a[i]
double evalHorner(const vector<double>& a, double x) {
    int n = static_cast<int>(a.size()) - 1;
    double res = a[n];
    for (int i = n - 1; i >= 0; i--)
        res = res * x + a[i];
    return res;
}

int main() {
    int degree;
    vector<double> a;
    if (!readPoly("poly.csv", degree, a)) return 1;

    vector<double> xs;
    if (!readXValues("x_values.csv", xs)) return 1;

    ofstream fout("output.csv");
    if (!fout) {
        cerr << "Error: cannot open output.csv for writing\n";
        return 1;
    }

    fout << "x,P(x)\n";
    fout << fixed << setprecision(6);
    for (double x : xs) {
        double px = evalHorner(a, x);
        fout << x << "," << px << "\n";
    }

    cout << "Done. Results written to output.csv\n";
    return 0;
}
