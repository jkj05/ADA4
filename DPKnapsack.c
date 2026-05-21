#include <stdio.h>

int max(int a, int b){
    return (a > b) ? a : b;
}

int knapsack(int n, int W, int weight[], int value[]){
    int dp[n+1][W+1];

    for(int i = 0; i <= n; i++){
        for(int w = 0; w <= W; w++){
            if(i == 0 || w == 0){
                dp[i][w] = 0;
            }
            else if(weight[i-1] <= w){
                dp[i][w] = max(value[i-1] + dp[i-1][w - weight[i-1]],
                               dp[i-1][w]);
            }
            else{
                dp[i][w] = dp[i-1][w];
            }
        }
    }

    printf("\nDP Table:\n\n");

    printf("     ");
    for(int w = 0; w <= W; w++){
        printf("%4d", w);
    }
    printf("\n");

    for(int i = 0; i <= n; i++){
        printf("i=%d ", i);
        for(int w = 0; w <= W; w++){
            printf("%4d", dp[i][w]);
        }
        printf("\n");
    }

    return dp[n][W];
}

int main(){
    int n, W;
    printf("Enter number of items: ");
    scanf("%d", &n);

    int weight[n], value[n];

    printf("Enter weights:\n");
    for(int i = 0; i < n; i++){
        scanf("%d", &weight[i]);
    }

    printf("Enter values:\n");
    for(int i = 0; i < n; i++){
        scanf("%d", &value[i]);
    }

    printf("Enter Knapsack Capacity: ");
    scanf("%d", &W);

    int result = knapsack(n, W, weight, value);

    printf("Maximum Value = %d\n", result);


    return 0;
}
