// ============================================================
// Tuan 6 - Bai 3: Xay dung prefix sum 2D
// Doc ma tran m×n. Xay dung mang pre2D.
// Ghi pre2D ra file: moi dong la 'i j pre[i][j]'.
// Cong thuc: pre[i][j] = a[i][j] + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1].
// Case bien: 1×1 -> pre[0][0]=a[0][0].
// ============================================================
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

typedef vector<vector<long long>> FMatrix;

// Read m×n integer matrix. First line: "m n".
bool readMatrix(const string& path, vector<vector<int>>& mat) {
    ifstream fin(path);
    if (!fin) {
        cerr << "Error: cannot open file " << path << "\n";
        return false;
    }
    int m, n;
    fin >> m >> n;
    mat.assign(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            fin >> mat[i][j];
    return true;
}

// Build 2D prefix sum array.
// pre[i][j] = sum of submatrix [0..i][0..j].
FMatrix buildPre2D(const vector<vector<int>>& a) {
    int m = static_cast<int>(a.size());
    int n = m > 0 ? static_cast<int>(a[0].size()) : 0;
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

int main() {
    vector<vector<int>> mat;
    if (!readMatrix("matrix.txt", mat)) return 1;

    FMatrix pre = buildPre2D(mat);

    ofstream fout("pre2d.txt");
    if (!fout) {
        cerr << "Error: cannot open pre2d.txt\n";
        return 1;
    }
    for (int i = 0; i < static_cast<int>(pre.size()); i++)
        for (int j = 0; j < static_cast<int>(pre[i].size()); j++)
            fout << i << " " << j << " " << pre[i][j] << "\n";

    cout << "Done. Written to pre2d.txt\n";
    return 0;
}
