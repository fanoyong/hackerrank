#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#define LL long long
#define DEBUG 0

using namespace std;

int is_pandigital(LL M1, LL M2, LL P);
int N;

int main() {
    cin >> N;
    LL M1, M2, P;
    LL count = 0;
    LL i, j;
    int DM1, DM2, DP;
    for(i=1;;i++) {
        M1 = i;
        DM1 = log10(i) + 1;
        #if DEBUG
            cout << "M1: " << M1 << endl;
            cout << "M1 digit: " << DM1 << endl;
        #endif
        if (DM1 >= N-2) {
            break;
        }
        for(j=i+1;;j++) {
            M2 = j;
            DM2 = log10(j) + 1;
            #if DEBUG
                cout << "M2: " << M2 << endl;
                cout << "M2 digit: " << DM2 << endl;
            #endif
            if (DM1 + DM2 >= N-1) {
                break;
            }
            P = M1 * M2;
            DP = log10(P) + 1;
            #if DEBUG
                cout << "P: " << P << endl;
                cout << "P digit: " << DP << endl;
            #endif
            if (DM1 + DM2 + DP != N) {
                continue;
            }
            if (is_pandigital(M1, M2, P)) {
                count += P;
            }
        }
    }
    cout << count << endl;
}

int is_pandigital(LL M1, LL M2, LL P) {
    int *digit = (int *)calloc(10, sizeof(int));
    #if DEBUG
        cout << "M1: " << M1 << " M2: " << M2 << " P: " << P << endl;
    #endif
    while (M1 > 0) {
        int cur = M1%10;
        if (cur > N || cur == 0) {
            return 0;
        }
        digit[cur]++;
        if (digit[cur] > 1) {
            return 0;
        }
        M1 /= 10;
    }

    while (M2 > 0) {
        int cur = M2%10;
        if (cur > N || cur == 0) {
            return 0;
        }
        digit[cur]++;
        if (digit[cur] > 1) {
            return 0;
        }
        M2 /= 10;
    }

    while (P > 0) {
        int cur = P%10;
        if (cur > N || cur == 0) {
            return 0;
        }
        digit[cur]++;
        if (digit[cur] > 1) {
            return 0;
        }
        P /= 10;
    }

    for (int i=1; i<N; i++) {
        if (digit[i] != 1) {
            return 0;
        }
    }
    return 1;
}
