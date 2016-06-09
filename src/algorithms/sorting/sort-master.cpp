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
void merge_sort(int *arr, int *arr2);
void merge_sort_split(int *arr, LL, LL, int *arr2);
void merge_sort_merge(int *arr, LL begin, LL middle, LL end, int *arr2);
void merge_sort_copy(int *arr2, LL, LL, int *arr1);
void heap_sort(int *arr);
void build_max_heap(int *arr);
void max_heapify(int * arr, int i, int heap_size);
void print(int *arr);
void print10(int *arr);


int main() {
    int data_random[N], data_reverse[N], data_nearly[N], data_sorted[N];
    srand(time(0));
    for(LL i=0; i<N; i++) {
        int RAND = rand();
        int REVERSE = N-i;
        data_random[i] = RAND;
        data_reverse[i] = REVERSE;
        data_nearly[i] = i;
        data_sorted[i] = i;
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
    cout << "starting comparison: fully sorted data" << endl;
    compare(data_sorted);
    return 0;
}

void compare(int *data) {
    int arr_lomuto[N], arr_hoare[N], arr_randomize[N], arr_heap[N];
    int arr_bubble[N], arr_insert[N], arr_merge1[N], arr_merge2[N];
    for(LL i=0; i<N; i++) {
        arr_bubble[i] = data[i];
        arr_insert[i] = data[i];
        arr_lomuto[i] = data[i];
        arr_hoare[i] = data[i];
        arr_randomize[i] = data[i];
        arr_merge1[i] = data[i];
        arr_merge2[i] = data[i];
        arr_heap[i] = data[i];
    }

#if DEBUG
    print10(arr_bubble);
    print10(arr_insert);
    print10(arr_lomuto);
    print10(arr_hoare);
    print10(arr_randomize);
    print10(arr_merge1);
    print10(arr_heap);
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

    clock_t begin6 = clock();
    merge_sort(arr_merge1, arr_merge2);
    clock_t end6 = clock();
    double elapsed_secs6 = double(end6 - begin6) / CLOCKS_PER_SEC;
    cout << "Merge sort took: " << elapsed_secs6 << endl;

    clock_t begin7 = clock();
    heap_sort(arr_heap);
    clock_t end7 = clock();
    double elapsed_secs7 = double(end7 - begin7) / CLOCKS_PER_SEC;
    cout << "Heap sort took: " << elapsed_secs7 << endl;

#if DEBUG
    print10(arr_bubble);
    print10(arr_insert);
    print10(arr_lomuto);
    print10(arr_hoare);
    print10(arr_randomize);
    print10(arr_merge1);
    print10(arr_heap);
#endif
    cout << endl;
}

void bubble_sort(int *arr) {
    for (LL i=0; i<N; i++) {
        for (LL j=0; j<N-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                LL t = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = t;
            }
        }
    }
}

void insertion_sort(int *arr) {
    for (LL i=0; i<N; i++) {
        for (LL j=i; j<N; j++) {
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

void merge_sort(int *arr, int *arr2) {
    merge_sort_split(arr, 0, N, arr2);
}

void merge_sort_split(int *arr, LL begin, LL end, int *arr2) {
    if (end - begin < 2) {
        return;
    }
    LL middle = (begin + end) / 2;
    merge_sort_split(arr, begin, middle, arr2);
    merge_sort_split(arr, middle, end, arr2);
    merge_sort_merge(arr, begin, middle, end, arr2);
    merge_sort_copy(arr2, begin,  end, arr);
}

void merge_sort_merge(int *arr, LL begin, LL middle, LL end, int *arr2) {
    LL i = begin;
    LL j = middle;
    for (LL k = begin; k < end; k++) {
        if (i >= middle) {
            while (k < end) {
                arr2[k++] = arr[j++];
            }
        } else if (j >= end) {
            while (k < end) {
                arr2[k++] = arr[i++];
            }
        } else if (arr[i] < arr[j]) {
            arr2[k] = arr[i++];
        } else {
            arr2[k] = arr[j++];
        }
    }
}

void merge_sort_copy(int *arr2, LL begin, LL end, int *arr) {
    for (LL i = begin; i<end; i++) {
        arr[i] = arr2[i];
    }
}

void heap_sort(int *arr) {
    LL heap_size = N;
    build_max_heap(arr);
    for (LL i = N-1; i>=1; i--) {
        int t = arr[i];
        arr[i] = arr[0];
        arr[0]  = t;
        heap_size--;
        max_heapify(arr, 0, heap_size);
    }
}

void build_max_heap(int *arr) {
    for (LL i = N/2; i>=0; i--) {
        max_heapify(arr, i, N);
    }
}

void max_heapify(int *arr, int i, int heap_size) {
    LL left = 2*(i+1) - 1;
    LL right = 2*(i+1);
    int largest;
    if (left < heap_size && arr[left] > arr[i]) {
        largest = left;
    } else {
        largest = i;
    }
    if (right < heap_size && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != i) {
        int t = arr[i];
        arr[i] = arr[largest];
        arr[largest] = t;
        max_heapify(arr, largest, heap_size);
    }
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
