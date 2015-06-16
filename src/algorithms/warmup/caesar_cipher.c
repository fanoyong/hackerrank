#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    char input[101];
    int N,K,i, alpha_count;
    scanf("%d %s %d", &N, input, &K);
    alpha_count = (int) ('z' - 'a' + 1);
    K %= alpha_count;
    for (i=0;i<N;i++) {
        if(input[i] >= 'a' && input[i] <= 'z') {
            if (input[i] + K > 'z') {
                input[i] += (K-alpha_count);
            } else {
                input[i] += K;
            }
        } else if (input[i] >= 'A' && input[i] <= 'Z') {
            if (input[i] + K > 'Z') {
                input[i] += (K-alpha_count);
            } else {
                input[i] += K;
            }
        }
    }
    puts(input);
    return 0;
}

