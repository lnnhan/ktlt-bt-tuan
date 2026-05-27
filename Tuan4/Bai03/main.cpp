// ============================================================
// Tuan 4 - Bai 3: LIS do dai O(n^2)
// Doc mang so nguyen. Tinh do dai day con tang chat dai nhat (LIS).
// Cong thuc: dp[i] = 1 + max{dp[j] : j<i va a[j]<a[i]}.
// Output: lis_len=<v>.
// Case bien: n=0 -> 0; n=1 -> 1; mang giam dan -> LIS=1.
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

// O(n^2) LIS using classic DP.
int lisLength(const vector<int>& a) {
    int n = static_cast<int>(a.size());
    if (n == 0) return 0;
    vector<int> dp(n, 1);
    int best = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i] && dp[j] + 1 > dp[i])
                dp[i] = dp[j] + 1;
        }
        if (dp[i] > best) best = dp[i];
    }
    return best;
}

int main() {
    vector<int> arr;
    if (!readIntArray("array.txt", arr)) return 1;

    if (arr.empty()) {
        cout << "lis_len=0\n";
        return 0;
    }

    cout << "lis_len=" << lisLength(arr) << "\n";
    return 0;
}
