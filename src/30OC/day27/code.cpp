#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void print_testcases();
void solve_problem();

int main()
{
    print_testcases();
    //solve_problem();
    return 0;
}

void print_testcases()
{
    cout << "6" << endl;
    cout << "4 4" << endl;
    cout << "-1 0 3 2" << endl;
    cout << "5 1" << endl;
    cout << "0 -1 -2 1 1" << endl;
    cout << "6 6" << endl;
    cout << "-1 0 4 2 0 -1" << endl;
    cout << "7 1" << endl;
    cout << "-1 0 4 2 0 2 -2" << endl;
    cout << "8 8" << endl;
    cout << "-1 0 2 3 4 5 6 7" << endl;
    cout << "9 8" << endl;
    cout << "0 1 2 3 4 5 6 7" << endl;
}

void solve_problem()
{
    int T, N, K, i, cnt, data;
    cin >> T;
    //solve_problem();
    while (T--) {
        cin >> N >> K;
        cnt = 0;
        for(i=0;i<N;i++) {
            cin >> data;
            if(data <= 0) cnt++;
        }
        if(cnt >= K) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
}
