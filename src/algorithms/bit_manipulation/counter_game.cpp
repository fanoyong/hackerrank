#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define ULL unsigned long long

int main() {
    ULL N, B;
    int T;
    cin >> T;
    while (T--) {
        cin >> N;
        int who = 1;
        while (N!=1) {
            if(who) {
                who--;
            }  else {
                who++;
            }
            if (N && !(N-1 & N)) {
                N >>= 1; 
            } else {
                B = 1;
                B <<= 63;
                while (N < B) {
                    B >>= 1;
                }
                N -= B;
            }
        }
        if (who) {
            cout << "Richard" << endl;
        } else {
            cout << "Louise" << endl;
        }
    }
    return 0;
}

