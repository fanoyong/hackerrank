#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void brute_force(int N);

int main() {
    int T,N;
    cin >> T;
    while (T--)
    {
        cin >> N;
        brute_force(N);   
    }
    return 0;
}

void brute_force(int N) {
    int i;
    int sum=0;
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

