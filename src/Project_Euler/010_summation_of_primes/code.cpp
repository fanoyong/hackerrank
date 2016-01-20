#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void generate_prime_list();
void get_nth_prime(int n);
int is_prime(int n);
long long PRIME_LIST[200001];

int main() {
    int T, N, i;
    long long sum;
    generate_prime_list();
    cin >> T;
    while (T--)
    {
        cin >> N;
        sum = 0;
        i=0;
        while (PRIME_LIST[i] <= N) {
            sum+=PRIME_LIST[i++];
        }
        cout << sum << endl;
    }
    return 0;
}

void generate_prime_list()
{
    int cnt=0, i=2;
    PRIME_LIST[cnt++] = 2;
    do {
        if (is_prime(i)) PRIME_LIST[cnt++] = i;
        i++;        
    } while (cnt < 200000);
}

int is_prime(int n)
{
    long long i;
    for(i=2;i<sqrt(n)+1;i++)
    {
        if (n%i == 0) return 0;
    }
    return 1;
}
