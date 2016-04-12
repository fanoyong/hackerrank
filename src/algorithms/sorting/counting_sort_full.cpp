#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >>N;
    unsigned int DATA[1000001], COUNT[100];
    unsigned int DATA22[1000001];
    char** DATAS = (char **) malloc(sizeof(char*) * N);
    for(int i = 0; i<100; i++) {
        COUNT[i] = N;
    }
    for(int i = 0; i<N; i++) {
        cin >> DATA[i];
        string s;
        cin >> s;
        DATAS[i] =(char *) malloc(sizeof(char) * ((s.length()+1)));
        s.copy(DATAS[i], s.length(),0);
        for (int j = 0; j<DATA[i]; j++) {
            COUNT[j]--;
        }
    }
    for (int i=0; i<100; i++) {
        cout << COUNT[i] << " ";
    }
    cout << endl;
    for (int i=0;i<N; i++) {
        free(DATAS[i]);
    }
    free(DATAS);
    return 0;
}

