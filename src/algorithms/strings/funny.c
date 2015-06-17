#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    int T,len,i,A,B,flag;
    char in[10000];
    scanf("%d", &T);
    while(T--) {
        scanf("%s",in);
        len = strlen(in);
        flag = 0;
        for(i=1;i<len;i++) {
            A = abs(in[i] - in[i-1]);
            B = abs(in[len-i] - in[len-i-1]);
            //printf("A %c %c -> %d B %c %c -> %d\n", in[i], in[i-1], A, in[len-i], in[len-i+1], B);
            if(A!=B) {
                flag = 1;
                break;
            }
        }
        if(flag) {
            printf("Not Funny\n");
        } else {
            printf("Funny\n");
        }
    }
    return 0;
}
