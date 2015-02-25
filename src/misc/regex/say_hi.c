#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define DEBUG 0

int is_valid(char *);

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
        if (is_valid(input)) {
            printf("%s\n", input);
        }
#if DEBUG
        printf("N:%d\n", N);
#endif
    }
    return 0;
}

int is_valid(char * input) {
#if DEBUG
    printf("0:%c 1:%c 2:%c 3:%c\n", input[0], input[1], input[2], input[3]);
#endif
    if ((input[0] != 'h' && input[0] != 'H') ||
        (input[1] != 'i' && input[1] != 'I') ||
        input[2] != ' ' ||
        (input[3] == 'd' || input[3] == 'D')) {
#if DEBUG
    printf("FALSE\n");
#endif
        return FALSE;
    }
#if DEBUG
    printf("TRUE\n");
#endif
    return TRUE;
}
