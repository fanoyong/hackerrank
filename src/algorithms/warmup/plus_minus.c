#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int N,num;
    int i;
    int count_p=0, count_n=0, count_z=0;;
    scanf("%d",&N);
    for(i=0;i<N;i++) {
        scanf("%d",&num);
        if(num > 0) {
            count_p++;
        } else if (num == 0) {
            count_z++;
        } else {
            count_n++;
        }
    }
    printf("%.3f\n", (double) count_p/N);
    printf("%.3f\n", (double) count_n/N);
    printf("%.3f\n", (double) count_z/N);
    return 0;
}

