#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int t;
    long n, c, m;
    scanf("%d", &t);
    while ( t-- )
    {
        scanf("%ld%ld%ld",&n,&c,&m);
        long count = (long) (n/c);
        long bonus = ((long) (n/c)) / m;
        long bonus_extra = ((((long) (n/c)) % m) + bonus) / m;
        long answer = count + bonus + bonus_extra;
        /** Write the code to compute the answer here. **/
        printf("%ld\n", answer);
    }
    return 0;
}

