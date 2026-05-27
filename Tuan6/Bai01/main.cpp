// ============================================================
// Tuan 6 - Bai 1: Tong hang va cot ma tran
// Doc ma tran m×n so nguyen tu matrix.txt.
// Tinh tong tung hang va tung cot.
// Ghi row_sums.txt va col_sums.txt (moi dong: i, tong).
// Case bien: ma tran 1×1; m=0 hoac n=0 -> file output rong.
// ============================================================
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// Read m×n integer matrix from file.
// File format: first line "m n", then m*n values row by row.
bool readMatrix(const string& path, vector<vector<int>>& mat) {
    ifstream fin(path);
    if (!fin) {
        cerr << "Error: cannot open file " << path << "\n";
        return false;
    }
    int m, n;
    fin >> m >> n;
    if (m < 0 || n < 0) return false;
    mat.assign(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            fin >> mat[i][j];
    return true;
}

// Compute sum of each row. Returns vector of size m.
vector<long long> rowSums(const vector<vector<int>>& mat) {
    vector<long long> sums(mat.size(), 0);
    for (int i = 0; i < static_cast<int>(mat.size()); i++)
        for (int v : mat[i]) sums[i] += v;
    return sums;
}

// Compute sum of each column. Returns vector of size n.
vector<long long> colSums(const vector<vector<int>>& mat) {
    if (mat.empty()) return {};
    int n = static_cast<int>(mat[0].size());
    vector<long long> sums(n, 0);
    for (const auto& row : mat)
        for (int j = 0; j < n; j++) sums[j] += row[j];
    return sums;
}

int main() {
    vector<vector<int>> mat;
    if (!readMatrix("matrix.txt", mat)) return 1;

    // Write row_sums.txt
    {
        ofstream fout("row_sums.txt");
        if (!fout) { cerr << "Error: cannot open row_sums.txt\n"; return 1; }
        vector<long long> rs = rowSums(mat);
        for (int i = 0; i < static_cast<int>(rs.size()); i++)
            fout << i << " " << rs[i] << "\n";
    }

    // Write col_sums.txt
    {
        ofstream fout("col_sums.txt");
        if (!fout) { cerr << "Error: cannot open col_sums.txt\n"; return 1; }
        vector<long long> cs = colSums(mat);
        for (int j = 0; j < static_cast<int>(cs.size()); j++)
            fout << j << " " << cs[j] << "\n";
    }

    cout << "Done. Written to row_sums.txt and col_sums.txt\n";
    return 0;
}
