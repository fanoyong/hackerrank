#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


long long N[101];

void generateFibo() {
    int i;
    N[0] = 0;
    N[1] = 1;
    for (i=2; i<101; i++) {
        N[i] = 0;
        N[i] = N[i-2] + N[i-1];
    }
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    long long T;
    long long I;
    int i, j;
    generateFibo();
    scanf("%lld", &T);
    for (i=0; i<T; i++) {
        scanf("%lld", &I);
        for (j=0; j< 101; j++) {
            if (N[j] > I) {
                printf("IsNotFibo\n");
                break;
            } else if (N[j] == I) {
                printf("IsFibo\n");
                break;
            }
        }
        if (j==101) {
            printf("IsNotFibo\n");
        }
    }
    return 0;
}

