#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX 100000
#define MAX_VAL 1000000001

int candies[MAX];

/** The code to read from STDIN and output to STDOUT has been provided by us, for convenience. You may or may not use this. **/

void swap_r(int r[], int a, int b)
{
    int temp = r[a];
    r[a] = r[b];
    r[b] = temp;
}

void quick(int r[], int start, int end)
{
    if(end > start)
    {
        int pivot_index = (start + end) / 2;
        int pivot = r[pivot_index];
        int chg, i;
        
        swap_r(r, pivot_index, end);
        
        for(i = chg = start; i < end; i++)
        {
            if(r[i] < pivot)
            {
                swap_r(r, i, chg);
                chg++;
            }
        }
        
        swap_r(r, chg, end);
        
        quick(r, start, chg - 1);
        quick(r, chg + 1, end);
    }
}

int main() {
    
    int N,K;
    int i,j,k;
    int temp;
    int min, max;
    scanf("%d %d",&N,&K);
    for(i = 0;i < N;i++) {
        scanf("%d",candies + i);
    }
    int unfairness = MAX_VAL; // Compute the min unfairness over here, using N,K,candies
    quick(candies, 0, N);
    min = (int) MAX_VAL-1;
    max = (int) -MAX_VAL+1;
    for(j=0; j<N-K; j++) {
        max = candies[j+K-1];
        min = candies[j];
        if (unfairness > (max - min)) {
            unfairness = max-min;
        }
    }
    printf("%d\n",unfairness);
    return 0;
}

