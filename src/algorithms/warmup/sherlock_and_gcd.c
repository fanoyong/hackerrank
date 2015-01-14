#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int gcd (int n, int A[]) {
    int i,j;
    int max, min;
    while(1) {
       max = 0;
        min = 100001;
        for (i=0; i<n; i++) {
            if (A[i] < min) {
                min = A[i];
                j = i;
            }
            if (A[i] > max) {
               max = A[i];
            }
        }
        if (max == min) {
            return min;
        }
        for (i=0;i<n;i++) {
            if (i!=j && A[i] != A[j]) A[i] -= min;
        }
    }
    return 1;
}

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
        if (gcd(n, A) == 1) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}

