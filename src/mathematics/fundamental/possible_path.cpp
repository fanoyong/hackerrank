#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define ULL unsigned long long

ULL GCD(ULL a, ULL b);

int main() {
    int T;
    unsigned long long a,b,x,y;
    cin >> T;
    while (T--) {
        cin >> a >> b >> x >> y;
        ULL d1 = GCD(x,y);
        ULL d2 = GCD(a,b);
        if (d1 == -1 || d2 == -1) {
            cout << "NO" << endl;
        } else if (d1 == d2) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 1;
}

ULL GCD(ULL a, ULL b) {
    while (a != b) {
        if (a < 0 || b < 0) {
            return -1;
        }
        if (a == 0) {
            return b;
        } else if (b == 0) {
            return a;
        }
        if (a > b) {
            a -= b;
        } else {
            b -= a;
        }
    }
    return a;
}

