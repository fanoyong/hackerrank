#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >>N;
    unsigned int DATA[1000001], COUNT[100];
    unsigned int DATA2[1000001];
    char** DATAS = (char **) malloc(sizeof(char*) * N);
    for(int i = 0; i<100; i++) {
        COUNT[i] = 0;
    }
    // Step 1 - Histogram
    for(int i = 0; i<N/2; i++) {
        cin >> DATA[i];
        COUNT[DATA[i]]++;
        char s[11];
        cin >> s;
        s[0] = '-';
        s[1] = '\0';
        DATAS[i] =(char *) malloc(sizeof(char) * 2);
        strcpy(DATAS[i], s);
    }
    for(int i = N/2; i<N; i++) {
        cin >> DATA[i];
        COUNT[DATA[i]]++;
        char s[11];
        cin >> s;
        DATAS[i] =(char *) malloc(sizeof(char) * (strlen(s)+1));
        strcpy(DATAS[i], s);
    }

    // Step 2 - Calculate the starting index for each key
    int total = 0;
    for (int i=0; i<100; i++) {
        int old_count = COUNT[i];
        COUNT[i] = total;
        total += old_count;
    }

    // Step 3 - Copy to output array
    for (int i=0; i<N; i++) {
        DATA2[COUNT[DATA[i]]] = i;
        COUNT[DATA[i]]++;
    }


    for (int i=0; i<N; i++) {
        cout << DATAS[DATA2[i]] << " ";
    }
    cout << endl;
    for (int i=0;i<N; i++) {
        free(DATAS[i]);
    }
    free(DATAS);
    return 0;
}

