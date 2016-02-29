//#include<time.h>
#include<stdio.h>
//#include<conio.h>
#include<string.h>

void swap(char* s, int a, int b)
{
    char temp = s[a];
    s[a] = s[b];
    s[b] = temp;
}

int permute(char* str, int len)
{
    int key = len-1;
    int newkey = len-1;
    while ((key > 0) && (str[key] <= str[key-1])) {
        key--;
    }
    key--;
    if (key < 0)
        return 0;
    newkey = len-1;
    while ((newkey > key) && (str[newkey] <= str[key])) {
        newkey--;
    }
    swap(str,key,newkey);
    len--;
    key++;
    while(len>key) {
        swap(str,len,key);
        key++;
        len--;
    }
    return 1;
}

int main(void)
{
    int t,n;
    long count;
    scanf("%d",&t);
    while (t--) {
        count = 0;
        char st[14] = {"abcdefghijklm\0"};
        scanf("%d",&n);
        do {
            count++;
            if (count == n) break;
        } while(permute(st,strlen(st)));
        printf("%s\n", st);
    }
  return 0;
}
