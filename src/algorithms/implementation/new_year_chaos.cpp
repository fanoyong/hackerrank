#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>

#define ULL long long

#define DEBUG 0

/*
12537864
12537684 +
12537648 +
12536748 +
12536478 +
12534678 +
12354678 +
12345678 +

*/


using namespace std;

void swap(vector<ULL> &arr, ULL index);
void print(vector<ULL> &arr);

int main(){
    int T;
    cin >> T;
    for(int t=0; t < T; t++){
        ULL n;
        cin >> n;
        vector<ULL> q(n+1);
        vector<ULL> index(n+1);
        vector<ULL> count(n+1);
        for(ULL i=1; i<=n; i++){
            cin >> q[i];
            index[q[i]] = i;
            count[i] = 2;
        }
#if DEBUG
        cout << endl << "data: " << endl;
        print(q);
        cout << "index: " << endl;;
        print(index);
#endif
        int flag = 0;
        for (ULL i=1; i<=n; i++) {
#if DEBUG
            cout << "i: " << i << endl;
            cout << "index[i]: " << index[i] << endl;
#endif
            if ((i - index[i]) > 2) {
#if DEBUG
                cout << "cannot reach" << endl;
#endif
                flag = 1;
                break;
            }
        }
        if (flag) {
            cout << "Too chaotic" << endl;
            continue;
        }
        ULL swap_count = 0;
        flag = 0;
        for (ULL i=n; i>1; i--) {
            ULL cur = index[i];
#if DEBUG
            cout << "i: " << i << " cur: " << cur << endl;
            print(q);
            print(index);
#endif
            if (index[i] == i) {
                continue;
            }
            do {
                if (count[i] <= 0) {
                    flag = 1;
                    break;
                }
                count[i]--;

                ULL t = q[index[i]+1];
#if DEBUG
                cout << "t:" << t << endl;
#endif
                q[index[i]+1] = q[index[i]];
                q[index[i]] = t;

                index[t]--;
                index[i]++;

                cur = index[i];
                swap_count++;
#if DEBUG
                cout << "SWAP_COUNT++" << endl;
                print(q);
                print(index);
#endif
            } while(cur < i);
            if (flag) {
                break;
            }
        }
        if (flag) {
            cout << "Too chaotic" << endl;
            continue;
        }
        cout << swap_count << endl;
    }
    return 0;
}

void print(vector<ULL> &arr)
{
    for (ULL i=1; i<arr.size(); i++) {
        cout << arr[i];
    }
    cout << endl << endl;
}
