#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE -1
#define DEBUG 0

void do_match(const char *);
int first_char(const char *);
int num_digit(const char *, int);
int last_char(const char *, int);
int is_lower_char(const char);
int is_upper_char(const char);
int is_digit(const char);

int main () {
    int N;
    char input[200];
    setbuf(stdout, NULL);
    scanf("%d",&N);
    getchar();
#if DEBUG
    printf("N:%d\n", N);
#endif
    while(N-- > 0) {
        fgets(input, sizeof(input), stdin);
        do_match(input);
    }
    return 0;
}

void do_match(const char * input) {
    int index;
    if ((index = first_char(input)) == FALSE ||
        (index = num_digit(input, index)) == FALSE ||
        last_char(input, index) == FALSE) {
        printf("INVALID\n");
        return;
    }
    printf("VALID\n");
}

int first_char(const char * input) {
    int index;
    for (index = 0; index<3; index++) {
        if (is_digit(input[index]) != FALSE) {
#if DEBUG
            printf("first_char return index:%d\n", index);
#endif
            return index;
        } else if (is_lower_char(input[index]) == FALSE ) {
#if DEBUG
            printf("first_char return false %d\n", index);
#endif
            return FALSE;
        }
    }
#if DEBUG
        printf("first_char index:%d\n", index);
#endif
    return index;
}

int num_digit(const char * input, int index) {
#if DEBUG
    printf("num start with index:%d\n", index);
#endif
    int index2;
    for (index2 = index; index2 < index+8; index2++) {
        if (is_digit(input[index2]) == FALSE) {
            if (index2 < index+2) {
#if DEBUG
                printf("num_digit: return FALSE\n");
#endif
                return FALSE;
            } else {
#if DEBUG
                printf("num_digit: return index:%d\n", index2);
#endif
                return index2;
            }
        }
    }
#if DEBUG
    printf("num_digit END: return index:%d\n", index2);
#endif
    return index2;
}

int last_char(const char * input, int index) {
    int i;
    int len = strlen(input);
#if DEBUG
    printf("last_char len:%d index:%d\n", len, index);
#endif
    if (len - index < 3) {
#if DEBUG
        printf("last_char: insifficient upper character lenght. return FALSE\n");
#endif
        return FALSE;
    }
    for (i = index; i<len-1; i++) {
#if DEBUG
        printf("char:[%c] index:%d \n", input[i], i);
#endif
        if (is_upper_char(input[i]) == FALSE) {
#if DEBUG
            printf("i:%d input[i]:%c \n", i, input[i]);
            printf("last_char:[%c] is not upper character. return FALSE\n", input[i]);
#endif
            return FALSE;
        }
    }
#if DEBUG
    printf("last_char: return TRUE");
#endif
    return TRUE;
}

int is_lower_char(const char c) {
    return (c >= 'a' && c <= 'z') ? TRUE:FALSE;
}

int is_upper_char(const char c) {
    return (c >= 'A' && c <= 'Z') ? TRUE:FALSE;
}

int is_digit(const char c) {
    return (c >= '0' && c <= '9') ? TRUE:FALSE;
}
