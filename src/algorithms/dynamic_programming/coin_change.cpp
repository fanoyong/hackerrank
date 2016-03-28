#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define UNDEFINED -1
#define DEBUG 1

int top_down(int * C, int * D, int N, int M);
int bottom_up(int * C, int N, int M);

int main() {
    int N, M;
    int C[50];
    int D[251];
    int count = 0;
    cin >> N >> M;
    for (int i = 0; i<=250; i++) {
        D[i] = UNDEFINED;
    }
    for (int i = 0; i<M; i++) {
        cin >> C[i];
    }
    cout << top_down(C, D, N, M) << endl;
    #if DEBUG
        for(int i=1;i<=N;i++) {
            cout << "D[" << i << "]:" << D[i] << " ";
        }
        cout << endl;
    #endif
    return 0;
}

int top_down(int * C, int * D, int N, int M)
{
    if (N < 0) {
        #if DEBUG
            cout << "N:" << N << " M:" << M <<  " return 0" << endl;
        #endif
        return 0;
    }
    if (N == 0) {
        #if DEBUG
            cout << "N:" << N << " M:" << M <<  " return 1" << endl;
        #endif
        return 1;
    }
    if (UNDEFINED == D[N]) {
        D[N] = 0;
        for (int i = M-1 ; i>=0 ; i--) {
            D[N] += top_down(C, D, N-C[i], M);
        }
    }
    return D[N];
}

int bottom_up(int * C, int N, int M)
{

}

