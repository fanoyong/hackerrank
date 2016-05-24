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
#include <unordered_map>

#define LL long long

using namespace std;

void print(vector<LL> &arr);

int main(){
    int T;
    cin >> T;
    for(LL a0 = 0; a0 < T; a0++){
        LL n;
        cin >> n;
        vector<LL> q(n+1);
        vector<LL> qr(n+1);
        vector<LL> r(n+1);
        for(LL q_i=1; q_i<=n; q_i++){
            cin >> q[q_i];
            qr[q[q_i]] = q_i;
            r[q_i] = 2;
        }
        print(q);
        print(qr);
        print(r);
        for (LL i=1; i<= n; i++) {
            qr[i];
        }    
    }
    return 0;
}

void print(vector<LL> &arr)
{
    for (LL i=1; i<arr.size(); i++) {
        cout << arr[i];
    }
    cout << endl << endl;
}
