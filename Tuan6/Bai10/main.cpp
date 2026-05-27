// ============================================================
// Tuan 6 - Bai 10: Dem vung con tong bang K
// Doc ma tran m×n (m,n <= 100) va K. Dem so vung chu nhat con co tong dung bang K.
// Dung prefix 2D + bai toan dem subarray sum=K tren moi cap hang.
// Output: count=<n>.
// ============================================================
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
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

// Read K from config file.
bool readK(const string& path, long long& K) {
    ifstream fin(path);
    if (!fin) {
        cerr << "Error: cannot open file " << path << "\n";
        return false;
    }
    fin >> K;
    return true;
}

int main() {
    vector<vector<int>> mat;
    int m, n;
    if (!readMatrix("matrix.txt", mat, m, n)) return 1;
    long long K;
    if (!readK("config.txt", K)) return 1;

    // Build column prefix sums for each pair of row boundaries
    // For each pair (r1, r2), compress to a 1D array and count subarrays summing to K
    long long count = 0;

    for (int r1 = 0; r1 < m; r1++) {
        vector<long long> colSum(n, 0);
        for (int r2 = r1; r2 < m; r2++) {
            // Add row r2 to column sums
            for (int c = 0; c < n; c++) colSum[c] += mat[r2][c];

            // Count subarrays in colSum with sum = K using prefix sum + hash map
            map<long long, int> freq;
            freq[0] = 1;
            long long prefSum = 0;
            for (int c = 0; c < n; c++) {
                prefSum += colSum[c];
                long long need = prefSum - K;
                if (freq.count(need)) count += freq[need];
                freq[prefSum]++;
            }
        }
    }

    cout << "count=" << count << "\n";
    return 0;
}
