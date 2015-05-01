#include<stdio.h>
#include <string.h>
#define DEBUG 0

int w,h;
int max;

int valid_x_y(int x, int y) {
    return (x>=0) && (x<h) && (y>=0) && (y<w);
}

int traverse(int depth, int max_depth, int i, int j, char board[50][50]) {
#if DEBUG
    printf("traverse depth:%d i:%d j:%d\n", depth, i, j);
#endif
    if (depth > max_depth || depth > max || !valid_x_y(i,j)) {
        return 0;
    }
    if (board[i][j] == 'd') {
        return 1;
    }
    if (traverse(depth+1, max_depth, i-1,j,board)) {
        return 2;
    } else if (traverse(depth+1, max_depth, i, j+1, board)) {
        return 3;
    } else if (traverse(depth+1, max_depth, i+1, j, board)) {
        return 4;
    } else if (traverse(depth+1, max_depth, i, j-1, board)) {
        return 5;
    }
    return 0;
}

void next_move(int posr, int posc, char board[50][50]) {
    int i;
    int ret;
     if (board[posr][posc] == 'd') {
        printf("CLEAN\n");
        return;
    }
    for (i=1; i<=max; i++) {
        ret = traverse(1, i+1, posr, posc, board);
        switch (ret) {
            case 2:
                printf("UP\n");
                return;
            case 3:
                printf("RIGHT\n");            
                return;
            case 4:
                printf("DOWN\n");            
                return;
            case 5:
                printf("LEFT\n");            
                return;
        }
    }
}

int main(void) {
    int pos[2], dim[2], i;
    char board[50][50];
    scanf("%d", &pos[0]);
    scanf("%d", &pos[1]);
    scanf("%d", &dim[0]);
    scanf("%d", &dim[1]);
    for(i=0; i<dim[0]; i++) {
        scanf("%s[^\\n]%*c", board[i]);
    }
    h = dim[0];
    w = dim[1];
    max = dim[0] + dim[1];
    next_move(pos[0], pos[1], board);
    return 0;
}

