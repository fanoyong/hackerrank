#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int get_divisor_sum(int n);
int is_amicable_number(int n);
void generate_data();
int get_sum(int n);
int DATA[10000];
int COUNT;

int main() {
    int T, N;
    cin >> T;
    generate_data();
    while(T--) {
        cin >> N;
        cout << get_sum(N) << endl;
    }
    return 0;
}


int get_divisor_sum(int n)
{
    int i;
    int local_count = 1;
    for(i=2; i<=sqrt(n); i++) {
        if(n%i == 0) {
            local_count += i;
            local_count += (n/i);
        }
    }
    return local_count;
}

int is_amicable_number(int n)
{
    int divisor_sum = get_divisor_sum(n);
    int divisor_sum_n = get_divisor_sum(divisor_sum);
    return (n == divisor_sum_n) && (n != divisor_sum);
}

void generate_data()
{
    int i;
    COUNT = 0;
    for(i=1; i<=100000; i++) {
        if(is_amicable_number(i)) {
            // cout << "i:" << i << endl;
            DATA[COUNT++] = i;
        }
    }
}

int get_sum(int n)
{
    int i;
    int sum = 0;
    for(i=0;i<COUNT;i++) {
        if(DATA[i]>n) {
            break;
        }
        sum+=DATA[i];
    }
    return sum;
}
