#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define LL long long
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

LL divide(LL N1, LL N2);
LL bitwise(LL N1, LL N2);

int main() {
    int T;
    LL N1, N2;
    cin >> T;
    while (T--) {
        cin >> N1 >> N2;
        // cout << divide(N1, N2) << endl;
        cout << bitwise(N1, N2) << endl;
    }
    return 0;
}

LL divide(LL N1, LL N2)
{
    LL F, i;
    F = 1;
    while (F < N2) {
        F <<= 1;
    }
    F >>= 1;
    LL F2 = F>>1;
    LL index = F + F2;
    if (N2 < 1) {
        LL AP = N1;
        for (i=N1+1; i<=N2; i++) {
            AP &= i;
        }
        return AP;
    } else if (N1 < F && N2 > F) {
        #if DEBUG
            cout << "CASE 1:" << F << endl;
        #endif
        return 0;
    } else if((N1-index) * (N2-index) < 0) {
        #if DEBUG
            cout << "CASE 2 F2:" << F2 << "index:" << index << endl;
        #endif
        return (index - F2);
    } else if (N1 == index) {
        return index;
    } else if (N2 == index) {
        return (index - F2);
    } else {
        #if DEBUG
            cout << "CASE 3 F2:" << F2 << "index:" << index << endl;
        #endif
        LL flag = 0;
        while ((N1-index) * (N2-index) > 0) {
            F2 >>= 1;
            if(N2 < index) {
                index -= F2;
            } else {
                index += F2;
            }
            #if DEBUG
                cout << "F2:" << F2 << endl;
                cout << "index:" << index << endl;
            #endif
        }
        return index;
    }
}
LL bitwise(LL N1, LL N2)
{
    int LLS = (sizeof(LL) * 4 - 1);
    LL mask = 1 << LLS;
    LL AP = 0;
    #if DEBUG
        cout << "LLS:" << LLS << endl;
    #endif
    for(int i = LLS; i >=0; i--) {
        if ((N1&mask) == (N2&mask)) {
            AP |= (N1&mask);
        }
        mask >>= 1;
        #if DEBUG
            cout << "i:" << i << endl;
            cout << "N1&mask:" << ((N1&mask)>>mask) << endl;
            cout << "mask:" << mask << endl;
        #endif
    }
    return AP;
}

