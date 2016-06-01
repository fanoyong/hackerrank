#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define LL long long

using namespace std;


int main() {
    LL T, N, M, S;
    int x,y;
    LL data[1001][1001];
    cin >> T;
    while(T--) {
        for(int i=0; i<=1000; i++) {
            for(int j=0; j<=1000; j++) {
                data[i][j] = 100000;
            }
        }
        cin >> N >> M;
        for (int i=0; i<M; i++) {
            cin >> x >> y;
            data[x][y] = 1;
        }
        cin >> S;

// A B C
// A C

        for(int i=1;i<=N; i++) {
            for(int j=1; j<=N; j++) {
                for(int k=1; k<=N; k++) {
                    LL local = data[i][k] + data[k][j];
                    if (local < data[i][j]) {
                        data[i][j] = local;
                    }
                }
            }
        }

        for(int i=1;i<=N; i++) {
            if (i==S) {
                continue;
            }
            if (data[S][i] >= 100000) {
                data[S][i] = -1;
            }
            if (data[S][i] >= 0) {
                data[S][i]*=6;
            }
            cout << data[S][i] << " ";
        }
        cout << endl;
    }
    return 0;
}
