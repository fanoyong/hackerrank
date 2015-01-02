#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int TESTCASE;
    int i;
    int N;
    int N_dual;
    int count;
    int digit;
    scanf("%d", &TESTCASE);
    for (i=0; i< TESTCASE; i++)
    {
        scanf("%d", &N);
        N_dual = N;
        count = 0;
        do
        {
            if (N_dual < 10)
            {
                if ((N % N_dual) == 0)
                {
                    count++;
                    break;
                }
            }
            digit = N_dual % 10;
            if ((digit != 0) && (N % digit) == 0)
            {
                count++;
            }
            N_dual = (int) N_dual / 10;
        } while(1);
        printf("%d\n", count);
    }
    return 0;
}

