#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int T, N, K;
    int student;
    int count;
    int i;
    scanf("%d", &T);
    while(T--) {
        scanf("%d %d", &N, &K);
        count = 0;
        for(i=0;i<N;i++) {
            scanf("%d", &student);
            if(student < 1) {
                count++;
            }
        }
        if(K <= count) {
            printf("NO\n");
        } else {
            printf("YES\n");
        }
    }
    return 0;
}

