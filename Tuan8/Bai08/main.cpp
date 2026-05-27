// ============================================================
// Tuan 8 - Bai 8: Ma tran don vi phan so
// Doc n tu config. Tao ma tran don vi n×n phan so (duong cheo = 1/1, con lai = 0/1).
// Doc ma tran A n×n phan so. Kiem tra A*I = A va I*A = A (so sanh tung o).
// Output: is_identity_product=1 hoac 0.
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

bool fracEqual(Frac a, Frac b) {
    Frac na = normalize(a), nb = normalize(b);
    return na.num == nb.num && na.den == nb.den;
}

typedef vector<vector<Frac>> FMatrix;

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

bool readFracMatrix(const string& path, FMatrix& mat, int& n) {
    ifstream fin(path);
    if (!fin) { cerr << "Error: cannot open " << path << "\n"; return false; }
    int r, c;
    fin >> r >> c;
    n = r;
    fin.ignore();
    mat.assign(r, vector<Frac>(c, {0, 1}));
    for (int i = 0; i < r; i++) {
        string line;
        getline(fin, line);
        istringstream ss(line);
        string token;
        for (int j = 0; j < c; j++) {
            if (!getline(ss, token, ',')) break;
            mat[i][j] = parseFrac(trim(token));
        }
    }
    return true;
}

// Multiply two n×n fraction matrices.
FMatrix matMul(const FMatrix& A, const FMatrix& B, int n) {
    FMatrix C(n, vector<Frac>(n, {0, 1}));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            Frac sum = {0, 1};
            for (int k = 0; k < n; k++)
                sum = addFrac(sum, mulFrac(A[i][k], B[k][j]));
            C[i][j] = sum;
        }
    return C;
}

// Check if two matrices are element-wise equal.
bool matEqual(const FMatrix& A, const FMatrix& B, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (!fracEqual(A[i][j], B[i][j])) return false;
    return true;
}

int main() {
    // Read n from config
    ifstream cfg("config.txt");
    if (!cfg) { cerr << "Error: cannot open config.txt\n"; return 1; }
    int n;
    cfg >> n;

    // Build identity matrix
    FMatrix I(n, vector<Frac>(n, {0, 1}));
    for (int i = 0; i < n; i++) I[i][i] = {1, 1};

    // Read A
    FMatrix A;
    int nA;
    if (!readFracMatrix("matA.csv", A, nA)) return 1;
    if (nA != n) {
        cout << "is_identity_product=0\n";
        return 0;
    }

    // Check A*I = A and I*A = A
    FMatrix AI = matMul(A, I, n);
    FMatrix IA = matMul(I, A, n);

    bool ok = matEqual(AI, A, n) && matEqual(IA, A, n);
    cout << "is_identity_product=" << (ok ? 1 : 0) << "\n";
    return 0;
}
