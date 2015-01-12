#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int T;
    long A,B;
    int a,b;
    scanf("%d",&T);
    while (T--) {
        scanf("%ld %ld", &A, &B);
        a = (int) pow(A,0.5);
        b = (int) pow(B,0.5);
        int answer = b-a;
        if (A == (int) pow(a,2)) {
            answer++;
        }
        printf("%d\n", answer);
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}

