#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int isSmith(unsigned long int N) {
    int A=0, B=0;
    unsigned long int N2 = N;
    unsigned long int i,j;
    while (N2 != 0) {
        A+=(N2%10);
        N2/=10;
    }
    int flag = 0;
    for(i=2;i<=N;i++) {
        if (N%i==0) {
            if (i!=N) {
                flag = 1;
            }
            //printf("N:%ld B:%d i:%ld\n", N, B, i);
            j = i;
            while (j != 0) {
                B+= (j%10);
                j/=10;
            }
            N/=i;
            i--;
        }
    }
    //printf("%d %d\n", A, B);
    return (A==B && flag) ? 1:0;
}

int main() {
    unsigned long int N;
    scanf("%ld", &N);
    if(isSmith(N)) {
        printf("1\n");
    } else {
        printf("0\n");
    }
    return 0;
}
