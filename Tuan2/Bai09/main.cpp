// ============================================================
// Tuan 2 - Bai 9: Histogram don gian
// Doc mang so thuc va so nguyen k (so bins).
// Chia deu khoang [min, max] thanh k bins. Dem so phan tu trong moi bin.
// Ghi histogram.txt: moi dong la [lo, hi): count.
// Phan tu = max -> thuoc bin cuoi.
// ============================================================
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

// Read array and k from file.
// File format: first line = k, second line = n, rest = values
bool readInput(const string& path, vector<double>& arr, int& k) {
    ifstream fin(path);
    if (!fin) {
        cerr << "Error: cannot open file " << path << "\n";
        return false;
    }
    fin >> k;
    int n;
    fin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++) fin >> arr[i];
    return true;
}

// Find min value.
double findMin(const vector<double>& arr) {
    double mn = arr[0];
    for (size_t i = 1; i < arr.size(); i++)
        if (arr[i] < mn) mn = arr[i];
    return mn;
}

// Find max value.
double findMax(const vector<double>& arr) {
    double mx = arr[0];
    for (size_t i = 1; i < arr.size(); i++)
        if (arr[i] > mx) mx = arr[i];
    return mx;
}

// Determine which bin index an element belongs to.
// Elements exactly equal to max go to the last bin.
int getBinIndex(double val, double minV, double binWidth, int k) {
    int idx = static_cast<int>((val - minV) / binWidth);
    if (idx >= k) idx = k - 1; // clamp max to last bin
    return idx;
}

int main() {
    vector<double> arr;
    int k;
    if (!readInput("input.txt", arr, k)) return 1;

    if (arr.empty() || k <= 0) {
        cout << "EMPTY or invalid k\n";
        return 0;
    }

    double mn = findMin(arr);
    double mx = findMax(arr);

    // Handle case where all elements are the same
    if (mx == mn) {
        ofstream fout("histogram.txt");
        fout << fixed << setprecision(6);
        fout << "[" << mn << ", " << mx << "]: " << arr.size() << "\n";
        cout << "Done. Written to histogram.txt\n";
        return 0;
    }

    double binWidth = (mx - mn) / static_cast<double>(k);
    vector<int> counts(k, 0);

    for (double v : arr) {
        int idx = getBinIndex(v, mn, binWidth, k);
        counts[idx]++;
    }

    ofstream fout("histogram.txt");
    if (!fout) {
        cerr << "Error: cannot open histogram.txt\n";
        return 1;
    }
    fout << fixed << setprecision(6);
    for (int i = 0; i < k; i++) {
        double lo = mn + i * binWidth;
        double hi = mn + (i + 1) * binWidth;
        fout << "[" << lo << ", " << hi << "): " << counts[i] << "\n";
    }

    cout << "Done. Written to histogram.txt\n";
    return 0;
}
