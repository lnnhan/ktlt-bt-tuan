// ============================================================
// Tuan 8 - Bai 5: Ma tran phan so: cong va nhan
// Doc matA.csv va matB.csv (dong dau m n; moi o num/den).
// Tinh A+B (neu cung kich thuoc) va A*B (neu cols_A = rows_B). Normalize moi ket qua.
// Ghi result.csv: '=== A+B ===' hoac 'INCOMPATIBLE'; '=== A*B ===' hoac 'INCOMPATIBLE'.
// ============================================================
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct Frac {
    long long num, den;
};

// Compute GCD using Euclidean algorithm.
long long gcd(long long a, long long b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    while (b) { long long t = b; b = a % b; a = t; }
    return a;
}

// Normalize fraction: reduce and ensure den > 0.
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

typedef vector<vector<Frac>> FMatrix;

string trim(const string& s) {
    size_t st = s.find_first_not_of(" \t\r\n");
    size_t en = s.find_last_not_of(" \t\r\n");
    if (st == string::npos) return "";
    return s.substr(st, en - st + 1);
}

// Parse "num/den" token into Frac.
Frac parseFrac(const string& token) {
    size_t pos = token.find('/');
    if (pos == string::npos) return {stoll(token), 1};
    return normalize({stoll(token.substr(0, pos)), stoll(token.substr(pos + 1))});
}

// Read fraction matrix from CSV. First line: "m n".
bool readFracMatrix(const string& path, FMatrix& mat, int& rows, int& cols) {
    ifstream fin(path);
    if (!fin) { cerr << "Error: cannot open " << path << "\n"; return false; }
    fin >> rows >> cols;
    fin.ignore();
    mat.assign(rows, vector<Frac>(cols, {0, 1}));
    for (int i = 0; i < rows; i++) {
        string line;
        getline(fin, line);
        istringstream ss(line);
        string token;
        for (int j = 0; j < cols; j++) {
            if (!getline(ss, token, ',')) break;
            mat[i][j] = parseFrac(trim(token));
        }
    }
    return true;
}

// Write fraction matrix to ostream.
void writeFMatrix(ofstream& fout, const FMatrix& mat) {
    for (const auto& row : mat) {
        for (int j = 0; j < static_cast<int>(row.size()); j++) {
            if (j > 0) fout << ",";
            fout << row[j].num << "/" << row[j].den;
        }
        fout << "\n";
    }
}

// Add two matrices (same size).
bool addMatrix(const FMatrix& A, const FMatrix& B,
               int rA, int cA, int rB, int cB, FMatrix& C) {
    if (rA != rB || cA != cB) return false;
    C.assign(rA, vector<Frac>(cA, {0, 1}));
    for (int i = 0; i < rA; i++)
        for (int j = 0; j < cA; j++)
            C[i][j] = addFrac(A[i][j], B[i][j]);
    return true;
}

// Multiply two matrices.
bool mulMatrix(const FMatrix& A, const FMatrix& B,
               int rA, int cA, int rB, int cB, FMatrix& C) {
    if (cA != rB) return false;
    C.assign(rA, vector<Frac>(cB, {0, 1}));
    for (int i = 0; i < rA; i++)
        for (int j = 0; j < cB; j++) {
            Frac sum = {0, 1};
            for (int k = 0; k < cA; k++)
                sum = addFrac(sum, mulFrac(A[i][k], B[k][j]));
            C[i][j] = sum;
        }
    return true;
}

int main() {
    FMatrix A, B;
    int rA, cA, rB, cB;
    if (!readFracMatrix("matA.csv", A, rA, cA)) return 1;
    if (!readFracMatrix("matB.csv", B, rB, cB)) return 1;

    ofstream fout("result.csv");
    if (!fout) { cerr << "Error: cannot open result.csv\n"; return 1; }

    fout << "=== A+B ===\n";
    FMatrix C;
    if (addMatrix(A, B, rA, cA, rB, cB, C)) writeFMatrix(fout, C);
    else fout << "INCOMPATIBLE\n";

    fout << "=== A*B ===\n";
    FMatrix D;
    if (mulMatrix(A, B, rA, cA, rB, cB, D)) writeFMatrix(fout, D);
    else fout << "INCOMPATIBLE\n";

    cout << "Done. Results written to result.csv\n";
    return 0;
}
