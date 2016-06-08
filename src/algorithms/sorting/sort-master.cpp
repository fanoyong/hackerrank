#include <cmath>
#include <cstdio>
#include <ctime>
#include <vector>
#include <iostream>
#include <algorithm>
#define LL long long
#define N 20000
#define DEBUG 0

using namespace std;

void compare(int *data);

void heap_sort(int *arr);
void radix_sort(int *arr);
void count_sort(int *arr);
void bubble_sort(int *arr);
void insertion_sort(int *arr);
void quicksort_lomuto(int *arr, LL lo, LL hi);
LL partition_lomuto(int *arr, LL lo, LL hi);
void quicksort_hoare(int *arr, LL lo, LL hi);
LL partition_hoare(int *arr, LL lo, LL hi);
void quicksort_randomize(int *arr, LL lo, LL hi);
LL partition_randomize(int *arr, LL lo, LL hi);
void print(int *arr);
void print10(int *arr);


int main() {
    int data_random[N], data_reverse[N], data_nearly[N];
    srand(time(0));
    for(LL i=0; i<N; i++) {
        int RAND = rand();
        int REVERSE = N-i;
        data_random[i] = RAND;
        data_reverse[i] = REVERSE;
        data_nearly[i] = i;
    }
    int t = data_nearly[0];
    data_nearly[0] = data_nearly[N-1];
    data_nearly[N-1] = t;
    cout << "starting comparison: random data" << endl;    
    compare(data_random);
    cout << "starting comparison: reverse data" << endl;
    compare(data_reverse);
    cout << "starting comparison: nearly sorted data" << endl;
    compare(data_nearly);

    return 0;
}

void compare(int *data) {
    int arr_lomuto[N], arr_hoare[N], arr_randomize[N], arr_bubble[N], arr_insert[N];
    for(LL i=0; i<N; i++) {
        arr_lomuto[i] = data[i];
        arr_hoare[i] = data[i];
        arr_randomize[i] = data[i];
        arr_bubble[i] = data[i];
        arr_insert[i] = data[i];
    }

#if DEBUG
    print10(arr_bubble);
    print10(arr_insert);
    print10(arr_lomuto);
    print10(arr_hoare);
    print10(arr_randomize);
#endif

    clock_t begin1 = clock();
    bubble_sort(arr_bubble);
    clock_t end1 = clock();
    double elapsed_secs1 = double(end1 - begin1) / CLOCKS_PER_SEC;
    cout << "Bubble sort took: " << elapsed_secs1 << endl;

    clock_t begin2 = clock();
    insertion_sort(arr_insert);
    clock_t end2 = clock();
    double elapsed_secs2 = double(end2 - begin2) / CLOCKS_PER_SEC;
    cout << "Insertion sort took: " << elapsed_secs2 << endl;

#if DEBUG
    print10(arr_bubble);
    print10(arr_insert);
    print10(arr_lomuto);
    print10(arr_hoare);
    print10(arr_randomize);
#endif

    clock_t begin3 = clock();
    quicksort_lomuto(arr_lomuto, 0, N-1);
    clock_t end3 = clock();
    double elapsed_sec3 = double(end3 - begin3) / CLOCKS_PER_SEC;
    cout << "Quicksort(lomuto) took: " << elapsed_sec3 << endl;

    clock_t begin4 = clock();
    quicksort_hoare(arr_hoare, 0, N-1);
    clock_t end4 = clock();
    double elapsed_secs4 = double(end4 - begin4) / CLOCKS_PER_SEC;
    cout << "Quicksort(hoare) took: " << elapsed_secs4 << endl;

    clock_t begin5 = clock();
    quicksort_randomize(arr_randomize, 0, N-1);
    clock_t end5 = clock();
    double elapsed_secs5 = double(end5 - begin5) / CLOCKS_PER_SEC;
    cout << "Quicksort(randomize) took: " << elapsed_secs5 << endl;
    cout << endl;
    
#if DEBUG
    print10(arr_bubble);
    print10(arr_insert);
    print10(arr_lomuto);
    print10(arr_hoare);
    print10(arr_randomize);
#endif
}

void bubble_sort(int *arr) {
    for (LL i=0; i<N-1; i++) {
        for (LL j=i; j<N-2-i; j++) {
            if (arr[i] > arr[j]) {
                LL t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
        }
    }
}

void insertion_sort(int *arr) {
    for (LL i=0; i<N-1; i++) {
        for (LL j=i+1; j<N-1; j++) {
            if (arr[i] > arr[j]) {
                LL t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
        }
    }
}

void quicksort_lomuto(int *arr, LL lo, LL hi) {
    if (lo < hi) {
        LL p = partition_lomuto(arr, lo, hi);
        quicksort_lomuto(arr, lo, p-1);
        quicksort_lomuto(arr, p+1, hi);
    }
}

LL partition_lomuto(int *arr, LL lo, LL hi) {
    int pivot = arr[hi];
    LL i = lo;
    for(LL j = lo; j<= hi-1; j++) {
        if(arr[j] < pivot) {
            int t = arr[j];
            arr[j] = arr[i];
            arr[i] = t;
            i++;
        }
    }
    int t = arr[hi];
    arr[hi] = arr[i];
    arr[i] = t;
    return i;
}

void quicksort_hoare(int *arr, LL lo, LL hi) {
    if (lo < hi) {
        LL p = partition_hoare(arr, lo, hi);
        quicksort_hoare(arr, lo, p);
        quicksort_hoare(arr, p+1, hi);
    }
}

LL partition_hoare(int *arr, LL lo, LL hi) {
    int pivot = arr[lo];
    LL i = lo-1;
    LL j = hi+1;
    while (1) {
        do {
            i++;
        } while (arr[i] < pivot);
        do {
            j--;
        } while (arr[j] > pivot);
        if (i >= j) return j;
        int t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }
}

void quicksort_randomize(int *arr, LL lo, LL hi) {
    if (lo < hi) {
        LL p = partition_randomize(arr, lo, hi);
        quicksort_randomize(arr, lo, p);
        quicksort_randomize(arr, p+1, hi);
    }
}

LL partition_randomize(int *arr, LL lo, LL hi) {
    LL pivot_index = (rand() % (hi-lo)) + lo;
    int pivot = arr[pivot_index];
    LL i = lo-1;
    LL j = hi+1;
    while (1) {
        do {
            i++;
        } while (arr[i] < pivot);
        do {
            j--;
        } while (arr[j] > pivot);
        if (i >= j) return j;
        int t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }
    return 0;
}

void print(int *arr) {
    LL end = N;
    for (LL i=0; i<end; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void print10(int *arr) {
 for (LL i=0; i<10; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;   
}
