#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

unsigned long long get_largest_prime_factor(unsigned long long N);

int main() {
    int T;
    unsigned long long N;
    cin >> T;
    while(T--)
    {
        cin >> N;
        cout << get_largest_prime_factor(N) << endl;
    }
    return 0;
}

unsigned long long get_largest_prime_factor(unsigned long long N)
{
    unsigned long long i, P=-1, Q=-1;
    for(i=2; i<=(unsigned long long)N/(i-1); i++)
    {
        if (N%i == 0)
        {
            P = i;
            Q = N/i;
            if (Q > P)
            {
                return get_largest_prime_factor(N/P);
            }
            else
            {
                return get_largest_prime_factor(N/Q);
            }
            
        }
    }
    if (P<0 || P>N)
    {
        P = N;
    }
    return P;
}
