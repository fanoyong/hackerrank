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

#define DEBUG_P 0

int main(){
    int len, i, cnt;
    string S;
    cin >> S;
    len = S.length();
    cnt = 0;
    if (DEBUG_P) {
        cout << "len:" << len << endl;
    }
    for (i=0; i< len; i+=3) {
        if (DEBUG_P) {
            cout << "i:" << i << endl;
            cout << "String:" << S[i] << S[i+1] << S[i+2] << endl;
        }
        if (S[i] != 'S') cnt++;
        if (S[i+1] != 'O') cnt++;
        if (S[i+2] != 'S') cnt++;
    }
    cout << cnt << endl;
    return 0;
}

