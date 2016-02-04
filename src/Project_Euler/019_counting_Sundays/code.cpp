#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int is_sunday(long long count);
long long get_count(long long y, long long m, long long d);
long long calculate();
long long dayofweek(long long y, long long m, long long d);

int DAYS[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
long long Y1, Y2, M1, M2, D1, D2;

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> Y1 >> M1 >> D1;
        cin >> Y2 >> M2 >> D2;
        cout << calculate() << endl;
    }
    return 0;
}


int is_sunday(long long count)
{
    // Let Jan 1 1900 is 0. 
    return (count % 7 == 0 );
}

long long get_count(long long y, long long m, long long d)
{
    long long i,j;
    long long count = 0;
    if ((y%4==0 && y%100 != 0) || (y%400 == 0)) {
        DAYS[1] = 29;
    } else {
        DAYS[1] = 28;
    }
    for(i=1900; i<=y; i++) {
        for(j=1; j<=12; j++) {
            count += DAYS[j];
        }
    }
    for(j=m; j<=12; j++) {
        count -= DAYS[j];
    }
    count -= (DAYS[m] - d);
    return count;
}


long long dayofweek(long long y, long long m, long long d)	/* 1 <= m <= 12,  y > 1752 (in the U.K.) */
{
    static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    y -= m < 3;
    return (y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
}

long long calculate()
{
    long long i,j;
    long long count = 0;
    if (D1 != 1) {
        if (M1++ > 12) {
            Y1++;
        }
        D1 = 1;
    }
    if (Y1 >= Y2) {
        for(i=M1; i<=M2; i++) {
            if (!dayofweek(Y2,i,1)) count++;
        }
    } else if (Y1 + 1 == Y2) {
        for(i=M1; i<=12; i++) {
            if (!dayofweek(Y1, i, 1)) count++;
        }
        for(i=1; i<=M2; i++) {
            if (!dayofweek(Y2, i, 1)) count++;
        }
    } else {
        for(i=M1; i<=12; i++) {
            if (!dayofweek(Y1, i, 1)) count++;
        }
        Y1++;
        for(i=1; i<=M2; i++) {
            if (!dayofweek(Y2, i, 1)) count++;
        }
        Y2--;
        for(i=Y1; i<=Y2; i++) {
            for(j=1; j<=12; j++) {
                if (!dayofweek(i, j, 1)) count++;
            }
        }
    }
    return count;
}
