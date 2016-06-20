#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#define LL long long
#define DEBUG 0

using namespace std;

LL is_pandigital(LL M1, LL M2, LL N);

int main() {
    LL input;
    cin >> input;
    LL l = pow(10,input);
    LL P;
    LL count = 0;
    for (LL i=1; i<=l; i++) {
        LL digit_i = (LL) log10(i) + 1;
        if (digit_i >= input) {
            break;
        }
        for (LL j=i; j<=l/i; j++) {
            LL digit_j = (LL) log10(j) + 1;
            if (digit_i + digit_j >= input) {
                break;
            }
            P = i*j;
            LL digit_p = (LL) log10(P) + 1;
            if (digit_p  + digit_i + digit_j + 1 != input) {
                continue;
            }
            if (is_pandigital(i, j, P)) {
                count += P;
            }
        }
    }
    cout << count << endl;
    return 0;
}

LL is_pandigital(LL M1, LL M2, LL N) {
    LL digit[10];
    for (LL i=0;i<10; i++) {
        digit[i] = 0;
    }
    LL l = (LL) log10(N) +1  + (LL) log10(M1) + 1 + (LL) log10(M2) + 1;
#if DEBUG
    cout << "l: " << l << endl;
    cout << endl;
    for (LL i=0;i<10; i++) {
        cout << digit[i] << " ";
    }
    cout << endl;
    cout << "M1 / M2 / N: " << M1 << " / " << M2 << " / " << N << endl;
#endif
    LL data = M1;
    for (LL i=0; i < log10(M1)+1; i++) {
        LL d = data%10;
#if DEBUG
        cout << "d: " << d << endl;
#endif
        if (d == 0 || d > l) {
            return 0;
        }
        digit[d]++;
        if (digit[d] > 1) {
            return 0;
        }
        data /= 10;
        if (data == 0) {
            break;
        }
    }
#if DEBUG
    cout << "checkpoint 1" << endl;
#endif
    data = M2;
    for (LL i=0; i < log10(M2)+1; i++) {
        LL d = data%10;
        if (d == 0 || d > l) {
            return 0;
        }
        digit[d]++;
        if (digit[d] > 1) {
            return 0;
        }
        data /= 10;
        if (data == 0) {
            break;
        }
    }
#if DEBUG
    cout << "checkpoint 2" << endl;
#endif
    data = N;
    for (LL i=0; i < log10(M2)+1; i++) {
        LL d = data%10;
        if (d == 0 || d > l) {
            return 0;
        }
        digit[d]++;
        if (digit[d] > 1) {
            return 0;
        }
        data /= 10;
        if (data == 0) {
            break;
        }
    }
#if DEBUG
    cout << "checkpoint 3" << endl;
    for (LL i=0;i<10; i++) {
        cout << digit[i] << " ";
    }
    cout << endl;
#endif
    for (LL i=1; i<= l; i++) {
        if (digit[i] != 1) {
            return 0;
        }
    }
    return 1;
}

