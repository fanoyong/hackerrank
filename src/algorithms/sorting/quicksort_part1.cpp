#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

void partition(vector <int>  ar, int lo, int hi) {
    int pivot = ar.at(lo);
    int i = lo;
    int j = hi;
    while (i < j) {
        while (ar.at(i) < pivot) {
            i++;
        }
        while (ar.at(j) > pivot) {
            j--;
        }
        int temp = ar.at(i);
        ar[i] = ar.at(j);
        ar[j] = temp;
    }

    for(int j=0; j<ar.size(); j++) {
        cout << ar.at(j) << " ";
    }
    cout << endl;
}

int main(void) {
   vector <int>  _ar;
   int _ar_size;
   cin >> _ar_size;
    
     for(int _ar_i=0; _ar_i<_ar_size; _ar_i++) {
        int _ar_tmp;
        cin >> _ar_tmp;
        _ar.push_back(_ar_tmp); 
    }

   partition(_ar, 0, _ar.size()-1);
   
   return 0;
}
