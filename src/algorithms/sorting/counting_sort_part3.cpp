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
    // char STRING[1000001][11];
    for(int i = 0; i<100; i++) {
        COUNT[i] = N;
    }
    for(int i = 0; i<N; i++) {
        cin >> DATA[i];
        string s;
        cin >> s;
        // cin >> STRING[i];
        for (int j = 0; j<DATA[i]; j++) {
            COUNT[j]--;
        }
    }
    for (int i=0; i<100; i++) {
        cout << COUNT[i] << " ";
    }
    cout << endl;
    return 0;
}

