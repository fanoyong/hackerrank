#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int t;
    long n, c, m;
    long count=0, wrapper=0;
    scanf("%d", &t);
    while ( t-- )
    {
        scanf("%ld%ld%ld",&n,&c,&m);
        count = (long) n/c;
        wrapper = count;
        while (wrapper / m > 0) {
            count += (wrapper/m);
            wrapper = (wrapper/m) + (wrapper%m);
        }
        long answer = count;
        /** Write the code to compute the answer here. **/
        printf("%ld\n", answer);
    }
    return 0;
}

