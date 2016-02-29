#include<bits/stdc++.h>
#define LL long long

using namespace std;

LL arr[15];

void fff()
{
    arr[0] = 1;
    for(int i=1; i<=13; i++)
        arr[i] = arr[i-1] * i;
}

LL cool(LL m, LL temp)
{
    //cout<<m<<' '<<temp<<endl;
    LL c;
    for(LL i=1; i<=13; i++)
    {
        if(m*i>=temp) { c = i - 1; break;}
    }
    return c;
}

int main()
{
    fff();
    string str, temp = "";
    LL n, to, test;
    scanf("%lld", &test);
    while(test--)
    {
        scanf("%lld", &n);
        str = "abcdefghijklm";
        temp ="";
        to = n;
        for(LL i=1; i<=13; i++)
        {
            LL id = cool(arr[13-i], to);
            to = to - (arr[13-i]*id);
            temp = temp + str[id];
            str.erase(id,1);
        }
        cout<<temp<<endl;
    }
    return 0;
}
