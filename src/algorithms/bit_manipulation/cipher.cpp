#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define LL long long
#define DEBUG 0
/*

7 4 1110100110
1001010   
 1001010  
  1001010 
   1001010
----------
1110100110 (7,4,10)

1:1 s=1
1: c 1 s 1 => 0
1: c 1 s 1 => 0
0: c 0 s 1 => 1 => s=0 a 1 => s 1
1: c 1 s 1 => 0 => s=1 a 0 => s 1
0: c 0 s 1 => 1 => s=0 a 0 => s 0
0: c 0 s 0 => 0 => end


6 2
1110001

101111
 101111
-------
1110001


1:1 s=1
1: c 1 s 1 => 0 => s 1 a 1 => s=0
1: c 1 s 0 => 1 => s 1 a 0 => s=1
0: c 0 s 1 => 1 => s 0 a 1 => s=1
0: c 0 s 1 => 1 => s 0 a 1 => s=1
0



6 2
1110001

*/

char * decode(char * s, LL N, LL K);
char * decode_better(char * s, LL N, LL K);

int main()
{
    LL N, K;
    cin >> N >> K;
    char S[(N+K)];
    cin >> S;
    // cout << decode(S, N, K) << endl;
    cout << decode_better(S, N, K) << endl;
    return 0;
}

char * decode(char * s, LL N, LL K)
{
    LL i, j;
    char *A = (char *) malloc(sizeof(char) * (N+1));
    #if DEBUG
        cout << "S=" << s << " N=" << N << " K=" << K << endl;
    #endif
    A[0] = s[0];
    #if DEBUG
        cout << "S[0]=" << A[0] << endl;
    #endif
    for(i=1; i<N; i++) {
        LL c = s[i] - '0';
        #if DEBUG
            cout << "S["<< i << "]=" << s[i] << " c:" << c << endl;
        #endif
        for(j=i-1;j>i-K; j--) {
            if (j < 0) {
                continue;
            }
            c = (c^(A[j]-'0'));
            #if DEBUG
                cout << "S^[" << j << "]=" << A[j] << " c:" << c << endl;
            #endif
        }
        A[i] = c + '0';
        #if DEBUG
            cout << "A:" <<  A << endl;
        #endif
    }
    A[N] = '\0';
    return A;
}

char * decode_better(char * input, LL N, LL K)
{
    LL i, j;
    LL start = 1;
    char * A = (char *) malloc(sizeof(char) * (N+1));
    A[0] = input[0];
    int S, C;
    C = A[0] - '0';
    S = A[0] - '0';
    while (start < N-1) {
        C = input[start] - '0';
        #if DEBUG
            cout << "start:" << start << "C:" << C << " S:" << S << " C^S:" << (C^S) << endl;
        #endif
        int next = (C^S);
        A[start] = next + '0';
        if (next) {
            #if DEBUG
                cout << "S updated to 1"  << endl;
            #endif
            if (S) {
                S = 0;
            } else {
                S = 1;
            }
        }
        if (start >= K-1) {
            int old = A[start-K+1] - '0';
            #if DEBUG
                cout << "start:" << (start) << " A[start-(K-1)]:" << old << endl;
            #endif
            S = (S^old);
        }
        start++;
    }
    A[N-1] = input[N+K-2];
    A[N] = '\0';
    return A;
}
