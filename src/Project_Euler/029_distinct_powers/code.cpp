#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define ULL unsigned long long

ULL get_answer(ULL N);

int main() {
    ULL N;
    cin >> N;
    cout << get_answer(N) << endl;
    return 0;
}

ULL get_answer(ULL N)
{
    ULL i, j, k, count, factor;
    ULL SUM = (N-1) * (N-1);
    for (i=2; i<=sqrt(N); i++) {
        for (j=2; j<=sqrt(N); j++) {
            k = pow (i,j);
            if (k > N) {
                continue;
            }
            // cout << "i=" << i << " j=" << j << " k=" << k << endl;
            factor = log(k)/log(i);
            count = (ULL)N/factor - 2/factor;
            SUM -= count;
        }
    }
    return SUM;
}
