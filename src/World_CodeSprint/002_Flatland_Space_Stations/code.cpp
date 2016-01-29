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
//#include <unordered_map>

using namespace std;


int main(){
    int n;
    int m;
    int i, temp;
    int max_distance = INT_MIN;
    cin >> n >> m;
    vector<int> d(n);
    vector<int> s(m);
    for(i=0; i<n; i++) {
        d[i] = 0;
    }
    for(i=0; i<m; i++) {
        cin >> temp;
        s[i] = temp;
    }
    if (n==m) {
        cout << 0 << endl;
        return 0;
    }
    int phase = 0;
    int cnt = 0;
    int index;
    while (cnt < n) {
        for(i=0; i<m; i++) {
            index = s[i] - phase;
            if(index >= 0 && !d[index]) {
                d[index] = 1;
                cnt++;
            }
            index = s[i] + phase;
            if(index < n && !d[index]) {
                d[index] = 1;
                cnt++;
            }
        }
        phase++;
    }
    cout << phase-1 << endl;
    return 0;
}

