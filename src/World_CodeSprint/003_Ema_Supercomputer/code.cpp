#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*

    1. Let MAX = min(N,M);
    2. Start searching for PLUS with size i = MAX to 1
        - If found mark it as used. Start searching for the other starting PLUS with size i = MAX to i;
        - If 2nd PLUS is found, calucate product and store the value. Update max product for all combinations
        - Revert mark it as used operation.

*/

void init();
void print_data();
void get_answer();
int is_plus(int i, int j, int size);
void mark_plus(int i, int j, int size, int mark);

int N, M, MIN_LEN, MAX_LEN, MAX_PROD=0;
int DATA[15][15];
int VISITED[15][15];

int main()
{
    init();
    get_answer();
    // print_data();
    cout << MAX_PROD << endl;
    return 0;
}

void init()
{
    int i, j, k;
    char d;
    cin >> N >> M;
    if (N > M) {
        MAX_LEN = N;
        MIN_LEN = M;
    } else {
        MAX_LEN = M;
        MIN_LEN = N;
    }
    for(i=0; i<MIN_LEN; i++) {
        for(j=0; j<MIN_LEN; j++) {
            VISITED[i][j] = 0;
        }
    }
    for(i=0; i<N; i++) {
        for(j=0; j<M; j++) {
            cin >> d;
            (d == 'G') ? k = 1 : k = 0;
            DATA[i][j] = k;
        }
    }
}

void print_data()
{
    int i, j;
    for (i=0; i<N; i++) {
        for (j=0; j<M; j++) {
            cout << DATA[i][j];
        }
        cout << endl;
    }
}

void get_answer()
{
    int size_1, size_2, i, j, k, l, temp;
    for(size_1=MIN_LEN/2; size_1>=0; size_1--) {
        for(i=size_1; i<N-size_1; i++) {
            for(j=size_1; j<M-size_1; j++) {
                // cout << "SIZE:" << size_1 << " i:" << i << " j:" << j << endl;
                if(is_plus(i,j,size_1)) {
                    mark_plus(i,j,size_1,0);
                    for(size_2=MIN_LEN/2; size_2>=0; size_2--) {
                        for(k=size_2; k<N-size_2; k++) {
                            for(l=size_2; l<M-size_2; l++) {
                                if(is_plus(k,l,size_2) && (!VISITED[size_1][size_2] && !VISITED[size_2][size_1])) {
                                    temp = (((size_1)*4) + 1) * (((size_2)*4) + 1);
                                    if (temp > MAX_PROD) {
                                        // cout << size_1 << "/" << size_2 << endl;
                                        MAX_PROD = temp;
                                    }
                                    VISITED[size_1][size_2] = 1;
                                    VISITED[size_2][size_1] = 1;
                                }
                            }
                        }
                    }
                    mark_plus(i,j,size_1,1);
                }
            }
        }    
    }
}

int is_plus(int i, int j, int size)
{
    int phase;
    if (!DATA[i][j]) {
        return 0;
    }
    for(phase = 1; phase <= size; phase++) {
        if(!DATA[i][j-phase] || !DATA[i-phase][j] || !DATA[i][j+phase] || !DATA[i+phase][j]) {
            return 0;
        }
    }
    return 1;
}

void mark_plus(int i, int j, int size, int mark)
{
    int phase;
    DATA[i][j] = mark;
    for(phase = 1; phase <= size; phase++) {
        DATA[i][j-phase] = mark;
        DATA[i-phase][j] = mark;
        DATA[i][j+phase] = mark;
        DATA[i+phase][j] = mark;
    }
}
