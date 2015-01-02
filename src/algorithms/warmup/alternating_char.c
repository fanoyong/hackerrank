#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main () {
    int T;
    int i;
    int c, oldc;
    int count;
    scanf("%d", &T);
    getc(stdin);
    for (i=0; i<T; i++) {
        oldc = -99;
        count = 0;
        while(1) {
            c=getc(stdin);
            if (c=='\n' || c=='\r' || c==EOF) {
                break;
            }
            if (c==oldc) {
                count++;
            }
            oldc = c;
        }
        printf("%d\n", count);
    }
    return 0;
}
