// ============================================================
// Tuan 10 - Bai 5: Text analysis pipeline
// Doc text.txt va stopwords.txt.
// Pipeline: normalize -> tokenize -> loc stop-words -> dem -> top-20.
// Ghi freq.csv (top-20) va summary.txt (total, unique, top-5 dang bang).
// Ham: readText(), normalize(), tokenize(), filterStopWords(),
//      countFreq(), writeFreq(), writeSummary().
// ============================================================
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <iomanip>
using namespace std;

// Read entire file content.
string readText(const string& path) {
    ifstream fin(path);
    if (!fin) { cerr << "Error: cannot open " << path << "\n"; return ""; }
    string content((istreambuf_iterator<char>(fin)), istreambuf_iterator<char>());
    return content;
}

// Normalize: convert to lowercase, replace non-alpha with space.
string normalize(const string& text) {
    string result = text;
    for (char& c : result) {
        if (c >= 'A' && c <= 'Z') c = c - 'A' + 'a';
        else if (!((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))) c = ' ';
    }
    return result;
}

// Tokenize by whitespace.
vector<string> tokenize(const string& text) {
    vector<string> tokens;
    istringstream ss(text);
    string word;
    while (ss >> word) tokens.push_back(word);
    return tokens;
}

// Read stopwords from file (one per line).
vector<string> readStopwords(const string& path) {
    vector<string> sw;
    ifstream fin(path);
    if (!fin) return sw;
    string line;
    while (getline(fin, line)) {
        string t = line;
        // Normalize stopword to lowercase
        for (char& c : t) if (c >= 'A' && c <= 'Z') c = c - 'A' + 'a';
        istringstream ss(t);
        string w;
        while (ss >> w) sw.push_back(w);
    }
    return sw;
}

// Filter stop-words from token list.
vector<string> filterStopWords(const vector<string>& tokens,
                                const vector<string>& stopwords) {
    // Build set-like check using a map
    map<string, bool> swMap;
    for (const string& w : stopwords) swMap[w] = true;

    vector<string> filtered;
    for (const string& t : tokens)
        if (!swMap.count(t)) filtered.push_back(t);
    return filtered;
}

// Count word frequencies.
map<string, int> countFreq(const vector<string>& tokens) {
    map<string, int> freq;
    for (const string& t : tokens) freq[t]++;
    return freq;
}

// Sort freq map by count descending, then alphabetically.
vector<pair<string, int>> sortedFreq(const map<string, int>& freq) {
    vector<pair<string, int>> v(freq.begin(), freq.end());
    // Insertion sort (simple)
    for (int i = 1; i < static_cast<int>(v.size()); i++) {
        auto key = v[i];
        int j = i - 1;
        while (j >= 0 && (v[j].second < key.second ||
               (v[j].second == key.second && v[j].first > key.first))) {
            v[j + 1] = v[j]; j--;
        }
        v[j + 1] = key;
    }
    return v;
}

// Write top-20 frequency CSV.
void writeFreq(const string& path, const vector<pair<string, int>>& sorted) {
    ofstream fout(path);
    if (!fout) { cerr << "Error: cannot open " << path << "\n"; return; }
    fout << "word,count\n";
    int limit = (static_cast<int>(sorted.size()) < 20) ? static_cast<int>(sorted.size()) : 20;
    for (int i = 0; i < limit; i++)
        fout << sorted[i].first << "," << sorted[i].second << "\n";
}

// Write summary with top-5 table.
void writeSummary(const string& path, int total, int unique,
                  const vector<pair<string, int>>& sorted) {
    ofstream fout(path);
    if (!fout) { cerr << "Error: cannot open " << path << "\n"; return; }
    fout << "total_tokens=" << total  << "\n";
    fout << "unique_words=" << unique << "\n";
    fout << "--- top-5 ---\n";
    fout << left << setw(20) << "word" << setw(10) << "count" << "\n";
    int limit = (static_cast<int>(sorted.size()) < 5) ? static_cast<int>(sorted.size()) : 5;
    for (int i = 0; i < limit; i++)
        fout << left << setw(20) << sorted[i].first << setw(10) << sorted[i].second << "\n";
}

int main() {
    string raw = readText("text.txt");
    if (raw.empty()) {
        // Write empty outputs
        ofstream fq("freq.csv"); fq << "word,count\n";
        ofstream fs("summary.txt"); fs << "total_tokens=0\nunique_words=0\n--- top-5 ---\n";
        return 0;
    }

    string normed = normalize(raw);
    vector<string> tokens = tokenize(normed);

    vector<string> stopwords = readStopwords("stopwords.txt");
    vector<string> filtered  = filterStopWords(tokens, stopwords);

    map<string, int> freq  = countFreq(filtered);
    vector<pair<string, int>> sorted = sortedFreq(freq);

    writeFreq("freq.csv", sorted);
    writeSummary("summary.txt", static_cast<int>(filtered.size()),
                 static_cast<int>(freq.size()), sorted);

    cout << "Done. freq.csv and summary.txt written.\n";
    return 0;
}
