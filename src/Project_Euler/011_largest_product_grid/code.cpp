#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int DATA[20][20];

long long get_largest();

int main()
{
    int i,j;
    for(i=0; i<20; i++) {
        for(j=0; j<20; j++) {
            cin >> DATA[i][j];
        }
    }
    cout << get_largest() << endl;
    return 0;
}


long long get_largest()
{
    int i, j;
    long long prod, max = -1;
    int a, b, c, d, sum, max_sum = 0;
    // Given constraint, we can simply find maximum of SUM with non-zeros.
    // Up - Down
    for (i=0; i<=16; i++) {
        for (j=0; j<20; j++) {
            a = DATA[i][j];
            b = DATA[i+1][j];
            c = DATA[i+2][j];
            d = DATA[i+3][j];
            if (a == 0 || b == 0 || c == 0 || d == 0) {
                continue;
            }
            sum = a+b+c+d;
            if (sum > max_sum) {
                max_sum = sum;
                prod = a*b*c*d;
                if (prod > max) {
                    max = prod;
                }
            }
        }
    }
    // Left - Right
    for (i=0; i<20; i++) {
        for (j=0; j<=16; j++) {
            a = DATA[i][j];
            b = DATA[i][j+1];
            c = DATA[i][j+2];
            d = DATA[i][j+3];
            if (a == 0 || b == 0 || c == 0 || d == 0) {
                continue;
            }
            sum = a+b+c+d;
            if (sum > max_sum) {
                max_sum = sum;
                prod = a*b*c*d;
                if (prod > max) {
                    max = prod;
                }
            }
        }
    }
    // Left Top - Right Down
    for(i=0; i<=16; i++) {
        for(j=0; j<=16; j++) {
            a = DATA[i][j];
            b = DATA[i+1][j+1];
            c = DATA[i+2][j+2];
            d = DATA[i+3][j+3];
            if (a == 0 || b == 0 || c == 0 || d == 0) {
                continue;
            }
            sum = a+b+c+d;
            if (sum > max_sum) {
                max_sum = sum;
                prod = a*b*c*d;
                if (prod > max) {
                    max = prod;
                }
            }
        }
    }
    // Right Top - Left Down
    for(i=0; i<=16; i++) {
        for(j=19; j>=3; j--) {
            a = DATA[i][j];
            b = DATA[i+1][j-1];
            c = DATA[i+2][j-2];
            d = DATA[i+3][j-3];
            if (a == 0 || b == 0 || c == 0 || d == 0) {
                continue;
            }
            sum = a+b+c+d;
            if (sum > max_sum) {
                max_sum = sum;
                prod = a*b*c*d;
                if (prod > max) {
                    max = prod;
                }
            }
        }
    }    
    return max;
}
