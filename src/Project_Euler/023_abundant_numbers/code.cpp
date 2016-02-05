#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int get_divisor_sum(int n);
int is_abundant_num(int n);
void generate_data();
void generate_data_from_abundant();
void print_data();

int DATA[100000];
int DATA2[100001];
int COUNT=0;

int main() {
    int T, N;
    cin >> T;
    COUNT = 0;
    generate_data();
    generate_data_from_abundant();
    // print_data();
    while(T--) {
        cin >> N;
        if(DATA2[N]) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
gi    return 0;
}


int get_divisor_sum(int n)
{
    int i;
    int local_count = 1;
    for(i=2; i<=sqrt(n); i++) {
        if(n%i == 0) {
            local_count += i;
            if ((n/i) != i) {
                local_count += (n/i);
            }
        }
    }
    return local_count;
}

int is_abundant_num(int n)
{
    return (get_divisor_sum(n) > n);
}

void generate_data()
{
    int i;
    for(i=1; i<=100000; i++) {
        if(is_abundant_num(i)) {
            DATA[COUNT++] = i;
        }
    }
}

void generate_data_from_abundant()
{
    int i,j;
    for (i=1; i<=100000; i++) {
        DATA2[i] = 0;
    }
    for (i=0; i<COUNT; i++) {
        for(j=0; j<COUNT; j++) {
            int k = DATA[i]+DATA[j];
            if (k <= 100000) {
                DATA2[k] = 1;
            }
        }
    }
}

void print_data()
{
    int i;
    for(i=0; i<10; i++) {
        cout << "ABU=" << DATA[i] << "DATA2=" << DATA2[i] <<endl;
    }
    for(i=0; i<100; i++) {
        if (DATA[i] != 0) {
            cout << i << endl;
        }
    }
}
