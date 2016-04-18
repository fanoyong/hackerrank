#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define LL long long

using namespace std;

void quicksort_lomuto(vector<int> &arr, LL lo, LL hi);
LL partition_lomuto(vector<int> &arr, LL lo, LL hi);
void quicksort_hoare(vector<int> &arr, LL lo, LL hi);
LL partition_hoare(vector<int> &arr, LL lo, LL hi);
void print(vector<int> arr);

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    for(LL i=0; i<N; i++) {
        cin >> arr[i];
    }
    print(arr);
    quicksort_hoare(arr,0,arr.size()-1);
    print(arr);
    return 0;
}

void quicksort_lomuto(vector<int> &arr, LL lo, LL hi) {
    if (lo < hi) {
        LL p = partition_lomuto(arr, lo, hi);
        quicksort_lomuto(arr, lo, p-1);
        quicksort_lomuto(arr, p+1, hi);
    }
}

LL partition_lomuto(vector<int> &arr, LL lo, LL hi) {
    int pivot = arr.at(hi);
    LL i = lo;
    for(LL j = lo; j<= hi-1; j++) {
        if(arr.at(j) <= pivot) {
            int t = arr.at(j);
            arr[j] = arr.at(i);
            arr[i] = t;
            i++;
        }
    }
    int t = arr.at(hi);
    arr[hi] = arr.at(i);
    arr[i] = t;
    return i;
}

void quicksort_hoare(vector<int> &arr, LL lo, LL hi) {
    if (lo < hi) {
        LL p = partition_hoare(arr, lo, hi);
        quicksort_hoare(arr, lo, p);
        quicksort_hoare(arr, p+1, hi);
    }
}

LL partition_hoare(vector<int> &arr, LL lo, LL hi) {
    int pivot = arr.at(lo);
    LL i = lo-1;
    LL j = hi+1;
    while (1) {
        do {
            i++;
        } while (arr.at(i) < pivot);
        do {
            j--;
        } while (arr.at(j) > pivot);
        if (i >= j) return j;
        int t = arr.at(i);
        arr[i] = arr.at(j);
        arr[j] = t;
    }
}

void print(vector<int> arr) {
    LL end = arr.size();
    for (LL i=0; i<end; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
