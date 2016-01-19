#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int bruteforce(int N);
int betterway(int N);

int main() {
    int T, N;
    
    cin >> T;
    while (T--)
    {
        cin >> N;
        // cout << bruteforce(N) << endl;
        cout << betterway(N) << endl;
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

int betterwary(int N)
{
    int i, local_max, c1, c2, max = -1;
    // 1) find max(abc) give a + b + c = N and a^2 + b^2 - c^2 = 0
    // 2) From 1), we know that a+b = N - c
    // 3) From 2) & 1) (a+b)^2 = a^2 + b^2 + 2ab = N^2 + c^2 - 2Nc. It gives
    // 4) 2ab = N^2 + c^2 - 2Nc - a^2 - b^2
    // 5) From 1), We know that c^2 - a^2 - b^ 2 which gives 4) that 2ab = N^2 - 2Nc
    // 6) From 5) abc becomes c * (N^2 - 2Nc) * 0.5
    // Thus abc = 0.5 * c * N^2 - Nc^2
    c1 = 0.5 * pow(N,2);
    c2 = -1 * N;
    for (i = 3; i<= N-2; i++)
    {
        local_max = c1 * i + c2 * i * i;
        if (local_max > max)
        {
            max = local_max;
        }
    }
    if (max <= 0)
    {
        max = -1;
    }
    return max;
}
