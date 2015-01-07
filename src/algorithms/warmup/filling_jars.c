#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    long N,M;
    long a,b,k;
    long answer = 0;
    int i;
    scanf("%ld %ld", &N, &M);
    for (i=0; i<M; i++)
    {
        scanf("%ld %ld %ld", &a, &b, &k);
        answer += (b-a+1) * k;
    }
    printf ("%ld\n", (long) answer/N);
    return 0;
}

