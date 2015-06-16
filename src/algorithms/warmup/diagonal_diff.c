#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int N;
    int i, j;
    int A=0,B=0;;
    int data[100][100];
    scanf("%d",&N);
    for(i=0;i<N;i++) {
        for(j=0;j<N;j++) {
            scanf("%d",&data[i][j]);
        }
    }
    for(i=0;i<N;i++) {
        A += data[i][i];
        B += data[N-i-1][i];
    }
    printf("%d\n", abs(A-B));
    return 0;
}

