#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#define LL long long
#define DEBUG 0

using namespace std;

int is_pandigital(int M1, int M2, int N);

int main() {
    int input;
    cin >> input;
    LL l = pow(10,input);
    LL P;
    int count = 0;
    for (LL i=1; i<=l; i++) {
        for (LL j=1; j<=l/i; j++) {
            P = i*j;
            if ((int) log10(P) +1  + (int) log10(i) + 1 + (int) log10(j) + 1 != input) {
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

int is_pandigital(int M1, int M2, int N) {
    int digit[10];
    for (int i=0;i<10; i++) {
        digit[i] = 0;
    }
    LL l = (int) log10(N) +1  + (int) log10(M1) + 1 + (int) log10(M2) + 1;
#if DEBUG
    cout << "l: " << l << endl;
    cout << endl;
    for (int i=0;i<10; i++) {
        cout << digit[i] << " ";
    }
    cout << endl;
    cout << "M1 / M2 / N: " << M1 << " / " << M2 << " / " << N << endl;
#endif
    int data = M1;
    for (int i=0; i < log10(M1)+1; i++) {
        int d = data%10;
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
    for (int i=0; i < log10(M2)+1; i++) {
        int d = data%10;
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
    for (int i=0; i < log10(M2)+1; i++) {
        int d = data%10;
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
    for (int i=0;i<10; i++) {
        cout << digit[i] << " ";
    }
    cout << endl;
#endif
    for (int i=1; i<= l; i++) {
        if (digit[i] != 1) {
            return 0;
        }
    }
    return 1;
}

