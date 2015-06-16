#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int N, T;
    int answer[1000];
    int lane[100000];
    int i;
    int min;
    int a,b;
    int index =0;
    scanf("%d %d", &N, &T);
    for(i=0;i<N;i++) {
        scanf("%d", &lane[i]);
    }
    while(T--) {
        min = 9999;
        scanf("%d %d", &a, &b);
        for(i=a; i<=b;i++) {
            if(lane[i] < min) {
                min = lane[i];
            }
        }
        answer[index++] = min;
    }
    for(i=0; i<index; i++) {
        printf("%d\n", answer[i]);
    }
    return 0;
}

