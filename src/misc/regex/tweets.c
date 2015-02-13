#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define DEBUG 0

int isChar(char);
int isNum(char);
int isValid(char *);

int main () {
    int N;
    char input[200];
//    freopen("test.input", "r", stdin);
    setbuf(stdout, NULL);
    scanf("%d",&N);
    getchar();
#if DEBUG
    printf("N:%d\n", N);
#endif
    while(N-- > 0) {
        fgets(input, 200, stdin);
        if(isValid(input)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
#if DEBUG
        printf("N:%d\n", N);
#endif
    }
    return 0;
}

int isValid(char * input) {
    int ret =  strlen(input) == 11 &&
        isChar(input[0]) &&
        isChar(input[1]) &&
        isChar(input[2]) &&
        isChar(input[3]) &&
        isChar(input[4]) &&
        isNum(input[5]) &&
        isNum(input[6]) &&
        isNum(input[7]) &&
        isNum(input[8]) &&
        isChar(input[9]);
#if DEBUG
    printf("isValid: %d\n", ret);
#endif
    return ret;
}

int isChar(char c) {
    int ret;
    ret = c >= 'A' && c <= 'Z';
#if DEBUG
    printf("isChar c:%c\n", c);
    printf("isChar: %d\n", ret);
#endif
    return ret;
}

int isNum(char c) {
   int ret = c >= '0' && c <= '9';
#if DEBUG
    printf("isNum c:%c\n", c);
    printf("isNum: %d\n", ret);
#endif
    return ret;
}

