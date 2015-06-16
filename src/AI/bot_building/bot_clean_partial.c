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
    FILE *fp;
    int direction, direction_prev;

    //printf("current %d/%d destination %d/%d\n", current->x, current->y, destination->x, destination->y);

    fp = fopen("previous_move", "r");
    direction_prev = -1;
    if (NULL != fp) {
        fscanf(fp, "%d", &direction_prev);
        fclose(fp);
    }

    if(valid_x_y(destination->x, destination->y) && valid_x_y(current->x, current->y)) {
        if(destination->x < current->x) {
            fp = fopen("previous_move", "w");
            fprintf(fp, "0");
            fclose(fp);
            printf("UP\n");
        } else if (destination->x > current->x) {
            fp = fopen("previous_move", "w");
            fprintf(fp, "1");
            fclose(fp);
            printf("DOWN\n");
        } else {
            if(destination->y > current->y) {
            fp = fopen("previous_move", "w");
                fprintf(fp, "2");
                fclose(fp);
                printf("RIGHT\n");
            } else if (destination->y < current->y) {
                fp = fopen("previous_move", "w");
                fprintf(fp, "3");
                fclose(fp);
                printf("LEFT\n");
            } else {
                printf("CLEAN\n");
            }
        }
    } else {
        /* In here apply some smart algorithm. 
         * It will just use previous step's path with 90% of probability
         * Or it will pick any ramdom direction with 10% of probability
         */
        if (direction_prev < 0) {
            direction = rand() % 4;
            switch (direction) {
                case 0:
                    if (current->x > 1) {
                        fp = fopen("previous_move", "w");
                        fprintf(fp, "0");
                        fclose(fp);
                        printf("UP\n");
                    } else {
                        fp = fopen("previous_move", "w");
                        fprintf(fp, "1");
                        fclose(fp);
                        printf("DOWN\n");
                    }
                    break;
                case 1:
                    if (current->x < h-1) {
                        fp = fopen("previous_move", "w");
                        fprintf(fp, "1");
                        fclose(fp);
                        printf("DOWN\n");
                    } else {
                        fp = fopen("previous_move", "w");
                        fprintf(fp, "0");
                        fclose(fp);
                        printf("UP\n");
                    }
                    break;
                case 2:
                    if (current->y < w-1) {
                        fp = fopen("previous_move", "w");
                        fprintf(fp, "2");
                        fclose(fp);
                        printf("RIGHT\n");
                    } else {
                        fp = fopen("previous_move", "w");
                        fprintf(fp, "3");
                        fclose(fp);
                        printf("LEFT\n");
                    }
                    break;
                case 3:
                    if (current->y > 0) {
                        fp = fopen("previous_move", "w");
                        fprintf(fp, "3");
                        fclose(fp);
                        printf("LEFT\n");
                    } else {
                        fp = fopen("previous_move", "w");
                        fprintf(fp, "2");
                        fclose(fp);
                        printf("RIGHT\n");
                    }
                    break;
            }
        } else {
            direction = rand() % 10;
            //printf("direction = %d\n", direction);
            switch (direction) {
                case 0:
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                    direction_prev = rand() % 4;
                    switch(direction_prev) {
                        case 0:
                            if (current->x > 1) {
                                fp = fopen("previous_move", "w");
                                fprintf(fp, "0");
                                fclose(fp);
                                printf("UP\n");
                            } else {
                                fp = fopen("previous_move", "w");
                                fprintf(fp, "1");
                                fclose(fp);
                                printf("DOWN\n");
                            }
                            break;
                        case 1:
                            if (current->x < h-1) {
                                fp = fopen("previous_move", "w");
                                fprintf(fp, "1");
                                fclose(fp);
                                printf("DOWN\n");
                            } else {
                                fp = fopen("previous_move", "w");
                                fprintf(fp, "0");
                                fclose(fp);
                                printf("UP\n");
                            }
                            break;
                        case 2:
                            if (current->y < w-1) {
                                fp = fopen("previous_move", "w");
                                fprintf(fp, "2");
                                fclose(fp);
                                printf("RIGHT\n");
                            } else {
                                fp = fopen("previous_move", "w");
                                fprintf(fp, "3");
                                fclose(fp);
                                printf("LEFT\n");
                            }
                            break;
                        case 3:
                        default:
                            if (current->y > 0) {
                                fp = fopen("previous_move", "w");
                                fprintf(fp, "3");
                                fclose(fp);
                                printf("LEFT\n");
                            } else {
                                fp = fopen("previous_move", "w");
                                fprintf(fp, "2");
                                fclose(fp);
                                printf("RIGHT\n");
                            }
                            break;
                    }
                    break;
                default:
                    //printf("previous direction %d\n", direction_prev);
                    switch (direction_prev) {
                        case 0:
                            if (current->x > 1) {
                                fp = fopen("previous_move", "w");
                                fprintf(fp, "0");
                                fclose(fp);
                                printf("UP\n");
                            } else {
                                fp = fopen("previous_move", "w");
                                fprintf(fp, "1");
                                fclose(fp);
                                printf("DOWN\n");
                            }
                            break;
                        case 1:
                            if (current->x < h-1) {
                                fp = fopen("previous_move", "w");
                                fprintf(fp, "1");
                                fclose(fp);
                                printf("DOWN\n");
                            } else {
                                fp = fopen("previous_move", "w");
                                fprintf(fp, "0");
                                fclose(fp);
                                printf("UP\n");
                            }
                            break;
                        case 2:
                            if (current->y < w-1) {
                                fp = fopen("previous_move", "w");
                                fprintf(fp, "2");
                                fclose(fp);
                                printf("RIGHT\n");
                            } else {
                                fp = fopen("previous_move", "w");
                                fprintf(fp, "3");
                                fclose(fp);
                                printf("LEFT\n");
                            }
                            break;
                        case 3:
                            if (current->y > 0) {
                                fp = fopen("previous_move", "w");
                                fprintf(fp, "3");
                                fclose(fp);
                                printf("LEFT\n");
                            } else {
                                fp = fopen("previous_move", "w");
                                fprintf(fp, "2");
                                fclose(fp);
                                printf("RIGHT\n");
                            }
                            break;
                    }
                    break;    
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
