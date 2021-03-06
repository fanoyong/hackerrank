#include <bits/stdc++.h>

#define DEBUG 0

using namespace std;

int partition_hoare(vector <int> &arr, int lo, int hi);
int partition_stable(vector <int> &arr, int lo, int hi);
void quicksort_hoare(vector <int> &arr, int lo, int hi);
int partition_lomuto(vector <int> &arr, int lo, int hi);
void quicksort_lomuto(vector <int> &arr, int lo, int hi);

int main()
{
    int n;
    cin >> n;

    vector <int> arr(n);
    for(int i = 0; i < (int)n; ++i) {
        cin >> arr[i];
    }

    quicksort_lomuto(arr,0,arr.size()-1);

    return 0;
}


void quicksort_hoare(vector <int> &arr, int lo, int hi) {
    if (lo < hi) {
        int p = partition_lomuto(arr, lo, hi);
        quicksort_hoare(arr, lo, p-1);
        quicksort_hoare(arr, p+1, hi);
    }
}

int partition_hoare(vector <int> &arr, int lo, int hi) {
    int pivot = arr.at(lo);
#if DEBUG
    for (int k = 0; k<arr.size(); k++) {
        cout << arr.at(k) << " ";
    }
    cout << endl;
    cout << "pivot:" << pivot << " lo:" << lo << " hi:" << hi << endl;
#endif
    int i = lo;
    int j = hi;
    while (i<j) {
        while(arr.at(i) < pivot) {
            i++;
        }
        while(arr.at(j) > pivot) {
            j--;
        }
#if DEBUG
        cout << "SWAP:" << arr[i] << " and " << arr[j] << endl;
#endif
        int temp = arr.at(i);
        arr[i] = arr.at(j);
        arr[j] = temp;
    }
#if DEBUG
    for (int k = 0; k<arr.size(); k++) {
        cout << arr.at(k) << " ";
    }
    cout << endl;
    cout << "return pivot:" << pivot <<  " p_index:" << i << endl;
#endif
    return j;
}

int partition_stable(vector <int> &arr, int lo, int hi) {
    vector<int> arr2 = arr;
    int pivot = arr2.at(lo);
    int index = lo;
    for(int i=lo; i<=hi; i++) {
        if(arr2.at(i) < pivot) {
            arr[index++] = arr2.at(i);
        }
    }
    int pivot_index = index;
    arr[index++] = pivot;
    for(int i=lo; i<=hi; i++) {
        if(arr2.at(i) > pivot) {
            arr[index++] = arr2.at(i);
        }
    }
    return pivot_index;
}

int partition_lomuto(vector <int> &arr, int lo, int hi) {
    int pivot = arr.at(hi);
    int i = lo;
    for (int j=lo; j<=hi-1; j++) {
        if (arr.at(j) <= pivot) {
            int temp = arr.at(i);
            arr[i] = arr.at(j);
            arr[j] = temp;
            i++;
        }
    }
    int temp = arr.at(i);
    arr[i] = arr.at(hi);
    arr[hi] = temp;
    return i;
}

void quicksort_lomuto(vector <int> &arr, int lo, int hi) {
    if (lo < hi) {
        int p = partition_lomuto(arr, lo, hi);
        for (int i = 0; i<arr.size(); i++) {
            cout << arr.at(i) << " ";
        }
        cout << endl;
        quicksort_lomuto(arr, lo, p-1);
        quicksort_lomuto(arr, p+1, hi);
    }
}
