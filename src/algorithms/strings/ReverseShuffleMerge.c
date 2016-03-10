#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int smallest(int *a) {
    int i;
    for(i = 0 ; i < 26 ; i++)
        if( a[i] != 0 )
            return i;

    return 25;
}

int main() {
    char *s = (char *)malloc(10001 * sizeof(char));     //input
    char *a = (char *)malloc(5001 * sizeof(char));      //op string
    scanf("%s", s);


    int *htskips = (int *)malloc(26 * sizeof(int));         //creation of hash table
    memset(htskips, 0, 26 * sizeof(int));
    int i;
    for(i = 0 ; s[i] != 0 ; i++)
        htskips[s[i] - 97]++;
    for(i = 0 ; i < 26 ; i++)
        htskips[i] /= 2;


    int *httaken = (int *)malloc(26 * sizeof(int));
    memcpy(httaken, htskips, 26*sizeof(int));


    i = strlen(s) - 1;
    int j = 0;
    int small = smallest(httaken);

char best_seen = ('z'+1) ;
int best_index ;
for( ; i >= 0 ; i--) {
    if(httaken[s[i]-97]==0) continue ;
    if( (s[i]-97) > small ) {
        if( htskips[s[i]-97] == 0 ) {
            if ( s[i] < best_seen ) {
                httaken[s[i]-97]--;
                a[j] = s[i];
                j++;
                best_seen = ('z'+1) ;
            }
            else {
                while (i<best_index) {
                    i++ ;
                    htskips[s[i]-97]++ ;
                }
                httaken[s[i]-97]--;
                a[j] = s[i] ;
                j++ ;
                best_seen = ('z'+1) ;
            }
        }
        else {
            htskips[s[i]-97]--;
            if( s[i] < best_seen) {
                best_seen = s[i] ;
                best_index = i ;
            }
        }
    }
    else {
        if( httaken[s[i]-97] != 0 ) {
            httaken[s[i]-97]--;
            small = smallest(httaken);
            a[j] = s[i];
            j++;
            best_seen = ('z'+1) ;
        }
    }
}

    a[j] = 0;


    printf("%s\n", a);          //output

    return 0;
}
