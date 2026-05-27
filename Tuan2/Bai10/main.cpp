// ============================================================
// Tuan 2 - Bai 10: Noi suy tuyen tinh
// Doc points.csv: cac diem (xi, yi) da sap xep tang theo x.
// Doc queries.csv: cac x can noi suy.
// Voi moi x_q: neu trong [x_min, x_max] -> noi suy; ngoai -> OUT_OF_RANGE.
// Ghi interpolated.csv: x_q, y_interp hoac OUT_OF_RANGE.
// ============================================================
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct Point {
    double x, y;
};

// Read comma-separated (x,y) points from file (one per line, no header).
bool readPoints(const string& path, vector<Point>& pts) {
    ifstream fin(path);
    if (!fin) {
        cerr << "Error: cannot open file " << path << "\n";
        return false;
    }
    string line;
    while (getline(fin, line)) {
        if (line.empty()) continue;
        istringstream ss(line);
        string tx, ty;
        if (!getline(ss, tx, ',')) continue;
        if (!getline(ss, ty, ',')) continue;
        pts.push_back({stod(tx), stod(ty)});
    }
    return true;
}

// Read query x values (one per line).
bool readQueries(const string& path, vector<double>& qs) {
    ifstream fin(path);
    if (!fin) {
        cerr << "Error: cannot open file " << path << "\n";
        return false;
    }
    double x;
    while (fin >> x) qs.push_back(x);
    return true;
}

// Find the index of the left-side control point for interpolation.
// Assumes pts is sorted by x and xq is in [pts[0].x, pts[n-1].x].
// Returns index i such that pts[i].x <= xq < pts[i+1].x.
int findSegment(const vector<Point>& pts, double xq) {
    // Linear scan (pts is small in most HW problems)
    int lo = 0;
    int hi = static_cast<int>(pts.size()) - 2;
    for (int i = hi; i >= lo; i--) {
        if (pts[i].x <= xq) return i;
    }
    return 0;
}

// Linear interpolation between two points.
double linearInterp(const Point& p1, const Point& p2, double xq) {
    // y = y1 + (y2 - y1) * (xq - x1) / (x2 - x1)
    return p1.y + (p2.y - p1.y) * (xq - p1.x) / (p2.x - p1.x);
}

int main() {
    vector<Point> pts;
    if (!readPoints("points.csv", pts)) return 1;

    vector<double> qs;
    if (!readQueries("queries.csv", qs)) return 1;

    ofstream fout("interpolated.csv");
    if (!fout) {
        cerr << "Error: cannot open interpolated.csv\n";
        return 1;
    }
    fout << "x_q,y_interp\n";
    fout << fixed << setprecision(6);

    if (pts.empty()) {
        for (double xq : qs) fout << xq << ",OUT_OF_RANGE\n";
        return 0;
    }

    double xMin = pts.front().x;
    double xMax = pts.back().x;

    for (double xq : qs) {
        if (xq < xMin || xq > xMax) {
            fout << xq << ",OUT_OF_RANGE\n";
        } else {
            int idx = findSegment(pts, xq);
            double yq;
            // Exact match at last point
            if (idx + 1 >= static_cast<int>(pts.size())) {
                yq = pts.back().y;
            } else {
                yq = linearInterp(pts[idx], pts[idx + 1], xq);
            }
            fout << xq << "," << yq << "\n";
        }
    }

    cout << "Done. Results written to interpolated.csv\n";
    return 0;
}
