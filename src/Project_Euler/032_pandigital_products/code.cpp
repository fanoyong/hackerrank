#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#define LL long long
#define DEBUG 1

using namespace std;

LL is_pandigital(LL M1, LL M2, LL N, LL P);

int main() {
    LL input;
    cin >> input;
    LL l = pow(10,input);
#if DEBUG
    //cout << "limit: " << l << endl;
#endif
    LL P;
    LL count = 0;
    for (LL i=1; i<l; i++) {
        LL digit_i = (LL) log10(i) + 1;
        if (digit_i >= input) {
            break;
        }
        for (LL j=1; j<=l; j++) {
            LL digit_j = (LL) log10(j) + 1;
            if (digit_i + digit_j > input) {
                break;
            }
#if DEBUG
            // cout << "i / digit_i: " << i << " / " << digit_i << endl;
            // cout << "j / digit_j: " << j << " / " << digit_j << endl;
#endif
            P = i*j;
            LL digit_p = (LL) log10(P) + 1;
            if (digit_p  + digit_i + digit_j + 1 != input) {
                continue;
            }
            if (is_pandigital(i, j, input, P)) {
                count += P;
            }
        }
    }
    cout << count << endl;
    return 0;
}

LL is_pandigital(LL M1, LL M2, LL N, LL P) {
    int count[10] = {0,0,0,0,0,0,0,0,0,0};
    LL digit = (LL) log10(M1) + 1;
    for(LL i = 0; i < digit; i++) {
        int n = M1 % 10;
        count[n]++;
        M1 /= 10;
    }
    digit = (LL) log10(M2) + 1;
    for(LL i = 0; i < digit; i++) {
        int n = M2 % 10;
        count[n]++;
        M2 /= 10;
    }
    digit = (LL) log10(N) + 1;
    LL N2 = N;
    for(LL i = 0; i < digit; i++) {
        int n = N % 10;
        count[n]++;
        N /= 10;
    }
    for (int i = 0; i<N2; i++) {
        if (count[i] != 1) {
            return 0;
        }
    }
#if DEBUG
    cout << "i: " << M1 << " j: " << M2 << " P: " << P << endl;
#endif
    return 1;
}

