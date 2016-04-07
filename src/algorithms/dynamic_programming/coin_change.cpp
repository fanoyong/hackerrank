#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define DEBUG 1

int bottom_up(int * C, int N, int M);

int main() {
    int N, M;
    int C[51];
    int count = 0;
    cin >> N >> M;
    for (int i=1; i<=M; i++) {
        cin >> C[i];
    }
    int answer = bottom_up(C, N, M);
    cout << answer << endl;
    return 0;
}

int bottom_up(int * C, int N, int M) {
    int table[N+1][M];
    // Fill the enteries for 0 value case (n = 0)
    for (int i=0; i<M; i++) {
        table[0][i] = 1;
    }
    // Fill rest of the table enteries in bottom up manner  
    for (int i = 1; i < N+1; i++) {
        for (int j = 0; j < M; j++) {
            // Count of solutions including S[j]
            int x = (i-C[j] >= 0)? table[i - C[j]][j]: 0;
            // Count of solutions excluding S[j]
            int y = (j >= 1)? table[i][j-1]: 0;
            // total count
            table[i][j] = x + y;
        }
    }
    return table[N][M-1];
}

