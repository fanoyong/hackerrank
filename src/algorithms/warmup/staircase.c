#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    char a[101];
    int i,j,N;
    scanf("%d", &N);
    for(i=1;i<=N;i++) {
        for(j=0;j<N-i;j++) {
            a[j] = ' ';
        }
        for(j=N-i;j<N;j++) {
            a[j] = '#';
        }
        a[N] = '\0';
        puts(a);
    }

    return 0;
}

