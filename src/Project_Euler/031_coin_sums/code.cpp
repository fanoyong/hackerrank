#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define LL long long
#define debug 1
#define MOD 1000000007
using namespace std;

const int M = 8;
int S[M] = {1,2,5,10,20,50,100,200};

/*

1: 1
2: (1 + (2-1)) / 2  = 2
3: 1-1-1 / 1-2 = 2
4: 2-(4-2) / 1-(4-1) => 2-2 / 2-1-1 / 1-1-1-1 / 1-1-2 / = 2+1 = 3








*/

int main() {
    int T;
    cin >> T;
    while(T--) {
        LL answer = 0;    
        cout << (answer % MOD) << endl;
    }
    return 0;
}

