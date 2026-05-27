// ============================================================
// Tuan 4 - Bai 2: Kadane co truy vet l, r
// Mo rong Bai 1: tim them chi so l, r (0-based) cua doan tot nhat.
// Neu nhieu doan bang nhau, chon doan co l nho nhat.
// Output: max_sum=<v> / l=<i> / r=<j>.
// Case bien: toan am -> doan 1 phan tu la phan tu lon nhat.
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

struct KadaneAns {
    long long sum;
    int l, r;
};

// Kadane with index tracking.
// Tracks 'start' for current window; updates bestL, bestR when bestSoFar improves.
KadaneAns kadaneWithIndex(const vector<int>& arr) {
    long long bestEnding = arr[0], bestSoFar = arr[0];
    int start = 0, bestL = 0, bestR = 0;

    for (int i = 1; i < static_cast<int>(arr.size()); i++) {
        // When starting fresh from arr[i] is better, reset start
        if (arr[i] > bestEnding + arr[i]) {
            bestEnding = arr[i];
            start = i;
        } else {
            bestEnding += arr[i];
        }
        // Strict > to prefer leftmost l when sums are equal
        if (bestEnding > bestSoFar) {
            bestSoFar = bestEnding;
            bestL = start;
            bestR = i;
        }
    }
    return {bestSoFar, bestL, bestR};
}

int main() {
    vector<int> arr;
    if (!readIntArray("array.txt", arr)) return 1;

    if (arr.empty()) {
        cout << "EMPTY\n";
        return 0;
    }

    KadaneAns ans = kadaneWithIndex(arr);
    cout << "max_sum=" << ans.sum << " / l=" << ans.l << " / r=" << ans.r << "\n";
    return 0;
}
