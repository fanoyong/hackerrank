#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

#define ULLT unsigned long long
#define DEBUG 0


/*

  1 1 1
  1 2 1
  1 1 1

  1 1 1 1
  1 2 2 1
  1 2 2 1
  1 1 1 1

  1 1 1 1 1
  1 2 2 2 1
  1 2 3 2 1
  1 2 2 2 1
  1 1 1 1 1
  
  1 1 1 1 1 1
  1 2 2 2 2 1
  1 2 3 3 2 1
  1 2 3 3 2 1
  1 2 2 2 2 1
  1 1 1 1 1 1
  
  
  1 1 1 1 1 1 1
  1 2 2 2 2 2 1
  1 2 3 3 3 2 1
  1 2 3 4 3 2 1
  1 2 3 3 3 2 1
  1 2 2 2 2 2 1
  1 1 1 1 1 1 1
*/

ULLT DATA[100000ULL];
ULLT N;

int main() {
    int T;
    // fstream fin;
    // fin.open("input2.txt",ios::in);
    cin >> T;
    #if DEBUG
        cout << "T:" << T << endl;
    #endif
    while(T--) {
        cin >> N;
        for(ULLT i=0; i<N; i++) {
            cin >> DATA[i];
        }
        if(N&1 == 1) {
            ULLT ret = 0;
            for(ULLT i=0;i<N;i+=2) {
                ret = (ret^DATA[i]);
            }
            cout << ret << endl;
        } else {
            cout << 0 << endl;
        }
    }
    
    return 0;
}
