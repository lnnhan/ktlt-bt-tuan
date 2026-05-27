// ============================================================
// Tuan 6 - Bai 9: Xoay ma tran 90 do theo chieu kim dong ho
// Doc ma tran m×n. Xoay 90 do theo chieu kim dong ho:
//   phan tu (i,j) -> (j, m-1-i) trong ma tran n×m moi.
// Ghi ma tran ket qua ra rotated.txt.
// ============================================================
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

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

int main() {
    vector<vector<int>> mat;
    int m, n;
    if (!readMatrix("matrix.txt", mat, m, n)) return 1;

    // Rotated matrix has dimensions n×m
    // (i,j) in original -> (j, m-1-i) in rotated
    vector<vector<int>> rot(n, vector<int>(m, 0));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            rot[j][m - 1 - i] = mat[i][j];

    ofstream fout("rotated.txt");
    if (!fout) { cerr << "Error: cannot open rotated.txt\n"; return 1; }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j > 0) fout << " ";
            fout << rot[i][j];
        }
        fout << "\n";
    }

    cout << "Done. Rotated matrix written to rotated.txt\n";
    return 0;
}
