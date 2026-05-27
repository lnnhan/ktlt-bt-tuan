// ============================================================
// Tuan 6 - Bai 8: Kiem tra ma tran tam giac
// Doc ma tran vuong n×n. Kiem tra:
//   (a) tam giac tren: a[i][j]=0 khi i>j
//   (b) tam giac duoi: a[i][j]=0 khi i<j
// Output: is_upper=<0/1> / is_lower=<0/1>.
// ============================================================
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// Read square matrix. First line: "n n".
bool readMatrix(const string& path, vector<vector<int>>& mat, int& n) {
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
    if (!readMatrix("matrix.txt", mat, n)) return 1;

    bool upper = true, lower = true;

    for (int i = 0; i < n && (upper || lower); i++) {
        for (int j = 0; j < n; j++) {
            // Upper triangular: elements below diagonal must be 0
            if (i > j && mat[i][j] != 0) upper = false;
            // Lower triangular: elements above diagonal must be 0
            if (i < j && mat[i][j] != 0) lower = false;
        }
    }

    cout << "is_upper=" << (upper ? 1 : 0) << " / is_lower=" << (lower ? 1 : 0) << "\n";
    return 0;
}
