#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define LL long long
#define DEBUG 0
/*
1001010   
 1001010  
  1001010 
   1001010
    
1110100110 (7,4,10)

1 => 1 => s=1
1 => c 1 s 1 => 0
1 => c 1 s 1 => 0
0 => c 0 s 1 => 1 => s=0 -> A[4-4] => s=1
1 => c 1 s 1 => 0 => s-A[5-4] => s=1
0 => c 0 s 1 => 1 => s=0 => S[6-4] => s=0
0 => c 0 s 0 -> 0

A[0] = S[0]
A[1] = S[1] ^ A[0] = S[1] ^ S[0]
A[2] = S[2] ^ A[1] ^ A[0] = S[2] ^ S[1] ^ S[0] ^ S[0]  =  S[2] ^ S[1]
A[3] = S[3] ^ A[2] ^ A[1] ^ A[0] = S[3] ^ S[2] ^ S[1] ^ S[0] ^ S[0] ^ S[1] ^ S[0] ^ S[0] = S[3] ^ S[2]
A[4] = S[4] ^ A[3] ^ A[2] ^ A[1] = S[4] ^ S[3] ^ S[2] ^ S[1] ^ S[0] ^ S[0] ^ S[1] ^ S[0] ^ S[0] S[2] ^ S[1] ^ S[0] ^ S[0] ^ S[1] ^ S[0] = S[4] ^ S[3]  ^ S[0]
A[5] = S[5] ^ A[4] ^ A[3] ^ A[2] = S[5] ^ S[4] ^ S[0] ^ S[1]

101
 101
  101
   101
    101

1100011 (3,5,7)

10111
 10111
  10111
1100101

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
            cout << "B:" << (C^S) << endl;
        #endif
        A[start++] = (C^S) + '0';
        if ((C^S)) {
            S = 0;
        }
        if (start >= K && (A[start-K] - '0') > 0) {
            #if DEBUG
                cout << "flip S" << endl;
            #endif
            if (S) {
                S = 0;
            } else {
                S = 1;
            }
        }
    }
    A[N-1] = input[N+K-2];
    A[N] = '\0';
    return A;
}
