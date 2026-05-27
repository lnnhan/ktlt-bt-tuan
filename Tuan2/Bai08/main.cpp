// ============================================================
// Tuan 2 - Bai 8: Impute missing bang median
// Doc mang co missing (NA/blank). Tinh median cua gia tri hop le.
// Thay missing bang median. Ghi output.csv va summary.
// Median: sort cac gia tri hop le; n le -> phan tu giua;
//         n chan -> trung binh 2 phan tu giua.
// ============================================================
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

// Check if a string token represents a missing value (NA, NaN, blank).
bool isMissing(const string& token) {
    if (token.empty()) return true;
    // Case-insensitive check for "na" or "nan"
    string t = token;
    for (char& c : t) {
        if (c >= 'A' && c <= 'Z') c = c - 'A' + 'a';
    }
    return (t == "na" || t == "nan");
}

// Simple insertion sort (no <algorithm>).
void insertionSort(vector<double>& v) {
    for (size_t i = 1; i < v.size(); i++) {
        double key = v[i];
        int j = static_cast<int>(i) - 1;
        while (j >= 0 && v[j] > key) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = key;
    }
}

// Calculate median of a sorted vector of valid values.
double calcMedian(vector<double> valid) {
    insertionSort(valid);
    size_t n = valid.size();
    if (n % 2 == 1) return valid[n / 2];
    return (valid[n / 2 - 1] + valid[n / 2]) / 2.0;
}

int main() {
    ifstream fin("input.csv");
    if (!fin) {
        cerr << "Error: cannot open input.csv\n";
        return 1;
    }

    // Parse tokens — values separated by commas or spaces/newlines
    vector<string> tokens;
    string line;
    while (getline(fin, line)) {
        istringstream ss(line);
        string tok;
        while (getline(ss, tok, ',')) {
            // Trim whitespace
            size_t start = tok.find_first_not_of(" \t\r\n");
            size_t end   = tok.find_last_not_of(" \t\r\n");
            tok = (start == string::npos) ? "" : tok.substr(start, end - start + 1);
            tokens.push_back(tok);
        }
    }

    // Separate valid and missing
    vector<double> valid;
    vector<bool> missing(tokens.size(), false);
    for (size_t i = 0; i < tokens.size(); i++) {
        if (isMissing(tokens[i])) {
            missing[i] = true;
        } else {
            valid.push_back(stod(tokens[i]));
        }
    }

    int countValid   = static_cast<int>(valid.size());
    int countMissing = static_cast<int>(tokens.size()) - countValid;

    // Compute median (0 if no valid values)
    double median = 0.0;
    if (!valid.empty()) median = calcMedian(valid);

    // Write output.csv with imputed values
    ofstream fout("output.csv");
    if (!fout) {
        cerr << "Error: cannot open output.csv\n";
        return 1;
    }
    fout << "i,value_imputed\n";
    fout << fixed << setprecision(6);
    for (size_t i = 0; i < tokens.size(); i++) {
        double val = missing[i] ? median : stod(tokens[i]);
        fout << i << "," << val << "\n";
    }

    // Write summary
    ofstream fsum("summary.txt");
    if (!fsum) {
        cerr << "Error: cannot open summary.txt\n";
        return 1;
    }
    fsum << fixed << setprecision(6);
    fsum << "count_valid="   << countValid   << "\n";
    fsum << "count_missing=" << countMissing << "\n";
    fsum << "median="        << median       << "\n";

    cout << "Done. Imputed data in output.csv, summary in summary.txt\n";
    return 0;
}
