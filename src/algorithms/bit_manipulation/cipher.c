#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define DEBUG 1

int char_to_int(char);

int main() {
    unsigned int N, N2, K, i, j;
    unsigned char * S;
    unsigned int answer[100000];
    unsigned int local_answer;
    scanf("%d %d", &N, &K);
    S = (char *)malloc(sizeof(char) * (N-K));
    scanf("%s", S);
    answer[0] = 1;
    for (i=1; i<N+K-1; i++) {
        N2 = (i < K )? i : K;
#if DEBUG
        printf("%d\n", N2);
#endif
        local_answer = char_to_int(S[i-1]);
        for (j=i-1; j<N2; j++) {
#if DEBUG
            printf("j=%d char=%d\n", j, answer[j]);
#endif
            local_answer = local_answer ^ char_to_int(answer[j]);
        }
        answer[i] = local_answer;
    }
    free(S);
    for (i=0;i<N; i++) {
        printf("%d",answer[i]);
    }
    printf("\n");
    return 0;
}

int char_to_int(char a) {
    return (a=='1') ? 1:0;
}

