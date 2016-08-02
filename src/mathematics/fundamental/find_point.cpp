#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T;
    int XP, YP, XQ, YQ;
    int XP2, YP2;
    cin >> T;
    while (T--) {
        cin >> XP >> YP >> XQ >> YQ;
        XP2 = 2 * XQ - XP;
        YP2 = 2 * YQ - YP;
        cout << XP2 << " " << YP2 << endl;
    }
    return 0;
}
