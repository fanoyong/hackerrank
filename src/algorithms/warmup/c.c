#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int N[60];

int main() {
    int i;
    int T;
    int n;

    N[0] = 1;
    for (i=1;i<=59;i +=2) {
        N[i] = N[i-1] * 2;
        N[i+1] = N[i] + 1;
    }
    scanf("%d", &T);
    for (i=0;i<T;i++) {
        scanf("%d", &n);
        printf("%d\n", N[n]);
    }
    return 0;
}

