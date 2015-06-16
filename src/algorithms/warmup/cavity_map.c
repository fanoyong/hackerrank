#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

char data[101][101];

int check(int i, int j) {
    int cur = data[i][j];
    return (data[i][j-1] < cur && data[i][j+1] < cur && data[i-1][j] < cur && data[i+1][j] < cur);
}

int main() {
    int N;
    int i,j;
    scanf("%d",&N);
    for(i=0; i<N; i++) {
        scanf("%s", data[i]);
    }
    for(i=1;i<N-1;i++) {
        for(j=1;j<N-1;j++) {
            if(check(i,j)) {
                data[i][j] = 'X';
            }
        }
    }
    
    for(i=0;i<N;i++) {
        puts(data[i]);
    }
    return 0;
}

