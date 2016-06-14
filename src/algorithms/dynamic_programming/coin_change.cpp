#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define LL long long
#define debug 1
#define MOD 1000000007
int N, M;
int C[51];
LL solution[51][251];

void generateAnswer();

int main() {
    cin >> N >> M;
    for (int i=0; i<M; i++) {
        cin >> C[i];
    }
    generateAnswer();
    LL answer = solution[M][N] % MOD;
    cout << (answer % MOD) << endl;
    return 0;
}

void generateAnswer() {
    for (LL i=0; i<= M; i++) {
        solution[i][0] = 1;
    }
    for (LL i=0; i<= N; i++) {
        solution[0][i] = 0;
    }
    for (LL j=1; j<= N; j++) {
        for (LL i=1; i<=M; i++) {
            if (C[i-1] <= j) {
                solution[i][j] = solution[i - 1][j] + solution[i][j - C[i-1]];
                solution[i][j] %= MOD;
            } else {
                solution[i][j] = solution[i - 1][j];
                solution[i][j] %= MOD;
            }
        }
    }
}
