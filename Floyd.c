#include <stdio.h>


#define MAX 10
#define INF 99999

void readGraph(int graph[MAX][MAX], int n) {
    printf("Enter the adjacency matrix (use %d for no edge):\n", INF);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
}


void printMatrix(int dist[MAX][MAX], int n) {
    printf("Shortest distance Matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(dist[i][j] == INF)
                printf("INF\t");
            else
                printf("%d\t", dist[i][j]);
        }
        printf("\n");
    }
}


void floydAlgo(int graph[MAX][MAX], int n) {
    int dist[MAX][MAX];


    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            dist[i][j] = graph[i][j];
        }
    }


    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(dist[i][k] != INF && dist[k][j] != INF &&
                   dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }


    printMatrix(dist, n);
}

int main() {
    int n;
    int graph[MAX][MAX];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    readGraph(graph, n);
    floydAlgo(graph, n);

    return 0;
}
