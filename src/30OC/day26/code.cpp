#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int D1, D2, M1, M2, Y1, Y2;
    cin >> D1 >> M1 >> Y1;
    cin >> D2 >> M2 >> Y2;
    int fine;
    if (Y1 > Y2) {
        fine = 10000;
    } else if (Y1 < Y2) {
        fine = 0;
    } else {
        if(M1 > M2) {
            fine = 500 * (M1-M2);
        } else if (M1 < M2) {
            fine = 0;
        } else {
            if (D1 <= D2) {
                fine = 0;
            } else {
                fine = 15 * (D1-D2);
            }
        }
    }
    cout << fine << endl;
    return 0;
}

