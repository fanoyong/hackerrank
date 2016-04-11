#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#define DEBUG 0

using namespace std;

int partition_lomuto(vector <int> &arr, int lo, int hi);
void quicksort_lomuto(vector <int> &arr, int lo, int hi);
void insertion_sort (vector <int> arr, int length);

int qsort_count=0;
int insertion_count=0;

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    vector<int> arr2(N);
    for(int i = 0; i<N; i++) {
        cin >> arr[i];
    }
    arr2 = arr;
    quicksort_lomuto(arr, 0, N-1);
    insertion_sort(arr2, N);
#if DEBUG
    cout << insertion_count << endl;
    cout << qsort_count << endl;
#endif
    cout << insertion_count - qsort_count << endl;
    return 0;
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
            qsort_count++;
        }
    }
    int temp = arr.at(i);
    arr[i] = arr.at(hi);
    arr[hi] = temp;
    qsort_count++;
    return i;
}

void quicksort_lomuto(vector <int> &arr, int lo, int hi) {
    if (lo < hi) {
        int p = partition_lomuto(arr, lo, hi);
        quicksort_lomuto(arr, lo, p-1);
        quicksort_lomuto(arr, p+1, hi);
    }
}

void insertion_sort (vector <int> arr, int length){
    int j, temp;
    for (int i = 0; i < length; i++) {
        j = i;
        while (j > 0 && arr[j] < arr[j-1]){
            temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
            insertion_count++;
        }
    }
}
