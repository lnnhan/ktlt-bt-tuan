// ============================================================
// Tuan 6 - Bai 4: Tra loi truy van tong vung
// Doc ma tran, xay prefix 2D, sau do q truy van (x1,y1,x2,y2).
// Tra loi O(1) moi truy van. In 'INVALID' neu chi so sai hoac x1>x2, y1>y2.
// Cong thuc sumRect: pre[x2][y2] - pre[x1-1][y2] - pre[x2][y1-1] + pre[x1-1][y1-1].
// ============================================================
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

typedef vector<vector<long long>> FMatrix;

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
FMatrix buildPre2D(const vector<vector<int>>& a, int m, int n) {
    FMatrix pre(m, vector<long long>(n, 0));
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

// Query sum of rectangle [x1..x2][y1..y2] using prefix array.
// Returns false if indices are invalid.
bool sumRect(const FMatrix& pre, int m, int n,
             int x1, int y1, int x2, int y2, long long& ans) {
    if (x1 > x2 || y1 > y2) return false;
    if (x1 < 0 || y1 < 0 || x2 >= m || y2 >= n) return false;
    ans = pre[x2][y2];
    if (x1 > 0) ans -= pre[x1-1][y2];
    if (y1 > 0) ans -= pre[x2][y1-1];
    if (x1 > 0 && y1 > 0) ans += pre[x1-1][y1-1];
    return true;
}

int main() {
    vector<vector<int>> mat;
    int m, n;
    if (!readMatrix("matrix.txt", mat, m, n)) return 1;

    FMatrix pre = buildPre2D(mat, m, n);

    ifstream fq("queries.txt");
    if (!fq) {
        cerr << "Error: cannot open queries.txt\n";
        return 1;
    }

    int q;
    fq >> q;
    for (int i = 0; i < q; i++) {
        int x1, y1, x2, y2;
        fq >> x1 >> y1 >> x2 >> y2;
        long long ans;
        if (sumRect(pre, m, n, x1, y1, x2, y2, ans))
            cout << ans << "\n";
        else
            cout << "INVALID\n";
    }
    return 0;
}
