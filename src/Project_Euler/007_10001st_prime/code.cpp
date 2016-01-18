#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void generate_prime_list();
void get_nth_prime(int n);
int is_prime(int n);
unsigned long long PRIME_LIST[10001];

int main() {
    int T, N;
    generate_prime_list();
    cin >> T;
    while (T--)
    {
        cin >> N;
        get_nth_prime(N-1);
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
    } while (cnt < 10001);
}

void get_nth_prime(int n)
{
    cout << PRIME_LIST[n] << endl;
}

int is_prime(int n)
{
    int i;
    for(i=2;i<sqrt(n)+1;i++)
    {
        if (n%i == 0) return 0;
    }
    return 1;
}
