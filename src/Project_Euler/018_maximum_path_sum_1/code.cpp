#include <cmath>
#include <cstdio>
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

int N;
int MAX_SUM;
int DATA[120];

void input();
void print();
void get_sum(int level, int index, int localsum);

int main() {
    int T;
    cin >> T;
    while (T--) {
        input();
        // print();
        MAX_SUM = INT_MIN;
        get_sum(0, 0, 0);
        cout << MAX_SUM << endl;
    }
    return 0;
}

void input()
{
    int i,j;
    cin >> N;
    for(i=0; i<N; i++) {
        for(j=0;j<i+1;j++) {
            cin >> DATA[(i*(i+1))/2+j];
        }
    }
}

void print()
{
    int i,j;
    for(i=0; i<N; i++) {
        for(j=0;j<i+1;j++) {
            cout << DATA[(i*(i+1))/2+j] << " ";
        }
        cout << endl;
    }
}

void get_sum(int level, int index, int localsum)
{
    if (level >= N) {
        if (localsum > MAX_SUM) {
            MAX_SUM = localsum;
        }
        return;
    }
    int left_child_index = index + level + 1, right_child_index = index + level + 2;
    get_sum(level+1, left_child_index, localsum + DATA[index]);
    get_sum(level+1, right_child_index, localsum + DATA[index]);
}
