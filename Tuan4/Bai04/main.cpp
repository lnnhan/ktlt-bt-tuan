// ============================================================
// Tuan 4 - Bai 4: Min subarray sum
// Doc mang so nguyen. Tim tong nho nhat cua doan con lien tiep.
// Output: min_sum=<v> / l=<i> / r=<j>.
// Case bien: toan duong -> min = phan tu nho nhat;
//            toan am    -> min = tong toan mang.
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

// Kadane variant for minimum subarray (replace max with min).
KadaneAns minSubarray(const vector<int>& arr) {
    long long bestEnding = arr[0], bestSoFar = arr[0];
    int start = 0, bestL = 0, bestR = 0;

    for (int i = 1; i < static_cast<int>(arr.size()); i++) {
        // Choose smaller: start fresh or extend current window
        if (arr[i] < bestEnding + arr[i]) {
            bestEnding = arr[i];
            start = i;
        } else {
            bestEnding += arr[i];
        }
        if (bestEnding < bestSoFar) {
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

    KadaneAns ans = minSubarray(arr);
    cout << "min_sum=" << ans.sum << " / l=" << ans.l << " / r=" << ans.r << "\n";
    return 0;
}
