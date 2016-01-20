#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int bruteforce(int N);
int betterway(int N);
int muchbetterway(int N);

int main() {
    int T, N;
    
    cin >> T;
    while (T--)
    {
        cin >> N;
        // cout << bruteforce(N) << endl;
        // cout << betterway(N) << endl;
        cout << muchbetterway(N) << endl;
    }
    return 0;
}

int bruteforce(int N)
{
    int a, b, c, ap, bp, cp;
    int max = -1;
    for(a=1; a<=N-2; a++)
    {
        ap = pow(a,2);
        for(b=a+1; b<=N-1-a; b++)
        {
            bp = pow(b,2);
            for(c=b+1; c<=N-a-b; c++)
            {
                // cout << "a:" << a << " b:" << b << " c:" << c << endl;
                cp = pow(c,2);
                if(ap + bp == cp)
                {
                    if (a*b*c > max)
                    {
                        max = a*b*c;
                    }
                }
            }
        }
    }
    return max;
}

int betterway(int N)
{
    int i, j, k, ap, bp, cp;
    int max = -1, local_max;
    // c = N - a - b
    for(i=1; i<N-2; i++) {
        ap = i*i;
        for(j=i+1; j<N-1; j++) {
            bp = j*j;
            k = N - i - j;
            cp = k*k;
            if(ap + bp == cp)
            {
                local_max = i*j*k;
                if (local_max > max)
                {
                    max = local_max;
                }
            }
        }
    }
    return max;
}

int muchbetterway(int N)
{
    // c = N - a - b
    // c^2 = a^2 + b^2
    // c^2 = N^2 + a^2 + b^2 +2ab - 2(Na+ Nb) = a^2 + b^2
    // N^2 +2ab -2Na -2Nb = 0;
    // b = 2Na - N^2 / 2* (a-N)
    int max=-1, local_max;
    int i, j, k, ap, bp , cp;
    for(i=1; i<N-2; i++) {
        j = (2*N*i - N*N / (2*(i-N)));
        k = N - i - j;
        ap = i*i;
        bp = j*j;
        cp = k*k;
        local_max = i*j*k;
        if (local_max > max)
        {
            max = local_max;
        }
    }
    return max;
}
