#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int is_palindrome(int N);

int main() {
    int T, N, R, MAX_R;
    cin >> T;
    while (T--)
    {
        cin >> N;
        MAX_R = 0;
        for (int i=100; i<=999; i++)
        {
            for (int j=100; j<=999; j++)
            {
                R = i*j;
                if (R >= 101101 && R < 1000000 && R < N)
                {
                    if (is_palindrome(R))
                    {
                        if (MAX_R < R)
                        {
                            MAX_R = R;
                        }
                    }
                }
            }
        }
        cout << MAX_R << endl;
    }
    return 0;
}

int is_palindrome(int N)
{
    if ((int)(N/100000)%10 != (int)(N/1)%10) return 0;
    if ((int)(N/10000)%10 != (int)(N/10)%10) return 0;
    if ((int)(N/1000)%10 != (int)(N/100)%10) return 0;

    return 1;
}
