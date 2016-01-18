#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void get_largest_prime_factor(unsigned long long N);
unsigned long long MAX_PF = 0;

int main() {
    int T;
    unsigned long long N;
    cin >> T;
    while(T--)
    {
        cin >> N;
        get_largest_prime_factor(N);
        cout << MAX_PF << endl;
    }
    return 0;
}

void get_largest_prime_factor(unsigned long long N)
{
    unsigned long long i, P=0, Q=0;
    for(i=2; i<=(unsigned long long)N/(i-1); i++)
    {
        if (N%i == 0)
        {
            P = i;
            Q = N/i;
            return get_largest_prime_factor(Q);
        }
    }
    if (P<=0 || P>=N)
    {
        P = N;
        if (P > MAX_PF)
        {
            MAX_PF = P;
        }
    }
}
