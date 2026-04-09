#include<stdio.h>

typedef struct{
    int weight;
    int profit;
    float ratio;
}Item;

void swap(Item *a,Item *b){
    Item temp=*a;
    *a=*b;
    *b=temp;
}

void sortItems(Item arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j].ratio<arr[j+1].ratio){
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}

float fractionalKnapsack(Item arr[],int n,int capacity){
    float totalProfit=0.0;

    for(int i=0;i<n; i++){
        if(capacity>=arr[i].weight){
            totalProfit+=arr[i].profit;
            capacity-=arr[i].weight;
        }else{
            totalProfit+=arr[i].ratio * capacity;
            break;
        }
    }
    return totalProfit;
}

int main(){
    int n, capacity;
    printf("Enter number of items: ");
    scanf("%d",&n);

    Item arr[n];

    for(int i=0;i<n;i++){
        printf("Enter weight and profit of item %d:",i+1);
        scanf("%d %d",&arr[i].weight,&arr[i].profit);
        arr[i].ratio=(float)arr[i].profit / arr[i].weight;
    }

    printf("Enter Knapsack capacity: ");
    scanf("%d",&capacity);

    sortItems(arr,n);

    float maxProfit=fractionalKnapsack(arr,n,capacity);
    printf("Maximum Profit= %.2f\n",maxProfit);

    return 0;

}
