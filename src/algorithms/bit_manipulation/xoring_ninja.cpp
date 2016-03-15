#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

#define ULLT unsigned long long
#define DEBUG 0

int main() {
    int T;
    ULLT N;
    ULLT L = 1000000007ULL;
    ULLT DATA[100000];
    // fstream fin;
    // fin.open("input.txt",ios::in);
    cin >> T;
    while(T--) {
        cin >> N;
        #if DEBUG
            cout << "N=" << N << endl;
        #endif
        ULLT bit = 0;
        for(ULLT i=0; i<N; i++) {
            cin >> DATA[i];
            bit |= DATA[i];
        }
        bit %= L;
        #if DEBUG
            cout << "bit=" << bit << endl;
        #endif
        ULLT P = 1;
        for(ULLT i=0; i<N-1; i++) {
            P <<= 1;
            if (P > L) P %= L;
        }
        #if DEBUG
            cout << "P=" << P << endl;
        #endif
        ULLT sum = P*bit;
        sum %= L;
        #if DEBUG
            cout << "sum=" << sum << endl;
        #endif
        cout << sum << endl;
    }
    return 0;
}
