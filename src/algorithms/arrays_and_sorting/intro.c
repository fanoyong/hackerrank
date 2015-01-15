
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int V, n;
    int i,t;
    scanf("%d %d", &V, &n);
    for (i=0; i<n; i++) {
        scanf("%d", &t);
        if(V==t) {
            printf("%d\n",i);
            return 0;
        }
    }
    printf("\n");
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}

