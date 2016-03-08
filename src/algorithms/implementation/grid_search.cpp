#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin >> R >> C;
        vector<string> G(R);
        for(int G_i = 0;G_i < R;G_i++){
           cin >> G[G_i];
        }
        int r, c;
        cin >> r >> c;
        vector<string> P(r);
        for(int P_i = 0;P_i < r;P_i++){
           cin >> P[P_i];
        }
        int i, j, k, l;
        int isAnswerFound = 0;
        for(i=0; i<=R-r; i++) {
            for(j=0; j<=C-c; j++) {
                if (G[i].at(j) != P[0].at(0)) continue;
                int isFound = 1;
                for(k = i; k < i+r; k++) {
                    for(l = j; l < j+c; l++) {
                        if(G[k].at(l) != P[k-i].at(l-j)) {
                            isFound = 0;
                            break;
                        }
                    }
                }
                if (k == i+r && l == j+c && isFound) {
                    isAnswerFound = 1;
                    break;
                }
            }
        }
        if (isAnswerFound) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        
    }
    return 0;
}
