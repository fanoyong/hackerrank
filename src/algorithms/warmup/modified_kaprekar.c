#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    long long int x, a,b, d, data[100000];
    int A,B,i,digit,count;
    scanf("%d %d", &A, &B);
    count = 0;
    data[count++] = 1;
    data[count++] = 9;
    for(i=10;i<=1000000;i++) {
        x = pow(i,2);
        digit = floor (log10 (abs (x))) + 1;
        if(digit%2 == 0) {
            d = pow(10,(digit/2)-2);
            if (d!=0) {
                a = x/d;
                b = x%d;
                if (a+b == i && a != 0 && b != 0) {
//                    printf("found case#3 %d d=%lld, digit=%d, x=%lld a=%lld b=%lld\n", i,d,digit,x,a,b);
                    data[count++] = i;
                }
            }
            d = pow(10,(digit/2)-1);
            if (d!=0) {
                a = x/d;
                b = x%d;
                if (a+b == i && a != 0 && b != 0) {
//                    printf("found case#1 %d d=%lld, digit=%d, x=%lld a=%lld b=%lld\n", i,d,digit,x,a,b);
                    data[count++] = i;
                }
            }
            d = pow(10,(digit/2));
            if (d!=0) {
                a = x/d;
                b = x%d;
                if (a+b == i && a != 0 && b != 0) {
//                    printf("found case#2 %d d=%lld, digit=%d, x=%lld a=%lld b=%lld\n", i,d,digit,x,a,b);
                    data[count++] = i;
                }
            }
            d = pow(10,(digit/2)+1);
            if (d!=0) {
                a = x/d;
                b = x%d;
                if (a+b == i && a != 0 && b != 0) {
//                    printf("found case#3 %d d=%lld, digit=%d, x=%lld a=%lld b=%lld\n", i,d,digit,x,a,b);
                    data[count++] = i;
                }
            }
            d = pow(10,(digit/2)+2);
            if (d!=0) {
                a = x/d;
                b = x%d;
                if (a+b == i && a != 0 && b != 0) {
//                    printf("found case#3 %d d=%lld, digit=%d, x=%lld a=%lld b=%lld\n", i,d,digit,x,a,b);
                    data[count++] = i;
                }
            }
        } else {
            d = pow(10,(digit/2)-2);
            if (d!=0) {
                a = x/d;
                b = x%d;
                if (a+b == i && a != 0 && b != 0) {
//                    printf("found case#3 %d d=%lld, digit=%d, x=%lld a=%lld b=%lld\n", i,d,digit,x,a,b);
                    data[count++] = i;
                }
            }
            d = pow(10,(digit/2)-1);
            if (d!=0) {
                a = x/d;
                b = x%d;
                if (a+b == i && a != 0 && b != 0) {
//                    printf("found case#3 %d d=%lld, digit=%d, x=%lld a=%lld b=%lld\n", i,d,digit,x,a,b);
                    data[count++] = i;
                }
            }
            d = pow(10,(digit/2));
            if (d!=0) {
                a = x/d;
                b = x%d;
                if (a+b == i && a != 0 && b != 0) {
//                    printf("found case#3 %d d=%lld, digit=%d, x=%lld a=%lld b=%lld\n", i,d,digit,x,a,b);
                    data[count++] = i;
                }
            }
            d = pow (10, (digit/2)+1);
            if (d!=0) {
                a = x/d;
                b = x%d;
                if (a+b == i && a != 0 && b != 0) {
//                    printf("found case#4 %d d=%lld, digit=%d, x=%lld a=%lld b=%lld\n", i,d,digit,x,a,b);
                    data[count++] = i;
                }
            }
            d = pow (10, (digit/2)+2);
            if (d!=0) {
                a = x/d;
                b = x%d;
                if (a+b == i && a != 0 && b != 0) {
//                    printf("found case#5 %d d=%lld, digit=%d, x=%lld a=%lld b=%lld\n", i,d,digit,x,a,b);
                    data[count++] = i;
                }
            }
        }
    }
    for(i=0;i<=count;i++) {
        if (data[i] >= A && data[i] <= B) {
            printf("%lld\n", data[i]);
        }
    }
    return 0;
}

