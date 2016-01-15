#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

unsigned long long fibonacci[10000];
unsigned long long fibonacci_even[10000];
int cnt=2, cnt_even=1;

void preprocess();
void print();

int main() {
    unsigned long long T, N;
    unsigned long long sum;
    int i;
    preprocess();
    cin >> T;
    while (T--) {
        cin >> N;
        sum = 0;
        i=0;        
        while(fibonacci_even[i] < N && i<cnt_even) {
            sum+=fibonacci_even[i++];
        }
        cout << sum << endl;
    }


    return 0;
}

void preprocess() {
    fibonacci[0] = 1;
    fibonacci[1] = 2;
    fibonacci_even[0] = 2;
    do {
        fibonacci[cnt] = fibonacci[cnt-2] + fibonacci[cnt-1];
        if (!(fibonacci[cnt] & 1))  {
            fibonacci_even[cnt_even++] = fibonacci[cnt];
        }
        cnt++;
    } while (fibonacci[cnt-1] < 40000000000000000);
}

void print() {
    int i=0;
    while(fibonacci[i] < 40000000000000000) {
        cout << "fibo:" << fibonacci[i] << " ";
        i++;
    }
}
