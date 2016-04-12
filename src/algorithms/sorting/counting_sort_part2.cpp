#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N;
    cin >>N;
    unsigned int DATA[1000001], COUNT[100];
    for(int i = 0; i<100; i++) {
        COUNT[i] = 0;
    }
    for(int i = 0; i<N; i++) {
        cin >> DATA[i];
        COUNT[DATA[i]]++;
    }
    for (int i=0; i<100; i++) {
        for (int j=0; j<COUNT[i]; j++) {
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}

