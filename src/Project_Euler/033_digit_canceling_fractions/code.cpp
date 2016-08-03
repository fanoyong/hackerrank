#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define DEBUG 1
using namespace std;

int N, K;

int candidate(int i, int j);
double reduce(int i, int j);

int main() {
    cin >> N >> K;
    int start = pow(10,N-1);
    int end = pow(10,N)-1;
    double original, fraction;
    int numerator = 0, denominator = 0;
    for (int i = start; i<=end; i++) {
        for (int j = i+1; j<=end; j++) {
            for (int k=1;k<=9; k++) {
                if (candidate(i,j)) {
                    original = i/j;
                    #if DEBUG
                        cout << "i: " << i << " j: " << j << endl;
                    #endif
                    fraction = reduce(i,j);
                    if (reduce(i,j)) {
                        numerator += i;
                        denominator += j;
                    }
                }
            }
        }
    }
    cout << numerator << " " << denominator << endl;
    return 1;
}

int candidate(int i, int j) {
    unsigned int digit;
    int * digiti = (int *) calloc (10, sizeof(int));
    int * digitj = (int *) calloc (10, sizeof(int));
    while (i>0) {
        digit = i%10;
        digiti[digit]++;
        i /= 10;
    }
    while (j>0) {
        digit = j%10;
        digitj[digit]++;
        j /= 10;
    }
    digit = __builtin_popcount (*digiti & *digitj);
    free(digiti);
    free(digitj);
    return digit >= 2 ? 1 : 0;
}

double reduce(int i, int j) {
    int newi=0, newj=0;
    int power10 = 1;
    int digit;
    while (i>0) {
        digit = i%10;
        i /= 10;
    }
    while (j>0) {
        digit = j%10;
        j /= 10;
    }
    return i/j;
}
