#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define DEBUG 1
int N, M;
int C[51];

int bottom_up();

int main() {
    int count = 0;
    cin >> N >> M;
    for (int i=1; i<=M; i++) {
        cin >> C[i];
    }
    int answer = bottom_up();
    cout << answer << endl;
    return 0;
}

int bottom_up() {

}
