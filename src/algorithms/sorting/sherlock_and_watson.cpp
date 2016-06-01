#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define LL long long

int main() {
    LL n, k, q, r;
    cin >> n >> k >> q;
    vector<LL> arr(n);
    for (LL i=0; i<n; i++) {
        cin >> arr[i];
    }
    for(LL i=0; i<q; i++) {
        cin >> r;
        LL index = r-k;
        while (index < 0) {
            index += n;
        }
        cout << arr[index%n] << endl;
    }
    return 0;
}

