// ============================================================
// Tuan 10 - Bai 4: Multi-query prefix sum tong hop
// Doc mang, sau do 3 loai truy van: 'SUM l r', 'AVG l r', 'CNT l r v'.
// Ghi ket qua tung truy van. In 'INVALID' neu chi so sai.
// Moi loai truy van la 1 ham rieng: handleSUM(), handleAVG(), handleCNT().
// ============================================================
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

// Read n integers from file (first line = n).
bool readArray(const string& path, vector<int>& arr) {
    ifstream fin(path);
    if (!fin) { cerr << "Error: cannot open " << path << "\n"; return false; }
    int n;
    fin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++) fin >> arr[i];
    return true;
}

// Validate 0-based indices [l, r] for array of size n.
bool validRange(int l, int r, int n) {
    return l >= 0 && r < n && l <= r;
}

// Handle SUM query: sum of arr[l..r].
void handleSUM(const vector<long long>& pre, int l, int r, int n, ofstream& fout) {
    if (!validRange(l, r, n)) { fout << "INVALID\n"; return; }
    long long ans = pre[r + 1] - pre[l];
    fout << ans << "\n";
}

// Handle AVG query: average of arr[l..r] with 6 decimal places.
void handleAVG(const vector<long long>& pre, int l, int r, int n, ofstream& fout) {
    if (!validRange(l, r, n)) { fout << "INVALID\n"; return; }
    long long sum = pre[r + 1] - pre[l];
    double avg = static_cast<double>(sum) / (r - l + 1);
    fout << fixed << setprecision(6) << avg << "\n";
}

// Handle CNT query: count elements == v in arr[l..r] (brute force O(n)).
void handleCNT(const vector<int>& arr, int l, int r, int v, int n, ofstream& fout) {
    if (!validRange(l, r, n)) { fout << "INVALID\n"; return; }
    int cnt = 0;
    for (int i = l; i <= r; i++) if (arr[i] == v) cnt++;
    fout << cnt << "\n";
}

int main() {
    vector<int> arr;
    if (!readArray("array.txt", arr)) return 1;
    int n = static_cast<int>(arr.size());

    // Build prefix sum array (1-indexed for easy query).
    vector<long long> pre(n + 1, 0);
    for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + arr[i];

    ifstream fq("queries.txt");
    if (!fq) { cerr << "Error: cannot open queries.txt\n"; return 1; }

    ofstream fout("answers.txt");
    if (!fout) { cerr << "Error: cannot open answers.txt\n"; return 1; }

    string line;
    while (getline(fq, line)) {
        if (line.empty()) continue;
        istringstream ss(line);
        string type;
        ss >> type;

        if (type == "SUM") {
            int l, r; ss >> l >> r;
            handleSUM(pre, l, r, n, fout);
        } else if (type == "AVG") {
            int l, r; ss >> l >> r;
            handleAVG(pre, l, r, n, fout);
        } else if (type == "CNT") {
            int l, r, v; ss >> l >> r >> v;
            handleCNT(arr, l, r, v, n, fout);
        } else {
            fout << "INVALID\n";
        }
    }

    cout << "Done. Answers written to answers.txt\n";
    return 0;
}
