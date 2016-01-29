#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define DEBUG 0
using namespace std;


int main() {
    int T, len, i, a, b, flag;
    string s;
    cin >> T;
    while(T--) {
        cin >> s;
        len = s.length();
        flag = 0;
        for(i=1; i<=len/2; i++) {
            if (DEBUG) {
                cout << "s[i] - s[i-1]" << s[i] << "/" << s[i-1] << endl;
                cout << "s[len-i-1] - s[len-i]" << s[len-i-1] << "/" << s[len-i] << endl;
            }
            a = abs(s[i] - s[i-1]);
            b = abs(s[len-i-1] - s[len-i]);
            if (DEBUG) {
                cout << "a:" << a << " b:" << b  << endl;
            }
            if(a != b) {
                flag = 1;
                break;
            }
        }
        if (flag) {
            cout << "Not Funny" << endl;
        } else {
            cout << "Funny" << endl;
        }
    }
    return 0;
}

