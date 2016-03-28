#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define DEBUG 0

int main() {
    int N, T;
    int data[1000];
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i<N; i++) {
            cin >> data[i];
        }
#if DEBUG
        cout << endl;
        for(int i = 0; i<N; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
#endif
        for(int i=0; i<N-4; i++) {
            for(int j=i; j<N-4;j++){
                if (data[i] > data[j]) {
                    int temp = data[j];
                    data[j] = data[i];
                    data[i] = temp;
                }
            }
        }
        if (N > 3) {
            if (data[N-2] < data[N-3] && data[N-2] < data[N-4]) {
#if DEBUG
        cout << "case 1" << endl;
#endif
                int temp = data[N-4];
                data[N-4] = data[N-2];
                data[N-2] = data[N-3];
                data[N-3] = temp;
            } else if (data[N-3] < data[N-2] && data[N-3] < data[N-4]) {
#if DEBUG
        cout << "case 2" << endl;
#endif
                int temp = data[N-4];
                data[N-4] = data[N-3];
                data[N-3] = data[N-2];
                data[N-2] = temp;
            } else if (data[N-4] < data[N-2] && data[N-4] < data[N-3]) {
#if DEBUG
        cout << "case 3" << endl;
#endif
                // do nothing
            }
        }
#if DEBUG
        cout << endl;
        for(int i = 0; i<N; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
#endif
        if (data[N-3] < data[N-2] && data[N-2] > data[N-1] && data[N-3] < data[N-1]) {
            // 1 3 2
#if DEBUG
            cout << "CASE 1" << endl;
#endif
            cout << "NO" << endl;
        } else if (data[N-3] > data[N-2] && data[N-2] > data[N-1]) {
            // 3 2 1
#if DEBUG
            cout << "CASE 2" << endl;
#endif
            cout << "NO" << endl;
        } else if (data[N-3] > data[N-2] && data[N-2] < data[N-1] && data[N-3] < data[N-1]) {
            // 2 1 3
#if DEBUG
            cout << "CASE 3" << endl;
#endif
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
    return 0;
}

