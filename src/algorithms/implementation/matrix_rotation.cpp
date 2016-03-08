#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define ULL unsigned long long
#define DEBUG 0

ULL DATA[301][301];
int M,N,MIN_V;

void print_matrix();
void rotate(ULL R);

int main() {
    ULL R;
    cin >> M >> N >> R;
    if (M<N) {
        MIN_V = M;
    } else {
        MIN_V = N;
    }
    #if DEBUG
        cout << endl << "M=" << M << " N=" << N << endl;
    #endif
    for(int i=0; i<M; i++) {
        for(int j=0; j<N; j++) {
            cin >> DATA[i][j];
        }
    }
    #if DEBUG
        print_matrix();
    #endif
    rotate(R);
    print_matrix();
    return 0;
}

void print_matrix()
{
    #if DEBUG
        cout << "print" << endl;
    #endif
    for(int i=0; i<M; i++) {
        for(int j=0; j<N; j++) {
            cout << DATA[i][j] << " ";
        }
        cout << endl;
    }
}

void rotate(ULL R)
{
    int i, j, shell, max_rotate;
    ULL rotate;
    ULL cur, next, temp, last;
    for(shell=0; shell<MIN_V/2; shell++) {
        max_rotate = (M+N) * 2 - shell * 8;
        rotate = R % max_rotate;
        #if DEBUG
            cout << "shell=" << shell << " r=" << rotate << " max_r=" << max_rotate << endl;
        #endif
        while(rotate--) {
            cur = DATA[shell][shell];
            last = DATA[M-shell][shell];
            #if DEBUG
                cout << "left cur=" << cur << endl;
            #endif
            for(int i=shell;i<M-shell-1; i++) {
                next = DATA[i+1][shell];
                DATA[i+1][shell] = cur;
                cur = next;
            }
            #if DEBUG
                print_matrix();
                cout << "bottom cur=" << cur << endl;
            #endif
            for(int j=shell;j<N-shell-1; j++) {
                next = DATA[M-shell-1][j+1];
                DATA[M-shell-1][j+1] = cur;
                cur = next;
            }
            #if DEBUG
                print_matrix();
                cout << "right cur=" << cur << endl;
            #endif
            for(int i=M-shell-1;i>shell; i--) {
                next = DATA[i-1][N-shell-1];
                DATA[i-1][N-shell-1] = cur;
                cur = next;
            }
            #if DEBUG
                print_matrix();
                cout << "top cur=" << cur << endl;
            #endif
            for(int j=N-shell-1;j>shell; j--) {
                next = DATA[shell][j-1];
                DATA[shell][j-1] = cur;
                cur = next;
            }
            #if DEBUG
                print_matrix();
                cout << "shell  cur=" << cur << endl;
            #endif 
        }
    }
}
