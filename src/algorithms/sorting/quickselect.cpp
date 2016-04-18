#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define LL long long
#define DEBUG 0

LL partition(vector<int> &arr, LL left, LL right, LL pivot_index);
int select(vector<int> &arr, LL left, LL right, int n);

int main() {
    LL N;
    cin >> N;
    vector<int> arr(N);
    for(LL i=0; i<N; i++) {
        cin >> arr[i];
    }
    cout << select(arr, 0, N-1, N/2) << endl;
    return 0;
}

LL partition(vector<int> &arr, LL left, LL right, LL pivot_index) {
#if DEBUG
    cout << "left:" << left << " right:" << right << " pi:" << pivot_index << endl;
#endif
    int pivot_value = arr.at(pivot_index);
    int t = arr.at(pivot_index);
    arr[pivot_index] = arr[right];
    arr[right] = t;
    LL store_index = left;
    for(LL i=left; i<=right-1; i++) {
        if(arr.at(i) < pivot_value) {
            t = arr.at(store_index);
            arr[store_index] = arr.at(i);
            arr[i] = t;
            store_index++;
        }
    }
    t = arr.at(store_index);
    arr[store_index] = arr.at(right);
    arr[right] = t;
    return store_index;
}

int select(vector<int> &arr, LL left, LL right, int n) {
    if (left == right) return arr.at(left);
    LL pivot_index = (left + floor(rand() % (right - left + 1)));
#if DEBUG
    cout << "pi_rand:" << pivot_index << endl;
#endif
    pivot_index = partition(arr, left, right, pivot_index);
#if DEBUG
    cout << "pi:" << pivot_index << endl;
#endif
    if (n == pivot_index) {
        return arr.at(n);
    } else if (n < pivot_index) {
        return select(arr, left, pivot_index-1, n);
    } else {
        return select(arr, pivot_index+1, right, n);
    }
}
