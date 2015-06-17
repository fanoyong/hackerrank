#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define DEBUG 0

void parse_and_print(char *);

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
        parse_and_print(input);
#if DEBUG
        printf("N:%d\n", N);
#endif
    }
    return 0;
}

void parse_and_print(char *input) {
    char country_code[200];
    char area_code[200];
    char number[200];
    char * matches;
#if DEBUG
    printf("Input %s\n", input);
#endif
    matches = strtok (input, " -");
#if DEBUG
    printf("Country code:%s\n", matches);
#endif
    strcpy(country_code, matches);
    matches = strtok (NULL, " -");
#if DEBUG
    printf("Area code:%s\n", matches);
#endif
    strcpy(area_code, matches);
    matches = strtok (NULL, " -");
#if DEBUG
    printf("Number:%s\n", matches);
#endif
    strcpy(number, matches);
    printf("CountryCode=%s,LocalAreaCode=%s,Number=%s", country_code, area_code, number);
}
