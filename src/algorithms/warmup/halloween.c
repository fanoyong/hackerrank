#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int i;
    int T,K;
    scanf("%d", &T);
    for (i=0;i<T;i++) {
        scanf("%d", &K);
        if (K%2 == 1) {
            printf("%d\n", (K-1)/2 * ((K-1)/2 + 1));
        } else {
            printf("%d\n", K*K/4);
        }
    }
    return 0;
}

