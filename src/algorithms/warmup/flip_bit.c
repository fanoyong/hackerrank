#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int i;
    int T;
    unsigned int N;
    scanf("%d", &T);
    for (i=0; i<T; i++)
    {
        scanf("%d",&N);
        printf("%u\n",~N);
    }
    return 0;
}

