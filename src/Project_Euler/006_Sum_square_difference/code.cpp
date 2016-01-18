#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int T, N;
    int i;
    unsigned long sum1, sum2; 
    cin >> T;
    while (T--)
    {
        cin >> N;
        sum1=0;
        for(i=1; i<=N; i++)
        {
            sum1 += pow(i,2);            
        }
        sum2 = pow((N+1) * N / 2, 2);
        cout << sum2- sum1 << endl;
    }
    return 0;
}

