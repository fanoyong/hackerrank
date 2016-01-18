#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long MAX_PROD;
char s[2001];
void calculate_prod(const int N, const int K);

int main() {
    int T, N, K;
    cin >> T;
    while(T--)
    {
        for(int i = 0; i<2001;i++)
        {
            s[i] = '\0';
        }
        cin >> N >> K;
        cin >> s;
        MAX_PROD=0;
        calculate_prod(N, K);
        cout << MAX_PROD << endl;
    }
    return 0;
}

void calculate_prod(const int N, const int K)
{
    int i,j;
    long long local_prod;
    for(i=0; i<N-K; i++)
    {
        local_prod = 1;
        for(j=i;j<i+K; j++)
        {
            char c = s[j]; 
            int k = atoi(&c);
            local_prod *= k;
        }
        if (local_prod > MAX_PROD)
        {
            MAX_PROD = local_prod;
        }
    }
}
