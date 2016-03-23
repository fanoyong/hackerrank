#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#define LL long long
#define DEBUG 0

using namespace std;

void get_answer(LL * arr, LL n);

int main() {
    LL T;
    LL arr[100000];
    cin >> T;
    while (T--) {
        LL n;
        cin >> n;
        for (LL i = 0; i<n; i++) {
            cin >> arr[i];
        }
        get_answer(arr, n);
    }
    return 0;
}

void get_answer(LL * arr, LL n)
{
    LL local = arr[0], c_sum = arr[0], nc_sum = 0, max = -10000, i;
    if (arr[0] > 0) {
        nc_sum += arr[0];
    }
    if (arr[0] > max) {
        max = arr[0];
    }
    
    for(i=1; i<n; i++) {
        #if DEBUG
            cout << "a[" << i << "]:" << arr[i] << endl;
        #endif
        if(arr[i] > 0) {
            nc_sum += arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
        if(local + arr[i] > arr[i]) {
            local += arr[i];
        } else {
            local = arr[i];
        }
        if(local > c_sum) {
            c_sum = local;
        }
        #if DEBUG
            cout << "c_sum:" << c_sum << "nc_sum:" << nc_sum << " max:" << max << endl;
        #endif
    }
    if (nc_sum < max || (max != 0 && nc_sum == 0)) {
        nc_sum = max;
    }
    cout << c_sum << " " << nc_sum << endl;
}
