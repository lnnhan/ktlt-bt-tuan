// ============================================================
// Tuan 6 - Bai 7: Vung con tong lon nhat (brute force)
// Doc ma tran m×n (m,n <= 50). Tim vung chu nhat (x1,y1,x2,y2) co tong lon nhat.
// Dung prefix 2D de tinh tong vung O(1); duyet tat ca O(m^2*n^2).
// Output: max_sum, x1, y1, x2, y2.
// ============================================================
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

typedef vector<vector<long long>> Matrix;

// Read m×n integer matrix. First line: "m n".
bool readMatrix(const string& path, vector<vector<int>>& mat, int& m, int& n) {
    ifstream fin(path);
    if (!fin) {
        cerr << "Error: cannot open file " << path << "\n";
        return false;
    }
    fin >> m >> n;
    mat.assign(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            fin >> mat[i][j];
    return true;
}

// Build 2D prefix sum.
Matrix buildPre2D(const vector<vector<int>>& a, int m, int n) {
    Matrix pre(m, vector<long long>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            pre[i][j] = a[i][j];
            if (i > 0) pre[i][j] += pre[i-1][j];
            if (j > 0) pre[i][j] += pre[i][j-1];
            if (i > 0 && j > 0) pre[i][j] -= pre[i-1][j-1];
        }
    }
    return pre;
}

// Query sum of rectangle [x1..x2][y1..y2].
long long sumRect(const Matrix& pre, int x1, int y1, int x2, int y2) {
    long long ans = pre[x2][y2];
    if (x1 > 0) ans -= pre[x1-1][y2];
    if (y1 > 0) ans -= pre[x2][y1-1];
    if (x1 > 0 && y1 > 0) ans += pre[x1-1][y1-1];
    return ans;
}

int main() {
    vector<vector<int>> mat;
    int m, n;
    if (!readMatrix("matrix.txt", mat, m, n)) return 1;

    if (m == 0 || n == 0) {
        cout << "EMPTY\n";
        return 0;
    }

    Matrix pre = buildPre2D(mat, m, n);

    long long bestSum = 0;
    int bx1 = 0, by1 = 0, bx2 = 0, by2 = 0;
    bool first = true;

    for (int x1 = 0; x1 < m; x1++)
      for (int y1 = 0; y1 < n; y1++)
        for (int x2 = x1; x2 < m; x2++)
          for (int y2 = y1; y2 < n; y2++) {
              long long s = sumRect(pre, x1, y1, x2, y2);
              if (first || s > bestSum) {
                  bestSum = s;
                  bx1 = x1; by1 = y1; bx2 = x2; by2 = y2;
                  first = false;
              }
          }

    cout << "max_sum=" << bestSum << " / x1=" << bx1 << " / y1=" << by1
         << " / x2=" << bx2 << " / y2=" << by2 << "\n";
    return 0;
}
