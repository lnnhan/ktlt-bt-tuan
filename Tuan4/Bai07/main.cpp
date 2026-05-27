// ============================================================
// Tuan 4 - Bai 7: Kadane voi nhieu bo test
// Doc file multi_test.txt gom T bo test.
// Moi bo: dong dau la n, dong sau la n so nguyen.
// Voi moi bo, in max subarray sum tren 1 dong.
// Dam bao khong crash khi n=0 (in 'EMPTY').
// ============================================================
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// Kadane's algorithm on a vector. Returns max subarray sum.
long long kadane(const vector<int>& arr) {
    long long bestEnding = arr[0], bestSoFar = arr[0];
    for (int i = 1; i < static_cast<int>(arr.size()); i++) {
        bestEnding = (arr[i] > bestEnding + arr[i]) ? arr[i] : bestEnding + arr[i];
        if (bestEnding > bestSoFar) bestSoFar = bestEnding;
    }
    return bestSoFar;
}

int main() {
    ifstream fin("multi_test.txt");
    if (!fin) {
        cerr << "Error: cannot open multi_test.txt\n";
        return 1;
    }

    int T;
    fin >> T;

    for (int t = 0; t < T; t++) {
        int n;
        fin >> n;
        if (n == 0) {
            cout << "EMPTY\n";
            continue;
        }
        vector<int> arr(n);
        for (int i = 0; i < n; i++) fin >> arr[i];
        cout << kadane(arr) << "\n";
    }
    return 0;
}
