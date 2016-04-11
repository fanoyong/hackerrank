#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int V;
    cin >> V;
    int N;
    cin >> N;
    for (int i=0;i<N; i++) {
        int C;
        cin >> C;
        if (C == V) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}

