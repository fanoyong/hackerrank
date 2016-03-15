#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define UL unsigned long
#define DEBUG 0

/*

0  0000

1   0001

2   0010
3   0011

4   0100
5   0101
6   0110
7   0111

8   1000
9   1001
10  1010
11  1011
12  1100
13  1101
14  1110
15  1111

16 10000
17 10001
18 10010
19 10011
20 10100
21 10101
22 10110
23 10111

24 11000
25 11001
26 11010
27 11011
28 11100
29 11101
30 11110
31 11111



*/


int main() {
    int T;
    UL N1, N2, F, i;
    cin >> T;
    while (T--) {
        cin >> N1 >> N2;
        F = 1;
        while (F < N2) {
            F <<= 1;
        }
        F >>= 1;
        if (N1 < F && N2 > F) {
            #if DEBUG
                cout << "Threshold:" << F << endl;
            #endif
            cout << 0 << endl;
        } else if (N2 - N1 > 100000UL) {
            UL AP = N1;
            for(i = N1+1; i<=N2; i++) {
                AP = (AP & i);
                #if DEBUG
                    cout << "i=" << i << " AP:" << AP << endl;
                #endif
            }
            cout <<  AP << endl;
        } else {
            if ((N2 - N1) > (F>>1)) {
                cout << F << endl;
            } else {
                cout << F << endl;
            }
        }
    }
    return 0;
}

