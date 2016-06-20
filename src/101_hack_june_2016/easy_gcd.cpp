#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>

#define DEBUG 1
#define LL long long

using namespace std;


int is_prime(LL n) {
    if (n==2 || n==3) {
#if DEBUG
        cout << "either 2 or 3" << endl;
#endif
        return 1;
    }
    if ((n&1) != 1) {
#if DEBUG
        cout << "even" << endl;
#endif
        return 0;
    }
    for (LL i=3;i<= sqrt(n); i+=2) {
        if (n%i == 0) {
#if DEBUG
        cout << "not prime" << endl;
#endif
            return 0;
        }
    }
    return 1;
}

int main(){
    LL n;
    LL k;
    cin >> n >> k;
    LL A[n+1];
    for (LL i=1; i<=n; i++) {
       cin >> A[i];
    }

#if DEBUG
    cout << "n / k: " << n << " / " << k << endl;
#endif

    int k_limit = k;
    for (LL i=n; i>=2; i--) {
        if (is_prime(A[i])) {
            if (A[i] > k) {
                cout << "0" << endl;
                return 0;
            } else {
                k_limit = A[i];
            }
        }
    }
#if DEBUG
    cout << "k_limite:" << k_limit << endl;
#endif
    int flag = 1;
    for (LL i=k_limit; i>=1; i--) {
        flag = 1;
        for (LL j=1; j<=n; j++) {
            if (A[j] % i != 0) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            flag = i;
            break;
        }
    }
    if (flag) {
    } else {
    }
    cout << 0 << endl;
    return 0;
}

