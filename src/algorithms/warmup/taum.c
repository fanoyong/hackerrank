#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int T;
    long long int B,W;
    long long int X,Y,Z;
    long long int XX, YY;
    scanf("%d",&T);
    while(T--) {
        scanf("%lld %lld", &B, &W);
        scanf("%lld %lld %lld", &X, &Y, &Z);
        XX = X;
        YY = Y;
        if ((X+Z) < Y) {
            YY = X+Z;
        } 
        if ((Y+Z) < X) {
            XX = Y+Z;
        }
        printf("%lld\n", B*XX + W*YY);
    }
    return 0;
}

