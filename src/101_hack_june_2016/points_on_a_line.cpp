#include <map>
#include <set>
#include <list>
#include <cmath>
#include <cfloat>
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

using namespace std;


int main(){
    int flag = 1;
    int n;
    int x_prev, y_prev;
    int x,y;
    double slope=0, slope_prev=0;
    cin >> n;
    cin >> x_prev >> y_prev;
    cin >> x >> y;
    if (x_prev == x) {
        slope_prev = DBL_MAX;
    } else if (y_prev == y) {
        slope_prev = 0;
    } else {
        slope_prev = (y-y_prev) / (x-x_prev);
    }
    x_prev = x;
    y_prev = y;
    for(int a0 = 2; a0 < n; a0++){
        cin >> x >> y;
        if (x_prev == x) {
            slope = DBL_MAX;
        } else if (y_prev == y) {
            slope = 0;
        } else {
            slope = (y-y_prev) / (x-x_prev);
        }
        if (slope != slope_prev) {
            flag = 0;
        }
        y_prev = y;
        x_prev = x;
        slope_prev = slope;
    }
    if (flag) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}

