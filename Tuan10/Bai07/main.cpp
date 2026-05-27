// ============================================================
// Tuan 10 - Bai 7: Sliding window multi-stat
// Doc mang so thuc va k. Tinh rolling mean, rolling max, rolling min.
// Ghi multi_rolling.csv: i, mean_i, max_i, min_i (setprecision(6)).
// Moi loai rolling la 1 ham rieng.
// ============================================================
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

// Read array and window size from file.
// File format: first line = k, second line = n, rest = values.
bool readInput(const string& path, vector<double>& arr, int& k) {
    ifstream fin(path);
    if (!fin) { cerr << "Error: cannot open " << path << "\n"; return false; }
    fin >> k;
    int n;
    fin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++) fin >> arr[i];
    return true;
}

// Compute rolling mean for window size k.
// result[i] = mean of arr[i..i+k-1] for i = 0..n-k.
vector<double> rollingMean(const vector<double>& arr, int k) {
    int n = static_cast<int>(arr.size());
    vector<double> res;
    if (k > n) return res;
    double sum = 0;
    for (int i = 0; i < k; i++) sum += arr[i];
    res.push_back(sum / k);
    for (int i = k; i < n; i++) {
        sum += arr[i] - arr[i - k];
        res.push_back(sum / k);
    }
    return res;
}

// Compute rolling max for window size k (simple O(n*k)).
vector<double> rollingMax(const vector<double>& arr, int k) {
    int n = static_cast<int>(arr.size());
    vector<double> res;
    if (k > n) return res;
    for (int i = 0; i <= n - k; i++) {
        double mx = arr[i];
        for (int j = i + 1; j < i + k; j++) if (arr[j] > mx) mx = arr[j];
        res.push_back(mx);
    }
    return res;
}

// Compute rolling min for window size k (simple O(n*k)).
vector<double> rollingMin(const vector<double>& arr, int k) {
    int n = static_cast<int>(arr.size());
    vector<double> res;
    if (k > n) return res;
    for (int i = 0; i <= n - k; i++) {
        double mn = arr[i];
        for (int j = i + 1; j < i + k; j++) if (arr[j] < mn) mn = arr[j];
        res.push_back(mn);
    }
    return res;
}

int main() {
    vector<double> arr;
    int k;
    if (!readInput("input.txt", arr, k)) return 1;

    vector<double> means = rollingMean(arr, k);
    vector<double> maxs  = rollingMax(arr, k);
    vector<double> mins  = rollingMin(arr, k);

    ofstream fout("multi_rolling.csv");
    if (!fout) { cerr << "Error: cannot open multi_rolling.csv\n"; return 1; }
    fout << "i,mean_i,max_i,min_i\n";
    fout << fixed << setprecision(6);
    for (int i = 0; i < static_cast<int>(means.size()); i++)
        fout << i << "," << means[i] << "," << maxs[i] << "," << mins[i] << "\n";

    cout << "Done. Written to multi_rolling.csv\n";
    return 0;
}
