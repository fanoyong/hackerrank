#include <cmath>
#include <cstdio>
#include <climits>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int C;
int ORIGINAL[6];

int isPositive();

int main() {
    int i,j;
    int answer = -1;
    cin >> ORIGINAL[0] >> ORIGINAL[1]  >> ORIGINAL[2];
    cin >> ORIGINAL[3] >> ORIGINAL[4]  >> ORIGINAL[5];
    C = INT_MAX;
    int flag = 0;
    if (isPositive()) {
        cout << 0 << endl;
        return 0;
    }
    for(i=1;i<=120;i++) {
        for(j=0;j<6;j++) {
            ORIGINAL[j] += i;
            if (i <= C && isPositive()) {
                // cout << "updated:" << i << endl;
                flag = 1;
                C = i;
                break;
            }
            ORIGINAL[j] -= i;
        }
    }
    
    if (flag == 0) {
        answer = -1;
    } else {
        answer = C;
    }
    cout << answer << endl;
    return 0;
}

/*
* C1: a + b + c + d
* C2: a + e + d
* C3: b+ f+ a
* 
*/
int isPositive()
{
    int a = ORIGINAL[0];
    int b = ORIGINAL[1];
    int c = ORIGINAL[2];
    int d = ORIGINAL[3];
    int e = ORIGINAL[4];
    int f = ORIGINAL[5];
    int C1 = a+b+c+d;
    int C2 = a+d+e;
    int C3 = a+b+f;
    // cout << "C1:" << C1 << " C2:" << C2 << " C3:" << C3 << endl;
    return (C1 >= 0) && (C2 >= 0) && (C3 >= 0);
}
