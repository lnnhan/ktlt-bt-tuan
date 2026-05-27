// ============================================================
// Tuan 6 - Bai 5: Ma tran duong cheo
// Doc ma tran vuong n×n. Tinh tong duong cheo chinh (i=j) va duong cheo phu (i+j=n-1).
// Kiem tra ma tran duong cheo: tat ca phan tu ngoai duong cheo chinh bang 0.
// Output: main_diag_sum=<v> / anti_diag_sum=<v> / is_diagonal=<0/1>.
// Case bien: n=1 -> duong cheo chinh = duong cheo phu = a[0][0]; is_diagonal=1.
// ============================================================
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// Read square matrix n×n. File first line: "n n" or just "n".
bool readSquareMatrix(const string& path, vector<vector<int>>& mat, int& n) {
    ifstream fin(path);
    if (!fin) {
        cerr << "Error: cannot open file " << path << "\n";
        return false;
    }
    int r, c;
    fin >> r >> c;
    n = r;
    mat.assign(r, vector<int>(c, 0));
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            fin >> mat[i][j];
    return true;
}

int main() {
    vector<vector<int>> mat;
    int n;
    if (!readSquareMatrix("matrix.txt", mat, n)) return 1;

    long long mainSum = 0, antiSum = 0;
    bool isDiagonal = true;

    for (int i = 0; i < n; i++) {
        mainSum += mat[i][i];
        antiSum += mat[i][n - 1 - i];
    }

    // Check all off-diagonal elements are 0
    for (int i = 0; i < n && isDiagonal; i++)
        for (int j = 0; j < n && isDiagonal; j++)
            if (i != j && mat[i][j] != 0) isDiagonal = false;

    cout << "main_diag_sum=" << mainSum << " / anti_diag_sum=" << antiSum
         << " / is_diagonal=" << (isDiagonal ? 1 : 0) << "\n";
    return 0;
}
