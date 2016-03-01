#include <iostream>
#include <cmath>

using namespace std;

int isPrime(int N);

int main()
{
    int i;
    int N, F, a, b, count;
    int MAX_COUNT=0, MAX_A=0, MAX_B=0;
    cin >> N;
    for (b=N; b>=-1*N; b--) {
        if (!isPrime(b)) {
            continue;
        }
        for (a=N; a>=-1*N; a--) {
            for(i=0; ;i++) {
                F = i * i + a*i + b;
                if (!isPrime(F)) {
                    if (i > MAX_COUNT) {
                        MAX_COUNT = i;
                        MAX_A = a;
                        MAX_B = b;
                    }
                    break;
                }
            }
        }
    }
    cout << MAX_A << " " << MAX_B << endl;
}

int isPrime(int N)
{
    int i;
    if (N < 2) return 0;
    if (N == 2) return 1;
    for (i=3; i<=sqrt(N); i+=2) {
        if (N%i == 0) {
            return 0;
        }
    }
    return 1;
}
