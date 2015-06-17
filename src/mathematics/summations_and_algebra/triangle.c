#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define DEBUG 0


int main () {
    int N;
    int row;
    setbuf(stdout, NULL);
    scanf("%d",&N);
#if DEBUG
    printf("N:%d\n", N);
#endif
    while(N-- > 0) {
        scanf("%d",&row);
        if (row == 1 || row == 2) {
            printf("-1\n");
        } else {
            switch ((row-2) % 4) {
                case 1:
                case 3:
                    printf("2\n");
                    break;
                case 2:
                    printf("3\n");
                    break;
                case 0:
                    printf("4\n");
                    break;
            }
        }
    }
    return 0;
}

