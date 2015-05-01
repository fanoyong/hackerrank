#include <stdio.h>
#include <string.h>
#include <math.h>

void displayPathtoPrincess(int n, char grid[101][101]){
    int i, j;
    int cnt = 0;
    int mx, my;
    int px, py;
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            if(grid[i][j] == 'm') {
                mx = i;
                my = j;
            } else if (grid[i][j] == 'p') {
                px = i;
                py = j;
            }
        }
    }
    if(mx > px) {
        for(i=0; i<(mx-px); i++) {
            printf("UP\n");
        }
    } else if(mx < px) {
        for(i=0; i<(px-mx); i++) {
            printf("DOWN\n");
        }
    }

    if(my > py) {
        for(i=0; i<(my-py); i++) {
            printf("LEFT\n");
        }
    } else if (my < py) {
        for(i=0; i<(py-my); i++) {
            printf("RIGHT\n");
        }
    }
}

int main(void) {

    int m,i;
    scanf("%d", &m);
    char grid[101][101]={};
    char line[101];

    for(i=0; i<m; i++) {
        scanf("%s", line);
        strcpy(grid[i], line);
    }
    displayPathtoPrincess(m,grid);
    return 0;
}

