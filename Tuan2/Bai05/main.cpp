// ============================================================
// Tuan 2 - Bai 5: Dao ham da thuc
// Doc poly.csv (degree, a0..an). Tinh he so da thuc dao ham P'(x).
// Ghi derivative.csv: degree_deriv, b0, b1, ..., b(n-1).
// Sau do tinh P'(x) tai cac x trong x_values.csv.
// Ham: vector<double> computeDerivCoeffs(vector<double> a).
// Case bien: degree=0 -> P'(x)=0 (hang so).
// ============================================================
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

// Parse comma-separated polynomial: degree, a0, a1, ..., an.
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
    if (!getline(ss, token, ',')) return false;
    degree = stoi(token);
    if (degree < 0) return false;

    a.assign(degree + 1, 0.0);
    for (int i = 0; i <= degree; i++) {
        if (!getline(ss, token, ',')) break;
        if (!token.empty()) a[i] = stod(token);
    }
    return true;
}

// Read x query values (one per line).
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

// Compute derivative coefficients.
// deriv[i] = (i+1) * a[i+1] for i = 0..n-1.
// If degree == 0, returns empty vector (derivative is 0).
vector<double> computeDerivCoeffs(const vector<double>& a) {
    int n = static_cast<int>(a.size()) - 1; // original degree
    if (n == 0) return {}; // constant polynomial
    vector<double> deriv(n);
    for (int i = 0; i < n; i++)
        deriv[i] = static_cast<double>(i + 1) * a[i + 1];
    return deriv;
}

// Evaluate polynomial at x using Horner's method.
double evalHorner(const vector<double>& a, double x) {
    if (a.empty()) return 0.0;
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

    vector<double> deriv = computeDerivCoeffs(a);
    int derivDegree = static_cast<int>(deriv.size()) - 1; // -1 if empty

    // Write derivative coefficients to derivative.csv
    ofstream fderiv("derivative.csv");
    if (!fderiv) {
        cerr << "Error: cannot open derivative.csv for writing\n";
        return 1;
    }
    if (deriv.empty()) {
        fderiv << "0,0.0\n"; // degree 0, coefficient 0
    } else {
        fderiv << derivDegree;
        for (double c : deriv) fderiv << "," << fixed << setprecision(6) << c;
        fderiv << "\n";
    }

    // Evaluate P'(x) at query points
    vector<double> xs;
    if (!readXValues("x_values.csv", xs)) return 1;

    ofstream fout("deriv_output.csv");
    if (!fout) {
        cerr << "Error: cannot open deriv_output.csv for writing\n";
        return 1;
    }
    fout << "x,dP(x)\n";
    fout << fixed << setprecision(6);
    for (double x : xs) {
        double dpx = evalHorner(deriv, x);
        fout << x << "," << dpx << "\n";
    }

    cout << "Done. Derivative written to derivative.csv and deriv_output.csv\n";
    return 0;
}
