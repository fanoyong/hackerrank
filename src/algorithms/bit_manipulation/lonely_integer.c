#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
int lonelyinteger(int a_size, int* a) {
    int i,j;
    for(i=0;i<a_size;i++) {
        int flag = 1;
        for(j=0;j<a_size;j++) {
            if(a[i] == a[j] && i!=j) {
                flag = 0;
                break;
            }    
        }
        if(flag) {
            return a[i];
        }
    }
    return a[0];

}
int main() {
    int res;
    
    int _a_size, _a_i;
    scanf("%d", &_a_size);
    int _a[_a_size];
    for(_a_i = 0; _a_i < _a_size; _a_i++) { 
        int _a_item;
        scanf("%d", &_a_item);
        
        _a[_a_i] = _a_item;
    }
    
    res = lonelyinteger(_a_size, _a);
    printf("%d", res);
    
    return 0;
}

