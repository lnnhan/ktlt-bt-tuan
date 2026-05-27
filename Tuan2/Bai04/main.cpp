// ============================================================
// Tuan 2 - Bai 4: Variance va std deviation
// Doc mang so thuc. Tinh variance quan the (chia n) va std deviation.
// Output: mean=<f> / variance=<f> / std=<f> (setprecision(6)).
// Xu ly: n=0 -> 'EMPTY'; n=1 -> variance=0, std=0.
// Ham: double calcVariance(vector<double>, double mean).
// ============================================================
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

// Read n doubles from file into arr.
bool readArray(const string& path, vector<double>& arr) {
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

// Calculate mean.
double calcMean(const vector<double>& arr) {
    double sum = 0.0;
    for (double v : arr) sum += v;
    return sum / static_cast<double>(arr.size());
}

// Calculate population variance (divide by n).
// Uses long double accumulator to reduce catastrophic cancellation.
double calcVariance(const vector<double>& arr, double mean) {
    long double acc = 0.0L;
    for (double v : arr) {
        long double diff = static_cast<long double>(v) - static_cast<long double>(mean);
        acc += diff * diff;
    }
    return static_cast<double>(acc / static_cast<long double>(arr.size()));
}

int main() {
    vector<double> arr;
    if (!readArray("array.txt", arr)) return 1;

    if (arr.empty()) {
        cout << "EMPTY\n";
        return 0;
    }

    double mean = calcMean(arr);
    double var  = calcVariance(arr, mean);
    double std_ = sqrt(var);

    cout << fixed << setprecision(6);
    cout << "mean=" << mean << " / variance=" << var << " / std=" << std_ << "\n";
    return 0;
}
