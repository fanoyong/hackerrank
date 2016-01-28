#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int is_prime(unsigned long long N);

int main() {
    int T;
    unsigned long long N;
    cin >> T;
    while(T--) {
        cin >> N;
        if(is_prime(N)) {
            cout << "Prime" << endl;
        } else {
            cout << "Not prime" << endl;
        }
    }
    return 0;
}

int is_prime(unsigned long long N)
{
    unsigned long long i;

    if(N<2) return 0;

    if(!(N&1) && N>2) return 0;

    for(i=3; i<=sqrt(N); i+=2) {
        if((N%i) == 0) return 0;
    }
    return 1;
}
