#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    char answer[100001];
    int T, N;
    int i,j;
    int digit_3, digit_5, count;
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&N);
        digit_3 = -1;
        digit_5 = -1;
        for (i=(N/3)+1; i--; i>=0) {
            if((N-3*i)%5 == 0) {
                j = (N-3*i) / 5;
            }
            if (i*3+j*5 == N) {
                digit_3 = j;
                digit_5 = i;
                break;
            }
        }
        count = 0;
        for (i=0; i<digit_5; i++) {
            answer[count++] = '5';
            answer[count++] = '5';
            answer[count++] = '5';
        }
        for (j=0; j<digit_3; j++) {
            answer[count++] = '3';
            answer[count++] = '3';
            answer[count++] = '3';
            answer[count++] = '3';
            answer[count++] = '3';
        }
        answer[count++] = '\0';
        if (digit_3 == -1 && digit_5 == -1) {
            printf("%d\n", -1);
        } else {
            printf("%s\n", answer);
        }
    }
    return 0;
}
