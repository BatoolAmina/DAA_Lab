#include <stdio.h>
int max(int a, int b) {
    return (a > b) ? a : b;
}
void knapsack(int capacity, int weights[], int values[], int n) {
    int dp[n + 1][capacity + 1];
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;  // Base case: no items or no capacity
            } else if (weights[i - 1] <= w) {
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    printf("Maximum value: %d\n", dp[n][capacity]);
    printf("Items included (index starting from 1): ");
    int w = capacity;
    for (int i = n; i > 0 && w > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            printf("%d ", i);
            w -= weights[i - 1];
        }
    }
    printf("\n");
}
int main() {
    int n, capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    int values[n], weights[n];
    printf("Enter the values of the items: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &values[i]);
    }
    printf("Enter the weights of the items: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);
    knapsack(capacity, weights, values, n);
    return 0;
}

Output:
Enter the number of items: 4
Enter the values of the items: 60 100 120 30
Enter the weights of the items: 10 20 30 5
Enter the capacity of the knapsack: 50

Maximum value: 220
Items included (index starting from 1): 3 2
