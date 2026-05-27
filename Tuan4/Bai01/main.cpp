// ============================================================
// Tuan 4 - Bai 1: Max subarray sum (Kadane co ban)
// Doc mang so nguyen tu array.txt.
// Tim tong lon nhat cua doan con lien tiep.
// Output: max_sum=<v>.
// Case bien: n=0 -> 'EMPTY'; toan so am -> max_sum = phan tu lon nhat.
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

// Kadane's algorithm: find maximum subarray sum.
// Handles all-negative arrays by returning the largest single element.
long long kadane(const vector<int>& arr) {
    long long bestEnding = arr[0];
    long long bestSoFar  = arr[0];
    for (int i = 1; i < static_cast<int>(arr.size()); i++) {
        bestEnding = (arr[i] > bestEnding + arr[i]) ? arr[i] : bestEnding + arr[i];
        if (bestEnding > bestSoFar) bestSoFar = bestEnding;
    }
    return bestSoFar;
}

int main() {
    vector<int> arr;
    if (!readIntArray("array.txt", arr)) return 1;

    if (arr.empty()) {
        cout << "EMPTY\n";
        return 0;
    }

    cout << "max_sum=" << kadane(arr) << "\n";
    return 0;
}
