
#include <stdio.h>

#define MAX 20

int g[MAX][MAX], indeg[MAX], q[MAX];
int n;

void findIndegree() {
    for(int j = 0; j < n; j++) {
        indeg[j] = 0;

        for(int i = 0; i < n; i++) {
            if(g[i][j])
                indeg[j]++;
        }
    }
}

void topoSort() {

    int front = 0, rear = 0;
    int cnt = 0;

    // insert all source vertices
    for(int i = 0; i < n; i++) {
        if(indeg[i] == 0)
            q[rear++] = i;
    }

    printf("Topological Order:\n");

    while(front < rear) {

        int u = q[front++];


        printf("%d ", u);

        cnt++;

        // remove outgoing edges
        for(int v = 0; v < n; v++) {

            if(g[u][v]) {

                indeg[v]--;

                if(indeg[v] == 0)
                    q[rear++] = v;
            }
        }
    }

    if(cnt != n)
        printf("\nGraph has a cycle");
}

int main() {

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &g[i][j]);
        }
    }

    findIndegree();

    topoSort();

    return 0;
}
