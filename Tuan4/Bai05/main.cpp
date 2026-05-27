// ============================================================
// Tuan 4 - Bai 5: LIS truy vet day con
// Mo rong LIS: in ra chi so (0-based) cac phan tu trong day con tang dai nhat.
// Neu nhieu LIS co do dai bang nhau, chon LIS ket thuc o chi so nho nhat.
// Output: lis_len=<v> / indices=<i0 i1 ...>.
// Case bien: LIS=1 -> chi 1 chi so.
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

int main() {
    vector<int> arr;
    if (!readIntArray("array.txt", arr)) return 1;

    int n = static_cast<int>(arr.size());
    if (n == 0) {
        cout << "lis_len=0 / indices=\n";
        return 0;
    }

    // dp[i] = LIS length ending at index i
    // parent[i] = previous index in LIS (-1 if head)
    vector<int> dp(n, 1), parent(n, -1);
    int bestLen = 1, bestEnd = 0;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                parent[i] = j;
            }
        }
        // Prefer smaller end index when lengths are equal
        if (dp[i] > bestLen) {
            bestLen = dp[i];
            bestEnd = i;
        }
    }

    // Reconstruct path by tracing parent pointers
    vector<int> path;
    for (int cur = bestEnd; cur != -1; cur = parent[cur])
        path.push_back(cur);

    // Reverse to get ascending order
    vector<int> indices;
    for (int k = static_cast<int>(path.size()) - 1; k >= 0; k--)
        indices.push_back(path[k]);

    cout << "lis_len=" << bestLen << " / indices=";
    for (int k = 0; k < static_cast<int>(indices.size()); k++) {
        if (k > 0) cout << " ";
        cout << indices[k];
    }
    cout << "\n";
    return 0;
}
