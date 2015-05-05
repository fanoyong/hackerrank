#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DEBUG 0

typedef struct struct_coordinate {
    int x;
    int y;
} coordinate;

int w,h;
char board[5][5];

int distance(coordinate * origin, coordinate * destination);
int valid_x_y(int x, int y);
int traverse(int depth, int max_depth, int i, int j, coordinate * destination);
void next_move(int posr, int posc);
void find_target(coordinate * current, coordinate * destination);
void print_path(coordinate * current, coordinate * destination);
void print_board();

int main(void) {
    int i;
    int pos[2];
    w = 5;
    h = 5;
    srand(time(NULL));
    scanf("%d", &pos[0]);
    scanf("%d", &pos[1]);
    for(i=0; i<h; i++) {
        scanf("%s", board[i]);
    }
    next_move(pos[0], pos[1]);
    return 0;
}

int distance(coordinate * origin, coordinate * destination) {
    return abs(origin->x - destination->x) + abs(origin->y - destination->y);
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
    return 0;
}

void next_move(int posr, int posc) {
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

    find_target(current, destination);
    print_path(current, destination);

    if (NULL != destination) {
        free(destination);
    }
    if (NULL != current) {
        free(current);
    }
}

void find_target(coordinate * current, coordinate * destination){
    int i,j;
    int dist = 10000000;
    int new_dist;
    coordinate *temp;
    temp = malloc(sizeof(coordinate));
    for(i=0; i<h; i++) {
        for(j=0; j<w; j++) {
            if(board[i][j] == 'd') {
                temp->x = i;
                temp->y = j;
                new_dist = distance(current,temp);
                if(new_dist < dist) {
                    dist = new_dist;
                    destination->x = i;
                    destination->y = j;
                }
            }
        }
    }
    free(temp);
}

void print_path(coordinate * current, coordinate * destination){
    int direction, zone;
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
    } else {
        direction = rand() % 2;
        if (current->x <= (h/2)) {
            if(current->y <= (w/2)) {
                zone = 0;
            } else {
                zone = 1;
            }
        } else {
            if(current->y <= (w/2)) {
                zone = 3;
            } else {
                zone = 2;
            }
        }
        switch(zone) {
            case 0:
                if(direction) {
                    printf("DOWN\n");
                } else {
                    printf("RIGHT\n");
                }
                break;
            case 1:
                if(direction) {
                    printf("DOWN\n");
                } else {
                    printf("LEFT\n");
                }
                break;
            case 2:
                if(direction) {
                    printf("UP\n");
                } else {
                    printf("LEFT\n");
                }
                break;
            case 3:
                if(direction) {
                    printf("UP\n");
                } else {
                    printf("RIGHT\n");
                }
                break;
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
