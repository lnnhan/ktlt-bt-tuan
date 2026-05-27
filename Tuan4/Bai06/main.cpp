// ============================================================
// Tuan 4 - Bai 6: Doan co tong lon nhat do dai dung k
// Doc mang va k. Tim doan lien tiep dai dung k co tong lon nhat.
// Output: max_sum=<v> / l=<i> / r=<j>. Neu k>n -> in 'IMPOSSIBLE'.
// ============================================================
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// Read n integers from file (file format: first line = n, then n values).
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

// Read k from config file.
bool readK(const string& path, int& k) {
    ifstream fin(path);
    if (!fin) {
        cerr << "Error: cannot open file " << path << "\n";
        return false;
    }
    fin >> k;
    return true;
}

int main() {
    vector<int> arr;
    if (!readIntArray("array.txt", arr)) return 1;
    int k;
    if (!readK("config.txt", k)) return 1;

    int n = static_cast<int>(arr.size());
    if (k > n || k <= 0) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    // Compute sum of first window of size k using sliding window
    long long windowSum = 0;
    for (int i = 0; i < k; i++) windowSum += arr[i];

    long long bestSum = windowSum;
    int bestL = 0;

    for (int i = k; i < n; i++) {
        windowSum += arr[i] - arr[i - k];
        if (windowSum > bestSum) {
            bestSum = windowSum;
            bestL = i - k + 1;
        }
    }

    cout << "max_sum=" << bestSum << " / l=" << bestL << " / r=" << (bestL + k - 1) << "\n";
    return 0;
}
