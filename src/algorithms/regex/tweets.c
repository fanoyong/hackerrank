#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define DEBUG 0

const int TWEET_LEN = 10;
const char TWEET_KEYWORD[11] = "hackerrank";

int isValid(char *);
int isTweetMatch(char *, int);

int main () {
    int N;
    char input[2000];
    int count;
//    freopen("test.input", "r", stdin);
    setbuf(stdout, NULL);
    scanf("%d",&N);
    getchar();
#if DEBUG
    printf("N:%d\n", N);
#endif
    count = 0;
    while(N-- > 0) {
        fgets(input, sizeof(input), stdin);
#if DEBUG
        printf("main input: %s\n", input);
#endif
        if(isValid(input)) {
            count++;
        }
    }
    printf("%d\n", count);
    return 0;
}

int isValid(char * input) {
    int ret = FALSE;
    int len = strlen(input);
    int i;
#if DEBUG
    printf("isValid: input:%s len:%d\n", input, len);
#endif
    for (i=0; i<len; i++) {
        if ((input[i] == 'h' || input[i] == 'H') && (len-i) >= TWEET_LEN) {
            if (isTweetMatch(input, i)) {
#if DEBUG
                printf("Match!\n");
#endif
               return TRUE;
            } else {
#if DEBUG
                printf("Not match\n");
#endif
                i += TWEET_LEN;
            }
        }
    }
#if DEBUG
    printf("isValid: %d\n", ret);
#endif
    return ret;
}

int isTweetMatch (char * input, int index) {
    int i;
    for (i=0; i< TWEET_LEN; i++) {
#if DEBUG
        printf("Character %c=%d\n", input[i+index], input[i+index]);
        printf("a = %c=%d\n", 'a', 'a');
#endif
        if (input[i+index] < 'a') {
#if DEBUG
            printf("Capital character: %c\n", input[i+index]);
#endif
            input[i+index] += ('a' - 'A');
#if DEBUG
            printf("input is %c:%d\n", input[i+index], input[i+index]);
#endif
        }
        if(input[i+index] != TWEET_KEYWORD[i]) {
#if DEBUG
            printf("Return false\n");
#endif
            return FALSE;
        }
    }
    return TRUE;
}
