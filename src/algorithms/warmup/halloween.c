#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    long i;
    long T,K;
    scanf("%ld", &T);
    for (i=0;i<T;i++) {
        scanf("%ld", &K);
        if (K%2 == 1) {
            printf("%ld\n", (K-1)/2 * ((K-1)/2 + 1));
        } else {
            printf("%ld\n", K*K/4);
        }
    }
    return 0;
}

