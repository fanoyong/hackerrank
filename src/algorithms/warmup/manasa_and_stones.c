#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int i,j;
    int T, n, a, b, t;
    scanf("%d",&T);
    while (T--) {
        scanf("%d %d %d", &n, &a, &b);
        if (a>b) {
            t = a;
            a = b;
            b = t;
        }
        if (a==b) {
            printf ("%d", a*(n-1));
        } else {
        for (i=0; i<n; i++) {
            printf("%d ", a*(n-i-1)+b*i);
        }
        }
        printf("\n");
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}

