#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

const int pi[29] = {3,1,4,1,5,
                9,2,6,5,3,
                5,8,9,7,9,
                3,2,3,8,4,
                6,2,6,4,3,
                3,8,3,3};


char *trimwhitespace(char *str) {
  char *end;

  // Trim leading space
  while(isspace(*str)) str++;

  if(*str == 0)  // All spaces?
    return str;

  // Trim trailing space
  end = str + strlen(str) - 1;
  while(end > str && isspace(*end)) end--;

  // Write new null terminator
  *(end+1) = 0;

  return str;
}

int main() {
    int T, index, flag,i;
    int nbytes = 100;
    char input[500];
    char *tok;
    scanf("%d\n",&T);
    while(T--) {
        index = 0;
        flag = 0;
        fgets(input, 500, stdin);
        tok = strtok(input, " ");
        while(tok != NULL) {
            tok = trimwhitespace(tok);
            //printf("%s index: %d len: %d pi[i]: %d\n", tok, index, (int)strlen(tok), pi[index]);
            if(strlen(tok) != pi[index++]) {
                flag = 1;
                printf("It's not a pi song.\n");
                break;
            }
            tok = strtok(NULL, " ");
        }
        if(!flag) {
            printf("It's a pi song.\n");
        }
    }
    return 0;
}
