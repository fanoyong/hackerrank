#include<stdio.h>
#include <string.h>
#define DEBUG 0

typedef stuct struct_coordinate{
    int x;
    int y;
} coordinate;

coordinate destination;

int valid_x_y(int x, int y) {
    return (x>=0) && (x<5) && (y>=0) && (y<5);
}

int traverse(int depth, int max_depth, int i, int j, char board[50][50]) {
#if DEBUG
    printf("traverse depth:%d i:%d j:%d\n", depth, i, j);
#endif
    if (depth > max_depth || depth > 8 || !valid_x_y(i,j)) {
        return 0;
    }
    if (board[i][j] == 'd') {
        destination.x = i;
        destination.y = j;
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
    destination.x = 0;
    destination.y = 0;
     if (board[posr][posc] == 'd') {
        printf("CLEAN\n");
        return;
    }
    for (i=1; i<=8; i++) {
    ret = traverse(1, i+1, posr, posc, board);

    printf("destination %d/%d\n", destination.x, destination.y);
#endif
        if ( posr > destination.x) {
        }
    }
}

int main(void) {
    int pos[2], i;
    char board[5][5], line[6];
    scanf("%d", &pos[0]);
    scanf("%d", &pos[1]);
    for(i=0; i<5; i++) {
        scanf("%s[^\\n]%*c", line);
        strncpy(board[i], line, 5);
    }
    next_move(pos[0], pos[1], board);
    return 0;
}

