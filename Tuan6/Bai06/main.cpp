// ============================================================
// Tuan 6 - Bai 6: Nhan hai ma tran
// Doc ma tran A (m×k) va B (k×n). Tinh C = A×B.
// Neu kich thuoc khong khop (cols_A != rows_B) -> in 'INCOMPATIBLE'.
// Ghi C ra output.csv: moi hang la 1 dong, phan tu cach nhau boi space.
// ============================================================
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

typedef vector<vector<long long>> Matrix;

// Read matrix from file. First line: "rows cols".
bool readMatrix(const string& path, Matrix& mat, int& rows, int& cols) {
    ifstream fin(path);
    if (!fin) {
        cerr << "Error: cannot open file " << path << "\n";
        return false;
    }
    fin >> rows >> cols;
    mat.assign(rows, vector<long long>(cols, 0));
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            fin >> mat[i][j];
    return true;
}

// Multiply A (m×k) × B (k×n) -> C (m×n).
Matrix multiply(const Matrix& A, const Matrix& B, int m, int k, int n) {
    Matrix C(m, vector<long long>(n, 0));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            for (int p = 0; p < k; p++)
                C[i][j] += A[i][p] * B[p][j];
    return C;
}

int main() {
    Matrix A, B;
    int rA, cA, rB, cB;
    if (!readMatrix("matA.txt", A, rA, cA)) return 1;
    if (!readMatrix("matB.txt", B, rB, cB)) return 1;

    if (cA != rB) {
        cout << "INCOMPATIBLE\n";
        return 0;
    }

    Matrix C = multiply(A, B, rA, cA, cB);

    ofstream fout("output.txt");
    if (!fout) { cerr << "Error: cannot open output.txt\n"; return 1; }
    for (int i = 0; i < rA; i++) {
        for (int j = 0; j < cB; j++) {
            if (j > 0) fout << " ";
            fout << C[i][j];
        }
        fout << "\n";
    }

    cout << "Done. Result written to output.txt\n";
    return 0;
}
