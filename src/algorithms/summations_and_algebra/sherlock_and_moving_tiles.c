#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define DEBUG 0

int is_pangram(char *);

int main () {
    int N;
    char input[200];
    setbuf(stdout, NULL);
    fgets(input, 200, stdin);
    if (is_pangram(input)) {
        printf("pangram\n");
    } else {
        printf("not pangram\n");
    }
    return 0;
}

int is_pangram(char * input) {
    int i;
    int len = strlen(input);
    int num_alphabet = (int)'z'-'a';
    int * alphabet_count = (int *) calloc(num_alphabet, sizeof(int));

    for(i=0;i<len;i++) {
        if(input[i] >= 'a' && input[i] <= 'z') {
            alphabet_count[(int) (input[i]-'a')]++;
        } else if(input[i] >= 'A' && input[i] <= 'Z') {
            alphabet_count[(int) (input[i]-'A')]++;
        } else {
            // Do nothing
        }
    }
    for(i=0; i<num_alphabet; i++) {
        if(alphabet_count[i] == 0) {
            return FALSE;
        }
    }
    free(alphabet_count);
    return TRUE;
}
