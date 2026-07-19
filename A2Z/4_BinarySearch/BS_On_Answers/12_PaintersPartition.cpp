#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

const int MOD = 10000003;

// Returns the number of painters needed if
// one painter can paint at most maxBoards units.
int cntPainters(vector<int>& boards, long long maxBoards) {
    int painters = 1;
    long long currSum = 0;

    for (int board : boards) {
        if (currSum + board <= maxBoards) {
            currSum += board;
        }
        else {
            painters++;
            currSum = board;
        }
    }

    return painters;
}

// ---------------- BRUTE FORCE ----------------

int paintBrute(int A, int B, vector<int>& boards) {
    long long l = *max_element(boards.begin(), boards.end());
    long long h = accumulate(boards.begin(), boards.end(), 0LL);

    for (long long maxBoards = l; maxBoards <= h; maxBoards++) {
        if (cntPainters(boards, maxBoards) <= A) {
            return (int)((maxBoards * B) % MOD);
        }
    }

    return -1;
}

// ---------------- OPTIMAL ----------------

int paintOptimal(int A, int B, vector<int>& boards) {
    long long l = *max_element(boards.begin(), boards.end());
    long long h = accumulate(boards.begin(), boards.end(), 0LL);

    while (l <= h) {
        long long mid = l + (h - l) / 2;

        if (cntPainters(boards, mid) > A) {
            l = mid + 1;
        }
        else {
            h = mid - 1;
        }
    }

    return (int)((l * B) % MOD);
}

int main() {
    int A; // number of painters
    int B; // time per unit board

    cin >> A >> B;

    int N;
    cin >> N;

    vector<int> boards(N);

    for (int i = 0; i < N; i++) {
        cin >> boards[i];
    }

    cout << "Brute Force Answer : "
         << paintBrute(A, B, boards) << "\n";

    cout << "Optimal Answer     : "
         << paintOptimal(A, B, boards) << "\n";

    return 0;
}
