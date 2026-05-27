// ============================================================
// Tuan 2 - Bai 7: Chuan hoa mang Min-Max
// Doc mang so thuc. Chuan hoa: x' = (x - min) / (max - min).
// Ghi normalized.csv: i, original, scaled (setprecision(6)).
// Xu ly: neu max=min thi scaled=0 cho moi phan tu.
// ============================================================
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

// Read n doubles from file.
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

// Find min value (arr must be non-empty).
double findMin(const vector<double>& arr) {
    double mn = arr[0];
    for (size_t i = 1; i < arr.size(); i++)
        if (arr[i] < mn) mn = arr[i];
    return mn;
}

// Find max value (arr must be non-empty).
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
        // Write empty CSV with header only
        ofstream fout("normalized.csv");
        fout << "i,original,scaled\n";
        return 0;
    }

    double mn = findMin(arr);
    double mx = findMax(arr);
    double range = mx - mn;

    ofstream fout("normalized.csv");
    if (!fout) {
        cerr << "Error: cannot open normalized.csv for writing\n";
        return 1;
    }
    fout << "i,original,scaled\n";
    fout << fixed << setprecision(6);

    for (size_t i = 0; i < arr.size(); i++) {
        // If max == min, all scaled values = 0
        double scaled = (range == 0.0) ? 0.0 : (arr[i] - mn) / range;
        fout << i << "," << arr[i] << "," << scaled << "\n";
    }

    cout << "Done. Results written to normalized.csv\n";
    return 0;
}
