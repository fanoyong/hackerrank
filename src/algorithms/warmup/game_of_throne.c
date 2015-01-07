#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
 
findPalind(char *arr)
{
    int count[50];
    int flag = 0;
    // Find the required answer here. Print Yes or No at the end of this function depending on your inspection of the string
    int i, j;
    int len = strlen(arr);
    for (i=0; i<50; i++)
    {
        count[i] = 0;
    }
    for (i=0; i<len; i++)
    {
        count[arr[i] - 'a']++;
    }
    for(i=0;i<50;i++)
    {
        if (count[i] % 2 == 1)
        {
            flag++;
        }
    }

    if (flag==0 || flag == 1)
        printf("YES\n");
    else
        printf("NO\n");
    
    return;
}

int main() {

    char arr[100001];
    scanf("%s",arr);
    findPalind(arr);
    return 0;
}

