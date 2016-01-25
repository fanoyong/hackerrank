#include <cmath>
#include <cstdio>
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>

#define DEBUG 0

using namespace std;

void generate_100_primes();
void generate_minimal_HCN();
long long get_answer(long long N);
void init_data();
void print_data();

long long PRIME[100];
long long DATA[100];
long long NOMINAL[100];
long long QUOTIENT[100];

int main() {
    long long i, T, N;
    generate_100_primes();
    generate_minimal_HCN();
    print_data();
    cin >> T;
    while (T--) {
        cin >> N;
        i = get_answer(N);
    }
    return 0;
}

void generate_100_primes()
{
    int cnt = 0;
    int flag;
    int i, j;
    for(i=2;;i++) {
        flag = 1;
        for(j=2;j<=sqrt(i); j++) {
            if((i%j) == 0) {
                flag = 0;
                break;
            }
        }
        if(flag) {
            PRIME[cnt++] = i;
        }
        if(cnt == 100) return;
    }
}

void generate_minimal_HCN()
{
    long long i, j, prod, prod_sum, min, min_i;
    DATA[0] = 1;
    for(i=1; i<100; i++) {
        init_data();
        prod = 1;
        prod_sum = 0;
        min = INT_MAX;
        while(prod_sum < (i+1)) {

            for(j=0;j<100;j++) {
                if(NOMINAL[j] < min) {
                    min = NOMINAL[j];
                    min_i = j;
                }
            }

            NOMINAL[min_i] = NOMINAL[min_i] * PRIME[min_i];
            QUOTIENT[min_i]++;

            for(j=0;j<100;j++) {
                if(QUOTIENT[j] != 0 && NOMINAL[j] > 1) {
                    prod = prod * QUOTIENT[j] * NOMINAL[j];
                    prod_sum = prod_sum + (QUOTIENT[j]+1);
                }
            }
        }
        DATA[i] = prod;
    }
}

long long get_answer(long long N)
{
    return 0;
}

void init_data()
{
    int i;
    for(i=0; i<100;i++) {
        NOMINAL[i] = PRIME[i];
        QUOTIENT[i] = 0;
    }
}

void print_data()
{
    int i;
    for(i=0;i<100;i++) {
        cout << DATA[i] << endl;
    }
}


