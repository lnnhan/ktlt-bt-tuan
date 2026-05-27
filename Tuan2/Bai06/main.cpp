// ============================================================
// Tuan 2 - Bai 6: Tim vi tri phan tu lon nhat
// Doc mang so nguyen. Tim chi so phan tu lon nhat
// (neu nhieu phan tu bang nhau -> lay chi so nho nhat).
// Output: max_val=<v> / max_idx=<i>.
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
    arr.resize(n);
    for (int i = 0; i < n; i++) fin >> arr[i];
    return true;
}

// Find index of maximum element (first occurrence if ties).
// Returns -1 if array is empty.
int findMaxIdx(const vector<int>& arr) {
    if (arr.empty()) return -1;
    int maxIdx = 0;
    for (int i = 1; i < static_cast<int>(arr.size()); i++)
        if (arr[i] > arr[maxIdx]) maxIdx = i;
    return maxIdx;
}

int main() {
    vector<int> arr;
    if (!readIntArray("array.txt", arr)) return 1;

    if (arr.empty()) {
        cout << "EMPTY\n";
        return 0;
    }

    int idx = findMaxIdx(arr);
    cout << "max_val=" << arr[idx] << " / max_idx=" << idx << "\n";
    return 0;
}
