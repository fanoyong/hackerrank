#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DEBUG 0

typedef struct struct_coordinate {
    int x;
    int y;
} coordinate;

int w,h;
char board[50][50];
coordinate destination;

int valid_x_y(int x, int y);
int traverse(int depth, int max_depth, int i, int j, coordinate * destination);
void next_move(int posr, int posc);
void find_target(int posr, int posc, coordinate * destination);
void print_path(coordinate * current, coordinate * destination);
void print_board();

int main(void) {
    int pos[2], dim[2], i;
    scanf("%d", &pos[0]);
    scanf("%d", &pos[1]);
    scanf("%d", &dim[0]);
    scanf("%d", &dim[1]);
    h = dim[0];
    w = dim[1];
    for(i=0; i<h; i++) {
        scanf("%s", board[i]);
    }
    next_move(pos[0], pos[1]);
    return 0;
}


int valid_x_y(int x, int y) {
    return (x>=0) && (x<h) && (y>=0) && (y<w);
}

int traverse(int depth, int max_depth, int i, int j, coordinate * destination) {
    if (depth > max_depth) {
        return 0;
    }
    if (board[i][j] == 'd') {
        destination->x = i;
        destination->y = j;
        return 1;
    }
    if (i < h/2 && j < w/2) {
        if (valid_x_y(i-1,j) && traverse(depth+1, max_depth, i-1, j, destination)) {
            return 1;
        } else if (valid_x_y(i,j-1) && traverse(depth+1, max_depth, i, j-1, destination)) {
            return 1;
        } else if (valid_x_y(i,j+1) && traverse(depth+1, max_depth, i, j+1, destination)) {
            return 1;
        } else if (valid_x_y(i+1,j) && traverse(depth+1, max_depth, i+1, j, destination)) {
            return 1;
        }
    } else if (i < h/2 && j >= w/2) {
        if (valid_x_y(i-1,j) && traverse(depth+1, max_depth, i-1, j, destination)) {
            return 1;
        } else if (valid_x_y(i,j+1) && traverse(depth+1, max_depth, i, j+1, destination)) {
            return 1;
        } else if (valid_x_y(i,j-1) && traverse(depth+1, max_depth, i, j-1, destination)) {
            return 1;
        } else if (valid_x_y(i+1,j) && traverse(depth+1, max_depth, i+1, j, destination)) {
            return 1;
        }
    } else if (i >= h/2 && j >= w/2) {
        if (valid_x_y(i+1,j) && traverse(depth+1, max_depth, i+1, j, destination)) {
            return 1;
        } else if (valid_x_y(i,j+1) && traverse(depth+1, max_depth, i, j+1, destination)) {
            return 1;
        } else if (valid_x_y(i-1,j) && traverse(depth+1, max_depth, i-1, j, destination)) {
            return 1;
        } else if (valid_x_y(i,j-1) && traverse(depth+1, max_depth, i, j-1, destination)) {
            return 1;
        }
    } else {
        if (valid_x_y(i+1,j) && traverse(depth+1, max_depth, i+1, j, destination)) {
            return 1;
        } else if (valid_x_y(i,j-1) && traverse(depth+1, max_depth, i, j-1, destination)) {
            return 1;
        } else if (valid_x_y(i,j+1) && traverse(depth+1, max_depth, i, j+1, destination)) {
            return 1;
        } else if (valid_x_y(i-1,j) && traverse(depth+1, max_depth, i-1, j, destination)) {
            return 1;
        }
    }
    
    return 0;
}

void next_move(int posr, int posc) {
    int i;
    int ret;
     if (board[posr][posc] == 'd') {
        printf("CLEAN\n");
        return;
    }
    coordinate *current, *destination;
    current = malloc(sizeof(coordinate));
    current->x = posr;
    current->y = posc;
    destination = malloc(sizeof(coordinate));
    destination->x = -1;
    destination->y = -1;

    find_target(posr, posc, destination);
    print_path(current, destination);

    if (NULL != destination) {
        free(destination);
    }
    if (NULL != current) {
        free(current);
    }
}

void find_target(int x, int y, coordinate * destination){
    int i;
    int ret;
    for(i=1; i<=w+h; i++) {
        if(traverse(1, i+1, x, y, destination)) {
            return;
        }
    }
}

void print_path(coordinate * current, coordinate * destination){
    if(valid_x_y(destination->x, destination->y) && valid_x_y(current->x, current->y)) {
        if(destination->x < current->x) {
            printf("UP\n");
        } else if (destination->x > current->x) {
            printf("DOWN\n");
        } else {
            if(destination->y > current->y) {
                printf("RIGHT\n");
            } else if (destination->y < current->y) {
                printf("LEFT\n");
            } else {
                printf("CLEAN\n");
            }
        }
    }
}

void print_board() {
    int i;
    printf("\n");
    for(i=0; i<h; i++) {
        printf("%s\n", board[i]);
    }
    printf("\n");
}
