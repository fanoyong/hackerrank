#include <cmath>
#include <cstdio>
#include <climits>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void generate_sequence();
void find_greatest();
void print_data();

unsigned long long DATA[5000001];
unsigned long long ANSWER[5000001];

int main() {
    unsigned long long T, N;
    generate_sequence();
    find_greatest();
    // print_data();
    cin >> T;
    while(T--) {
        cin >> N;
        cout << ANSWER[N] << endl;
    }
    return 0;
}

void generate_sequence()
{
    unsigned long long i, cur, cnt;
    for(i=1; i<=5000000; i++) {
        cnt = 0;
        cur = i;
        while (cur != 1) {
            if (cur < i) {
                cnt += DATA[cur];
                break;
            }
            if (cur&1) {
                cur *= 3;
                cur++;
            } else {
                cur >>= 1;
            }
            cnt++;
        }
        DATA[i] = cnt;
    }
}

void find_greatest()
{
    unsigned long long i, j, max, max_i;
    max = DATA[1];
    ANSWER[1] = 0;
    for(i=2; i<=5000000; i++) {
        if(DATA[i] >= max) {
            max = DATA[i];
            max_i = i;
        }
        ANSWER[i] = max_i;
    }
}

void print_data()
{
    unsigned long long i;
    for(i=1; i<=100; i++) {
        cout << "\ti:" << i << "\tDATA[i]:" << DATA[i] <<  "\tindex[i]:" << ANSWER[i] << endl;
    }
}
