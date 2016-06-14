#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define LL long long
#define debug 1
#define MOD 1000000007
using namespace std;

LL S[8] = {1,2,5,10,20,50,100,200};
LL solution[9][100001];

void generateAnswer();

int main() {
    for (LL i=0; i<=100000; i++)    {
        for (LL j=0;j<=8; j++) {
            solution[j][i] = 0;
        }
    }
    generateAnswer();
    LL T;
    cin >> T;
    while(T--) {
        LL N;
        cin >> N;
        LL answer = solution[8][N] % MOD;
        cout << (answer % MOD) << endl;
    }
    return 0;
}

void generateAnswer() {
    for (LL i=0; i<= 8; i++) {
        solution[i][0] = 1;
    }
    for (LL i=0; i<= 100000; i++) {
        solution[0][i] = 0;
    }
    cout << "start" << endl;
    for (LL j=1; j<= 100000; j++) {
        for (LL i=1; i<=8; i++) {
            if (S[i-1] <= j) {
                solution[i][j] = solution[i - 1][j] + solution[i][j - S[i-1]];
                solution[i][j] %= MOD;
            } else {
                solution[i][j] = solution[i - 1][j];
                solution[i][j] %= MOD;
            }
        }
    }
}
