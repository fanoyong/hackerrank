#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int get_answer(int N);
int generate_data(int N);

int DATA[10001];
int LIST[10001];

int main()
{
    int T, N;
    generate_data(10000);
    cin >> T;
    while (T--) {
        cin >> N;
        cout << get_answer(N) << endl;
    }
    return 0;
}

int get_answer(int N)
{
    int MAX = -1;
    int index = 1;
    for (int i = 3; i < N; i++) {
        if (DATA[i] > MAX) {
            MAX = DATA[i];
            index = i;
        }
    }
    return index;
}

int is_prime(int N)
{
    int i;
    if(N%2 == 0) return 1;
    if(N%3 == 0) return 1;
    for (i=3;i<=sqrt(N);i+=2) {
        if(N%i == 0)  return 0;
    }
    return 1;
}


int generate_data(int N)
{
    double n;    
    int q, index, count, flag;
    int max = -1, max_index = 0;
    for (int i = 3; i <= N; i++) {
        n = 1;
        flag = 0;
        count = 0;
        if (i % 5 == 0 || i % 2 == 0) {
            DATA[i] = 0;
            continue;
        }
        if (i > 5 && !is_prime(i)) {
            // cout << i << " is prime." << endl;
            DATA[i] = 0;
            continue;
        }
        index = 0;
        while (true) {
            while (n < i) {
                n *= 10;
            }
            n = fmod(n, (double) i);
            if (n == 0) {
                index = 0;
                break;
            }
            int count2;
            if (count > 10) {
                count2 = 10;
            } else {
                count2 = count;
            }
            for (int j = 0; j < count2; j++) {
                if (LIST[j] == n) {
                    flag = 1;
                    break;
                }
            }
            if (flag) {
                break;
            }
            LIST[count++] = n;
        }
        DATA[i] = count - index;
        if (DATA[i] > max) {
            max = DATA[i];
            max_index = i;
        }
    }
    return max_index;
}
