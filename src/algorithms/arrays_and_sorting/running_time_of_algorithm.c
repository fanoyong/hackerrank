#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

void printAr(int ar_size, int * ar) {

    int i;
    for(i=0; i<ar_size; i++) {
        printf("%d ",ar[i]);
    }
    printf("\n");
}

void insertionSort(int ar_size, int *  ar) {
    int i,j;
    for(i=1; i<ar_size; i++) {
        int V = ar[i];
        for (j=i; j>0; j--) {
            ar[j] = ar[j-1];
            if( ar[j] < V) {
                ar[j] = V;
                break;
            } else {
                ar[j-1] = V;
            }
        }
        printAr(ar_size, ar);
    }
}

int insertionSort2(int ar_size, int *  ar) {
    int i,j,count;
    count = 0;
    for(i=1; i<ar_size; i++) {
        int V = ar[i];
        for (j=i; j>0; j--) {
            ar[j] = ar[j-1];
            if( ar[j] <= V) {
                ar[j] = V;
                break;
            } else {
                ar[j-1] = V;
            }
            count++;
        }
    }
    return count;
}
int main(void) {
    int _ar_size;
    int _count;
    scanf("%d", &_ar_size);
    int _ar[_ar_size], _ar_i;
    for(_ar_i = 0; _ar_i < _ar_size; _ar_i++) {
        scanf("%d", &_ar[_ar_i]);
    }
    _count = insertionSort2(_ar_size, _ar);
    printf("%d\n", _count);
   return 0;
}

