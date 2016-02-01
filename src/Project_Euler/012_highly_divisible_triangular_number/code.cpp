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
long long get_prod_sum(long long N);
long long get_answer(long long N);

long long PRIME[5000];
long long DATA[1000];
long long ANSWER[1000];

int main() {
    long long i, T, N;
    generate_100_primes();
    generate_minimal_HCN();
    cin >> T;
    while (T--) {
        cin >> N;
        i = get_answer(N);
        cout << ANSWER[i] << endl;
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
        if(cnt == 5000) return;
    }
}

void generate_minimal_HCN()
{
    int prod = 1;
    long long i, j, number, sum;
    DATA[0] = 1;
    i = 1;
    while(1) {
        for(;;i++) {
            number = (int) (i * (i+1) / 2);
            sum = get_prod_sum(number);
            if(DATA[prod-1] < sum) {
                DATA[prod] = sum;
                ANSWER[prod] = number;
                break;
            }
        }
        // cout << "i=" << i << " n=" << number << " DATA[prod]=" << DATA[prod] << endl;
        if(DATA[prod] > 1000) {
            break;
        }
        prod++;
    }
}

long long get_prod_sum(long long N)
{
    int i, prod;
    int sum = 1;
    for(i=0; i< 5000;i++) {
        if (PRIME[i] > N) {
            break;
        }
        prod = 1;
        while(N%PRIME[i] == 0) {
            prod++;
            N /= PRIME[i];
        }
        sum *= prod;
    }
    return sum;
}

long long get_answer(long long N)
{
    int i;
    for(i=0;;i++) {
        if(DATA[i] > N) {
            break;
        }
    }
    return i;
}

