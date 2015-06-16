#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    char input[11];
    int carriage;
    scanf("%s", input);
    if(input[0] == '1' && input[1] == '2') {
        if ((input[8] == 'A' || input[8] == 'a')) {
            input[0] = '0';
            input[1] = '0';
        }
    } else {
        if ((input[8] == 'P' || input[8] == 'p')) {
            switch (input[1]) {
                case '8':
                    input[1] = '0';
                    carriage = 1;
                    break;
                case '9':
                    input[1] = '1';
                    carriage = 1;
                    break;
                default:
                    input[1] += 2;
                    carriage = 0;
            }
            input[0]++;
            if(carriage) {
                input[0]++;
            }
            if(input[0] == '2' && input[1] == '4') {
                input[0] = '0';
                input[1] = '0';
            }
        }
    }
    input[8] = '\0';
    puts(input);
    return 0;
}

