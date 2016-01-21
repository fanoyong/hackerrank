#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int DATA[100000];
int DATA2[100000];

void generate_data_brute_force();
void generate_data_better();
int get_factor_number(int N);
int find_data(int N);
void print();

int main() {
    int i, T, N, index;
    // generate_data_brute_force();
    generate_data_better();
    print();
    cin >> T;
    while (T--) {
        cin >> N;
        index = find_data(N);
        cout << index * (index+1) / 2 << endl;
    }
    return 0;
}

void generate_data_brute_force()
{
    int i, j, cnt;
    DATA[0] = 1;
    for(i=1; i<30000; i++) {
        DATA[i] = DATA[i-1] + (i+1);
    }
    DATA2[0] = 1;
    for(i=1; i<30000; i++) {
        cnt = 0;
        for(j=2; j<=sqrt(DATA[i]); j++) {
            if((DATA[i] % j) == 0) {
                cnt++;
            }
        }
        DATA2[i] = 2 + cnt*2;
    }
}

void generate_data_better()
{
    // DATA[i] is actually ((i+1) * i) / 2, so no need to store.
    // This will give integer factor i/2 & i+1 if i is even, and i+1/2 & i if i is odd. 
    // 1,3,6,10,15,21,28,36,45,55,...
    // 1 - 1
    // 3 - 1 3
    // 6 - 1 2 3 6
    // 10 - 1 2 5 10
    // 15 - 1 3 5 15
    // 21 - 1 3 7 21
    // 28 - 1 2 4 7 14 28
    // 36 - 1 2 3 4 6 9 12 18 36
    // we can get # of factors of these numbers and combine later.
    int i, j, cnt;
    DATA2[0] = 1;
    DATA2[1] = 2;
    for(i=2; i<100000; i++) {
        if(i&1) {
            if((i+1)/2 == i) {
                DATA2[i] = get_factor_number((i+1)/2) + 1;
            } else {
                DATA2[i] = get_factor_number((i+1)/2) + get_factor_number(i) + 2;
            }
        } else {
            if(i/2 == i+1) {
                DATA2[i] = get_factor_number(i/2) + 1;
            } else {
                DATA2[i] = get_factor_number(i/2) + get_factor_number(i+1) + 2;
            }
        }
    }
}

int get_factor_number(int N)
{
    int i, cnt=0;
    for(i=2; i<=sqrt(N); i++) {
        if((N%i) == 0) {
            cnt++;
        }
    }
    return cnt*2;
}

int find_data(int N)
{
    int i;
    for(i=0; i<100000; i++) {
        if(DATA2[i] > N) {
            return i;
        }
    }
    return 100000;
}

void print()
{
    int i;
    for(i=0; i<50; i++) {
        cout << DATA2[i] << endl;
    }
}
