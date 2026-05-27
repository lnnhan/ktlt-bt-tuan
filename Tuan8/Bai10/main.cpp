// ============================================================
// Tuan 8 - Bai 10: Phan tich binh phuong tong (phan so chinh xac)
// Doc fractions.csv. Tinh tong binh phuong S = sum (num_i/den_i)^2
// va Var = E[X^2] - (E[X])^2. Tat ca tinh chinh xac theo phan so.
// Ghi stats.csv: sum_squares=<num>/<den> / variance=<num>/<den>.
// ============================================================
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

struct Frac {
    long long num, den;
};

long long gcd(long long a, long long b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    while (b) { long long t = b; b = a % b; a = t; }
    return a;
}

Frac normalize(Frac f) {
    if (f.den < 0) { f.num = -f.num; f.den = -f.den; }
    if (f.num == 0) { f.den = 1; return f; }
    long long g = gcd(f.num < 0 ? -f.num : f.num, f.den);
    f.num /= g; f.den /= g;
    return f;
}

Frac addFrac(Frac a, Frac b) {
    return normalize({a.num * b.den + b.num * a.den, a.den * b.den});
}

Frac mulFrac(Frac a, Frac b) {
    return normalize({a.num * b.num, a.den * b.den});
}

Frac subFrac(Frac a, Frac b) {
    return normalize({a.num * b.den - b.num * a.den, a.den * b.den});
}

Frac divFrac(Frac a, Frac b) {
    return normalize({a.num * b.den, a.den * b.num});
}

string trim(const string& s) {
    size_t st = s.find_first_not_of(" \t\r\n");
    size_t en = s.find_last_not_of(" \t\r\n");
    if (st == string::npos) return "";
    return s.substr(st, en - st + 1);
}

Frac parseFrac(const string& token) {
    size_t pos = token.find('/');
    if (pos == string::npos) return normalize({stoll(token), 1});
    return normalize({stoll(token.substr(0, pos)), stoll(token.substr(pos + 1))});
}

int main() {
    ifstream fin("fractions.csv");
    if (!fin) { cerr << "Error: cannot open fractions.csv\n"; return 1; }

    vector<Frac> fracs;
    string line;
    getline(fin, line); // skip header
    while (getline(fin, line)) {
        string t = trim(line);
        if (t.empty()) continue;
        fracs.push_back(parseFrac(t));
    }

    int n = static_cast<int>(fracs.size());
    if (n == 0) {
        ofstream fout("stats.csv");
        fout << "sum_squares=0/1\nvariance=0/1\n";
        return 0;
    }

    Frac sumX  = {0, 1};
    Frac sumX2 = {0, 1};
    Frac N     = {n, 1};

    for (const Frac& f : fracs) {
        sumX  = addFrac(sumX,  f);
        sumX2 = addFrac(sumX2, mulFrac(f, f));
    }

    // E[X] = sumX / n
    Frac EX  = divFrac(sumX,  N);
    // E[X^2] = sumX2 / n
    Frac EX2 = divFrac(sumX2, N);
    // Var = E[X^2] - (E[X])^2
    Frac var = subFrac(EX2, mulFrac(EX, EX));

    ofstream fout("stats.csv");
    if (!fout) { cerr << "Error: cannot open stats.csv\n"; return 1; }
    fout << "sum_squares=" << sumX2.num << "/" << sumX2.den << "\n";
    fout << "variance="    << var.num   << "/" << var.den   << "\n";

    cout << "Done. Written to stats.csv\n";
    return 0;
}
