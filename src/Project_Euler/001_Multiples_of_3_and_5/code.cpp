#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void brute_force(int N);
void calculate(long N);

int main() {
    int T;
    long N;
    cin >> T;
    while (T--)
    {
        cin >> N;
        // brute_force(N);   
        calculate(N);
    }
    return 0;
}

void brute_force(long N) {
    long i;
    long sum=0;
    for(i=3; i<N; i+=3) {
        sum+=i;
    }
    for(i=5; i<N; i+=5) {
        sum+=i;
    }
    for(i=15; i<N; i+=15) {
        sum-=i;
    }
    cout << sum << endl;
}

void calculate(long N) {
    long num_of_3 = (long) (N-1)/3;
    long num_of_5 = (long) (N-1)/5;
    long num_of_15 = (long) (N-1)/15;
    long sum_of_3 = 3 * (num_of_3 + 1) * num_of_3 / 2;
    long sum_of_5 = 5 * (num_of_5 + 1) * num_of_5 / 2;
    long sum_of_15 = 15 * (num_of_15 + 1) * num_of_15 / 2;
    cout << sum_of_3 + sum_of_5 - sum_of_15 << endl;
}
