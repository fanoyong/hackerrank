#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int i, j;
    int T;
    int count;
    int length;
    char S[10000];

    scanf("%d", &T);
    for (i=0; i<T; i++) {
        scanf("%s", S);
        count=0;
        length = strlen(S);
        for (j=0;j<length/2; j++) {
            count += abs(S[j] - S[length-j-1]);
        }
        printf("%d\n", count);
    }
    return 0;
}

