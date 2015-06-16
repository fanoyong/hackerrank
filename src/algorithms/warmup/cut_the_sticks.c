#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int N;
    int sticks[1000];
    int i;
    int count;
    int min;
    scanf("%d", &N);
    count = N;
    for(i=0; i<N; i++) {
        scanf("%d", &sticks[i]);
    }
    printf("%d\n", N);
    while (count) {
        count = 0;
        min = 9999;
        for(i=0; i<N; i++) {
            if(sticks[i] > 0 && sticks[i] < min) {
                min = sticks[i];
            }
        }
        for(i=0;i<N; i++) {
            if (sticks[i] > 0) {
                sticks[i] -= min;
            }
            if (sticks[i] > 0) {
                count++;
            }
        }
        if (count > 0) {
            printf("%d\n", count);
        }
    }
    return 0;
}

