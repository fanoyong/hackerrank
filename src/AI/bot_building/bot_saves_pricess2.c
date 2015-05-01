#include <stdio.h>
#include <string.h>
#include <math.h>

void displayPathtoPrincess(int n, int x, int y, char grid[101][101]){
    int i, j;
    int cnt = 0;
    int mx, my;
    int px, py;
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            if (grid[i][j] == 'p') {
                px = i;
                py = j;
                break;
            }
        }
    }
    mx = x;
    my = y;
    if(mx > px) {
        printf("UP\n");
        return;
    } else if(mx < px) {
        printf("DOWN\n");
        return;
    }

    if(my > py) {
        printf("LEFT\n");
        return;
    } else if (my < py) {
        printf("RIGHT\n");
        return;
    }
}

int main(void) {

    int m,i,x,y;
    scanf("%d %d %d", &m, &x, &y);
    char grid[101][101]={};
    char line[101];

    for(i=0; i<m; i++) {
        scanf("%s", line);
        strcpy(grid[i], line);
    }
    displayPathtoPrincess(m,x,y,grid);
    return 0;
}

