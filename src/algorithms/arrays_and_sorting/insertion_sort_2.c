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
    for(j=1; j<ar_size; j++) {
        int V = ar[j];
        ar[ar_size-1] = ar[ar_size-2];
        for(i=j; i<ar_size; i++) {
            //printf("i %d ar[i] %d V %d\n",i, ar[i-1], V);
            if(ar[i-1] < V) {
                ar[i] = V;
                printAr(ar_size, ar);
                break;
            }
            ar[i] = ar[i-1];
        }
    }

}

int main(void) {
    int _ar_size;
    scanf("%d", &_ar_size);
    int _ar[_ar_size], _ar_i;
    for(_ar_i = 0; _ar_i < _ar_size; _ar_i++) {
        scanf("%d", &_ar[_ar_i]);
    }
    insertionSort(_ar_size, _ar);
   return 0;
}

