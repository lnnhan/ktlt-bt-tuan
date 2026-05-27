// ============================================================
// Tuan 2 - Bai 2: Dem phan tu thoa dieu kien
// Doc mang so nguyen tu array.txt, nguong k tu config.txt.
// Dem va in: count_ge_k va count_lt_k.
// Ham: int countIf(vector<int>, int k, bool geq).
// Case bien: n=0 -> ca 2 deu 0; tat ca phan tu bang k.
// ============================================================
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// Read n integers from file into arr.
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

// Read a single integer threshold from file.
bool readThreshold(const string& path, int& k) {
    ifstream fin(path);
    if (!fin) {
        cerr << "Error: cannot open file " << path << "\n";
        return false;
    }
    fin >> k;
    return true;
}

// Count elements satisfying condition:
//   geq=true  -> count elements >= k
//   geq=false -> count elements <  k
int countIf(const vector<int>& arr, int k, bool geq) {
    int cnt = 0;
    for (int v : arr) {
        if (geq && v >= k) cnt++;
        if (!geq && v < k) cnt++;
    }
    return cnt;
}

int main() {
    vector<int> arr;
    if (!readIntArray("array.txt", arr)) return 1;

    int k;
    if (!readThreshold("config.txt", k)) return 1;

    int ge = countIf(arr, k, true);
    int lt = countIf(arr, k, false);

    cout << "count_ge_k=" << ge << "\n";
    cout << "count_lt_k=" << lt << "\n";
    return 0;
}
