#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define ULL unsigned long long

using namespace std;

// at t:
// s1 = S1 / sqrt(2);
// s2 = S2 / sqrt(2);
// P1 = t * s1 + L
// P2 = t * s2;
// Q = (L+ s1*t - s2*t)^2
//   = L^2 + (s1-s2)^2 * t^2 + 2*(s1-s2)*t
//   = L^2 + (s1^2 + s2^2 -2*s1*s2) * t^2  + 2*(s1-s2)*L*t
// until P1 == P2, or L / (s2-s1) == t
int main() {
    ULL L, S1, S2;
    cin >> L >> S1 >> S2;
    double s1 = S1 / sqrt(2);
    double s2 = S2 / sqrt(2);
    ULL TEST;
    ULL T;
    double C1 = pow(s1,2) + pow(s2,2) - 2*s1*s2;
    double C2= 2 * (s1-s2) * L;
    double C3 = pow(L,2);
    cin >> TEST;
    while (TEST--) {
        cin >> T;
//        if (T > (L/(s2-s1))) {
  //          cout << 0 << endl;
   //     } else {
            double Q = C1 * pow(T,2) + C2 * T + C3;
            cout << Q << endl;
     //   }
    }
    return 1;
}
