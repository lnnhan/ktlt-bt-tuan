// ============================================================
// Tuan 6 - Bai 2: Kiem tra ma tran doi xung
// Doc ma tran vuong n×n. Kiem tra co doi xung khong (a[i][j]=a[j][i]).
// Output: is_symmetric=1 hoac 0. Neu khong vuong: is_symmetric=0.
// Case bien: n=1 -> luon doi xung; n=0 -> doi xung (ma tran rong).
// ============================================================
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// Read matrix from file. First line: "m n", then values.
bool readMatrix(const string& path, vector<vector<int>>& mat, int& rows, int& cols) {
    ifstream fin(path);
    if (!fin) {
        cerr << "Error: cannot open file " << path << "\n";
        return false;
    }
    fin >> rows >> cols;
    mat.assign(rows, vector<int>(cols, 0));
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            fin >> mat[i][j];
    return true;
}

// Check if matrix is symmetric: a[i][j] == a[j][i] for all i != j.
// Only checks upper triangle O(n^2/2).
bool isSymmetric(const vector<vector<int>>& mat) {
    int n = static_cast<int>(mat.size());
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (mat[i][j] != mat[j][i]) return false;
    return true;
}

int main() {
    vector<vector<int>> mat;
    int rows, cols;
    if (!readMatrix("matrix.txt", mat, rows, cols)) return 1;

    // Not square -> not symmetric
    if (rows != cols) {
        cout << "is_symmetric=0\n";
        return 0;
    }

    cout << "is_symmetric=" << (isSymmetric(mat) ? 1 : 0) << "\n";
    return 0;
}
