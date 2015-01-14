#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int i,j,t;
    int T, n, A[100];
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        for (i=0; i<n; i++) {
            scanf("%d", &t);            
            A[i] = t; 
        }
        t = 0;
        while (A[t] <= 1) {
            t++;        
        }
        for (i=1; i<n; i++) {
            if (A[i]%A[t] != 0) {
                printf("YES\n");
                break;
            }
        }
        if (i==n) {
            printf("NO\n");
        }
    }
    return 0;
}

