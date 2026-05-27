// ============================================================
// Tuan 8 - Bai 9: Da thuc Lagrange noi suy
// Doc points.csv: n diem (xi, yi) phan biet (n <= 8).
// Tinh da thuc noi suy Lagrange.
// Danh gia tai cac diem trong query.csv. Ghi ket qua: x_q, P(x_q).
// Ghi chu: khong can tinh he so da thuc - chi can P(x_q) = sum yi * Li(x_q).
// ============================================================
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct Point { double x, y; };

string trim(const string& s) {
    size_t start = s.find_first_not_of(" \t\r\n");
    size_t end   = s.find_last_not_of(" \t\r\n");
    if (start == string::npos) return "";
    return s.substr(start, end - start + 1);
}

// Read (x, y) points from CSV (no header, one point per line).
bool readPoints(const string& path, vector<Point>& pts) {
    ifstream fin(path);
    if (!fin) { cerr << "Error: cannot open " << path << "\n"; return false; }
    string line;
    while (getline(fin, line)) {
        if (trim(line).empty()) continue;
        istringstream ss(line);
        string tx, ty;
        if (!getline(ss, tx, ',')) continue;
        if (!getline(ss, ty)) continue;
        pts.push_back({stod(trim(tx)), stod(trim(ty))});
    }
    return true;
}

bool readQueries(const string& path, vector<double>& qs) {
    ifstream fin(path);
    if (!fin) { cerr << "Error: cannot open " << path << "\n"; return false; }
    double x;
    while (fin >> x) qs.push_back(x);
    return true;
}

// Evaluate Lagrange interpolation at xq.
// P(xq) = sum over i: yi * Li(xq)
// Li(xq) = product over j!=i: (xq - xj) / (xi - xj)
double lagrange(const vector<Point>& pts, double xq) {
    int n = static_cast<int>(pts.size());
    double result = 0.0;
    for (int i = 0; i < n; i++) {
        double Li = 1.0;
        for (int j = 0; j < n; j++) {
            if (j == i) continue;
            Li *= (xq - pts[j].x) / (pts[i].x - pts[j].x);
        }
        result += pts[i].y * Li;
    }
    return result;
}

int main() {
    vector<Point> pts;
    if (!readPoints("points.csv", pts)) return 1;

    vector<double> qs;
    if (!readQueries("query.csv", qs)) return 1;

    ofstream fout("lagrange_out.csv");
    if (!fout) { cerr << "Error: cannot open lagrange_out.csv\n"; return 1; }
    fout << "x_q,P(x_q)\n";
    fout << fixed << setprecision(6);
    for (double xq : qs)
        fout << xq << "," << lagrange(pts, xq) << "\n";

    cout << "Done. Written to lagrange_out.csv\n";
    return 0;
}
