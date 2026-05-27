// ============================================================
// Tuan 2 - Bai 1: Tim min, max, mean mang
// Doc array.txt (n, roi n so thuc). Tinh min, max, mean.
// Output: min=<f> / max=<f> / mean=<f> (setprecision(4)).
// Ham: bool readArray(path, vector<double>&); double calcMean(vector<double>).
// Case bien: n=0 -> in 'EMPTY'; n=1 -> min=max=mean=a[0].
// ============================================================
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

// Read n and n doubles from file into arr.
// Returns false if file cannot be opened or n < 0.
bool readArray(const string& path, vector<double>& arr) {
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

// Calculate arithmetic mean of arr (arr must be non-empty).
double calcMean(const vector<double>& arr) {
    double sum = 0.0;
    for (double v : arr) sum += v;
    return sum / static_cast<double>(arr.size());
}

// Find minimum value (arr must be non-empty).
double findMin(const vector<double>& arr) {
    double mn = arr[0];
    for (size_t i = 1; i < arr.size(); i++)
        if (arr[i] < mn) mn = arr[i];
    return mn;
}

// Find maximum value (arr must be non-empty).
double findMax(const vector<double>& arr) {
    double mx = arr[0];
    for (size_t i = 1; i < arr.size(); i++)
        if (arr[i] > mx) mx = arr[i];
    return mx;
}

int main() {
    vector<double> arr;
    if (!readArray("array.txt", arr)) return 1;

    if (arr.empty()) {
        cout << "EMPTY\n";
        return 0;
    }

    double mn   = findMin(arr);
    double mx   = findMax(arr);
    double mean = calcMean(arr);

    cout << fixed << setprecision(4);
    cout << "min=" << mn << " / max=" << mx << " / mean=" << mean << "\n";
    return 0;
}
