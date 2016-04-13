#include <functional>
#include <cmath>
#include <cstdio>
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>

#define LL long long
#define DEBUG 0

using namespace std;

void quicksort(vector<LL> &arr, LL lo, LL hi);
LL partition(vector<LL> &arr, LL lo, LL hi);

int main() {
    LL N;
    cin >> N;
    vector<LL> DATA(200001);
    for(LL i=0; i<N; i++) {
        cin >> DATA[i];
    }
#if DEBUG
    for(LL i=0; i<N; i++) {
        cout << DATA[i] << " ";
    }
    cout << endl;
#endif
    quicksort(DATA, 0, N-1);
#if DEBUG
    for(LL i=0; i<N; i++) {
        cout << DATA[i] << " ";
    }
    cout << endl;
#endif
    vector<LL> DIFF(200000);
    LL MIN = INT_MAX;
    for(LL i=0; i<N-1; i++) {
        DIFF[i] = abs(DATA[i+1] - DATA[i]);
        if (MIN > DIFF[i]) MIN = DIFF[i];
    }
    for(LL i=0;i<N-1; i++) {
        if(DIFF[i] == MIN) {
            cout << DATA[i] << " " << DATA[i+1] << " ";
        }
    }
    cout << endl;
    return 0;
}

LL partition(vector<LL> &arr, LL lo, LL hi) {
    LL p = arr[lo];
    LL i = lo-1;
    LL j = hi+1;
    while(1) {
        do {
            i++;
        } while(arr[i] < p);
        do {
            j--;
        } while(arr[j] > p);
        if (i>=j) {
            return j;
        }
        LL t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }
}
void quicksort(vector<LL> &arr, LL lo, LL hi) {
    if (lo < hi) {
        LL p = partition(arr,lo,hi);
        quicksort(arr, lo, p);
        quicksort(arr, p+1, hi);
    }
}
