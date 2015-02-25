#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define DEBUG 0

void parse_and_print(char *);
void preprocess(char *);
int is_valid(double x, double y);
int is_valid_number(char * x);

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
        preprocess(input);
        parse_and_print(input);
#if DEBUG
        printf("N:%d\n", N);
#endif
    }
    return 0;
}

void parse_and_print (char * input) {
    double x = 0, y = 0;
    char * token = strtok(input, ", ");

#if DEBUG
    printf("input: [%s]\n", input);
    printf("x str:%s\n", token);
#endif
    if (is_valid_number(token) == FALSE) {
        printf("Invalid\n");
        return;
    }
    x = strtod(token, NULL);
    token = strtok(NULL, ", ");
#if DEBUG
    printf("y str:%s\n", token);
#endif
    if(is_valid_number(token) == FALSE) {
        printf("Invalid\n");
        return;
    }
    y = strtod(token, NULL);
#if DEBUG
    printf("x: %f y: %f\n",x,y);
#endif
    if(is_valid(x,y)) {
        printf("Valid\n");
    } else {
        printf("Invalid\n");
    }
}

void preprocess(char * input) {
    int i;
    int len = strlen(input);
    for (i=0; i<len-2; i++) {
        input[i] = input[i+1];
    }
    input[len-3] = '\0';
}

int is_valid(double x, double y) {
    int ret = (x >= -90 && x <= 90 && y >= -180 && y <= 180) ? TRUE:FALSE;
#if DEBUG
    printf("%d\n", ret);
#endif
    return ret;
}

int is_valid_number(char * x) {
    int len = strlen(x);
#if DEBUG
    printf("input for num: [%s]\n", x);
    printf("first: %c, last:%c\n", x[0], x[len-1]);
#endif
    if (x[0] == '+' || x[0] == '-') {
        return (x[1] >= '1' && x[1] <= '9' && x[len-1] >= '0' && x[len-1] <= '9') ? TRUE:FALSE;
    }
    return (x[0] >= '1' && x[0] <= '9' && x[len-1] >= '0' && x[len-1] <= '9') ? TRUE:FALSE;
}
