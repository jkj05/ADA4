#include <stdio.h>

#define MAX 10
#define INF 9999

int parent[MAX];


void findMinEdge(int cost[MAX][MAX], int n, int *a, int *b, int *min) {
    *min = INF;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (cost[i][j] < *min) {
                *min = cost[i][j];
                *a = i;
                *b = j;
            }
        }
    }
}


void kruskal(int cost[MAX][MAX], int n) {
    int edges = 0, total = 0;
    int a, b, u, v, min;

    while (edges < n - 1) {
        findMinEdge(cost, n, &a, &b, &min);


        u = a;
        while (parent[u] != 0)
            u = parent[u];


        v = b;
        while (parent[v] != 0)
            v = parent[v];


        if (u != v) {
            printf("%d -> %d : %d\n", a, b, min);
            total += min;
            parent[v] = u;
            edges++;
        }


        cost[a][b] = cost[b][a] = INF;
    }

    printf("Total cost = %d\n", total);
}

int main() {
    int n, cost[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    kruskal(cost, n);

    return 0;
}


