#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define DEBUG 0

const int PATTERN_LEN = 10;
const char * PATTERN = "hackerrank";

int starts_with(const char *);
int ends_with(const char *);
void do_match();

int main () {
    int N;
    setbuf(stdout, NULL);
    scanf("%d",&N);
    getchar();
#if DEBUG
    printf("N:%d\n", N);
#endif
    while(N-- > 0) {
        do_match();
    }
    return 0;
}

int starts_with(const char * sentence) {
#if DEBUG
    printf("S[0]:%c\n", sentence[0]);
#endif
    if (strncmp(sentence, PATTERN, PATTERN_LEN) == 0) {
        return TRUE;
    }
    return FALSE;
}

int ends_with(const char * sentence) {
    int len = strlen(sentence);
#if DEBUG
    printf("S[0]:%c\n", sentence[0]);
    printf("len:%d\n", len);
    printf("S[s]:%c\n", sentence[len - PATTERN_LEN-1]);
#endif
    if (strncmp(sentence + len - PATTERN_LEN-1, PATTERN, PATTERN_LEN) == 0) {
        return TRUE;
    }
    return FALSE;
}

void do_match() {
    char input[2000];
#if DEBUG
    printf("do_match() START\n");
#endif
    fgets(input, sizeof(input), stdin);
    if (starts_with(input)) {
#if DEBUG
        printf("STARTSWITH\n");
#endif
        if (ends_with(input)) {
            printf("0\n");
        } else {
            printf("1\n");
        }
    } else if (ends_with(input)) {
#if DEBUG
        printf("ENDSWITH\n");
#endif
        printf("2\n");
    } else {
        printf("-1\n");
    }
#if DEBUG
    printf("do_match() end\n");
#endif
}
