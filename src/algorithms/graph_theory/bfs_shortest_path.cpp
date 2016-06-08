#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define LL long long
#define DEBUG 0

using namespace std;
void print(LL N, LL **data);

int main() {
    LL T, N, M, S;
    LL x,y;
    LL ** data;
    data = new LL *[1001];
    for (LL i=0;i<=1000; i++) {
        data[i] = new LL[1001];
    }
    cin >> T;
    while(T--) {
        for(LL i=0; i<=1000; i++) {
            for(LL j=0; j<=1000; j++) {
                if (i==j) {
                    data[i][j] = 0;
                } else {
                    data[i][j] = -1;
                }
            }
        }
        cin >> N >> M;
        for (LL i=0; i<M; i++) {
            cin >> x >> y;
            data[x][y] = 1;
            data[y][x] = 1;
        }
        cin >> S;

// A B C
// A C
        for(LL i=1;i<=N; i++) {
#if DEBUG
            print(N, data);
#endif
            for(LL j=1; j<=N; j++) {
                if (i==j) {
                    continue;
                }
                for(LL k=1; k<=N; k++) {
                    if (i==k || j==k) {
                        continue;
                    }
                    if (data[i][k] < 0 || data[k][j] < 0) {
                        continue;
                    }
                    LL local = data[i][k] + data[k][j];
                    if (data[i][j] < 0) {
                        data[i][j] = local;
                    } else if (local < data[i][j]) {
                        data[i][j] = local;
                    }
                }
            }
        }

        for(LL i=1;i<=N; i++) {
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

void print(LL N, LL **data) {
    cout << endl;
    for (LL i=1; i<=N; i++) {
        for (LL j=1; j<=i; j++) {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
