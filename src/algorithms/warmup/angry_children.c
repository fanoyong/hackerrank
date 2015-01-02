#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX 100000
#define MAX_VAL 1000000001

int candies[MAX];

/** The code to read from STDIN and output to STDOUT has been provided by us, for convenience. You may or may not use this. **/
 
int main() {
    
    int N,K;
    int i;
    
    scanf("%d %d",&N,&K);
    for(i = 0;i < N;i++)
        scanf("%d",candies + i);
  
    int unfairness = // Compute the min unfairness over here, using N,K,candies
        
    printf("%d",unfairness);
    return 0;
}

