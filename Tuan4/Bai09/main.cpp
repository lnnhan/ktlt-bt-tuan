// ============================================================
// Tuan 4 - Bai 9: Maximum circular subarray
// Doc mang vong tron. Tim doan con lien tiep (theo vong) co tong lon nhat.
// Goi y: max_circular = max(Kadane thuong, total_sum - min_subarray_sum).
// Chu y: neu toan so am thi chi dung Kadane thuong.
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

// Standard Kadane for max subarray.
long long kadaneMax(const vector<int>& arr) {
    long long best = arr[0], cur = arr[0];
    for (int i = 1; i < static_cast<int>(arr.size()); i++) {
        cur  = (arr[i] > cur + arr[i]) ? arr[i] : cur + arr[i];
        if (cur > best) best = cur;
    }
    return best;
}

// Kadane variant for min subarray.
long long kadaneMin(const vector<int>& arr) {
    long long best = arr[0], cur = arr[0];
    for (int i = 1; i < static_cast<int>(arr.size()); i++) {
        cur  = (arr[i] < cur + arr[i]) ? arr[i] : cur + arr[i];
        if (cur < best) best = cur;
    }
    return best;
}

int main() {
    vector<int> arr;
    if (!readIntArray("array.txt", arr)) return 1;

    if (arr.empty()) {
        cout << "EMPTY\n";
        return 0;
    }

    long long maxLinear = kadaneMax(arr);

    // Compute total sum
    long long total = 0;
    for (int v : arr) total += v;

    long long minSub = kadaneMin(arr);
    long long maxCircular = total - minSub;

    // If all elements are negative, circular formula gives 0 (invalid) -> use linear
    long long result = maxLinear;
    if (maxCircular > result && maxCircular != 0)
        result = maxCircular;

    cout << "max_sum=" << result << "\n";
    return 0;
}
