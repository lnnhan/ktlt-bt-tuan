// ============================================================
// Tuan 10 - Bai 8: Sort + search tong hop
// Doc records.csv (id, score). Doc queries.txt: moi dong la 1 id can tra.
// Sap xep records theo score giam (stable sort). Voi moi query: tim record va in rank
// (1-based), id, score. Neu id khong ton tai: in 'NOT_FOUND'.
// ============================================================
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct Record {
    string id;
    double score;
};

string trim(const string& s) {
    size_t st = s.find_first_not_of(" \t\r\n");
    size_t en = s.find_last_not_of(" \t\r\n");
    if (st == string::npos) return "";
    return s.substr(st, en - st + 1);
}

// Read records from CSV (id, score). First line = header.
bool readRecords(const string& path, vector<Record>& records) {
    ifstream fin(path);
    if (!fin) { cerr << "Error: cannot open " << path << "\n"; return false; }
    string line;
    getline(fin, line); // skip header
    while (getline(fin, line)) {
        if (trim(line).empty()) continue;
        istringstream ss(line);
        string sid, sscore;
        if (!getline(ss, sid, ',')) continue;
        if (!getline(ss, sscore)) continue;
        Record r;
        r.id = trim(sid);
        r.score = stod(trim(sscore));
        records.push_back(r);
    }
    return true;
}

// Read query ids from file (one per line).
bool readQueries(const string& path, vector<string>& ids) {
    ifstream fin(path);
    if (!fin) { cerr << "Error: cannot open " << path << "\n"; return false; }
    string line;
    while (getline(fin, line)) {
        string t = trim(line);
        if (!t.empty()) ids.push_back(t);
    }
    return true;
}

// Stable sort by score descending (insertion sort preserves original order for equal).
void stableSort(vector<Record>& records) {
    for (int i = 1; i < static_cast<int>(records.size()); i++) {
        Record key = records[i];
        int j = i - 1;
        // Only move when strictly less (stable: equal stays in original order)
        while (j >= 0 && records[j].score < key.score) {
            records[j + 1] = records[j];
            j--;
        }
        records[j + 1] = key;
    }
}

int main() {
    vector<Record> records;
    if (!readRecords("records.csv", records)) return 1;

    stableSort(records);

    vector<string> queries;
    if (!readQueries("queries.txt", queries)) return 1;

    for (const string& qid : queries) {
        bool found = false;
        for (int i = 0; i < static_cast<int>(records.size()); i++) {
            if (records[i].id == qid) {
                cout << "rank=" << (i + 1) << " / id=" << records[i].id
                     << " / score=" << fixed << setprecision(6) << records[i].score << "\n";
                found = true;
                break;
            }
        }
        if (!found) cout << "NOT_FOUND\n";
    }
    return 0;
}
