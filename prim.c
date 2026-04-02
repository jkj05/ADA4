#include <stdio.h>

#define INF 9999

int main() {
    int n, i, j, min, a, b, u, v;
    int cost[10][10], visited[10] = {0}, total = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if(cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    visited[0] = 1;

    printf("Edges in MST:\n");

    for(int edge = 0; edge < n - 1; edge++) {
        min = INF;

        for(i = 0; i < n; i++) {
            if(visited[i]) {
                for(j = 0; j < n; j++) {
                    if(!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        printf("%d -> %d : %d\n", u, v, min);
        total += min;
        visited[v] = 1;
    }

    printf("Total cost = %d\n", total);

    return 0;
}
