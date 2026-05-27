// ============================================================
// Tuan 4 - Bai 10: Dem so day con tang co do dai = L
// Doc mang va L. Dem so day con tang chat co dung do dai L (O(n^2)).
// dp2[i][l] = so day con tang do dai l ket thuc tai i.
// Output: count=<n>.
// ============================================================
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// Read n integers from file.
bool readIntArray(const string& path, vector<int>& arr) {
    ifstream fin(path);
    if (!fin) {
        cerr << "Error: cannot open file " << path << "\n";
        return false;
    }
    int n;
    fin >> n;
    if (n < 0) return false;
    arr.resize(n);
    for (int i = 0; i < n; i++) fin >> arr[i];
    return true;
}

// Read L from config file.
bool readL(const string& path, int& L) {
    ifstream fin(path);
    if (!fin) {
        cerr << "Error: cannot open file " << path << "\n";
        return false;
    }
    fin >> L;
    return true;
}

int main() {
    vector<int> arr;
    if (!readIntArray("array.txt", arr)) return 1;
    int L;
    if (!readL("config.txt", L)) return 1;

    int n = static_cast<int>(arr.size());
    if (L <= 0 || L > n) {
        cout << "count=0\n";
        return 0;
    }

    // dp[i][l] = number of strictly increasing subsequences of length l ending at index i
    // Use 2D vector: dp[i] indexed by length 1..L
    vector<vector<long long>> dp(n, vector<long long>(L + 1, 0));

    // Every element is a subsequence of length 1
    for (int i = 0; i < n; i++) dp[i][1] = 1;

    long long count = 0;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) {
                // Extend all subsequences ending at j by arr[i]
                for (int l = 1; l < L; l++) {
                    dp[i][l + 1] += dp[j][l];
                }
            }
        }
        count += dp[i][L];
    }

    // Also count single elements if L==1
    if (L == 1) {
        count = n;
    }

    cout << "count=" << count << "\n";
    return 0;
}
