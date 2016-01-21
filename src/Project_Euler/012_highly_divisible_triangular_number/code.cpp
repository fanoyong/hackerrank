#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int generate_data_better(int target);

int main() {
    int i, T, N, index;
    cin >> T;
    while (T--) {
        cin >> N;
        cout << generate_data_better(N) << endl;
    }
    return 0;
}

int generate_data_better(int target)
{
    int i=0, j, n, cnt, sum, l;
    if (target == 1) return 1;
    if (target == 2) return 2;
    while(1) {
        cnt = 0;
        sum = 0;
        n = (i+1) * i / 2;
        l = sqrt(i);
        for(j=1;j<=l; j++) {
            if(n%j == 0) cnt++;
            if(j==l) sum--;
        }
        sum += 2*cnt;
        i++;
        if (sum > target) return i;
    }
}
