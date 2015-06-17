#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define DEBUG 0

unsigned int gcd(unsigned int, unsigned int);

int main () {
    int N;
    unsigned int a,b;
    unsigned int answer;
    char input[200];
    setbuf(stdout, NULL);
    scanf("%d",&N);
#if DEBUG
    printf("N:%d\n", N);
#endif
    while(N-- > 0) {
        scanf("%u %u", &a, &b);
        answer = gcd(a,b);
#if DEBUG
        printf("gcd: %d\n", answer);
#endif
        printf("%d\n", (int)((a/answer) * (b/answer)));
    }
    return 0;
}

unsigned int gcd(unsigned int u, unsigned int v)
{
    // simple cases (termination)
    if (u == v)
        return u;
 
    if (u == 0)
        return v;
 
    if (v == 0)
        return u;
 
    // look for factors of 2
    if (~u & 1) // u is even
    {
        if (v & 1) // v is odd
            return gcd(u >> 1, v);
        else // both u and v are even
            return gcd(u >> 1, v >> 1) << 1;
    }
 
    if (~v & 1) // u is odd, v is even
        return gcd(u, v >> 1);
 
    // reduce larger argument
    if (u > v)
        return gcd((u - v) >> 1, v);
 
    return gcd((v - u) >> 1, u);
}
