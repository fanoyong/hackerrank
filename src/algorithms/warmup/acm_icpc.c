#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

char T[500][500];

int main() {
    int i,j,k,temp;
    int N,M;
    char t[500];
    int MAX_T = -10;
    int count = 0;
    scanf("%d %d", &N, &M);
    for (i=0;i<N;i++)
    {
        scanf("%s",t);
        strcpy (T[i], t);
    }
    for (i=0; i<N; i++)
    {
        for (j=i; j<N; j++)
        {
            temp = 0;
            for (k=0; k<M; k++)
            {
                temp += (T[i][k]=='1' || T[j][k]=='1') ? 1:0;
            }
            if (temp > MAX_T) {
                count = 1;
                MAX_T = temp;
            } else if (temp == MAX_T) {
                count ++;
            }
        }
    }
    printf ("%d\n%d\n", MAX_T, count);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
