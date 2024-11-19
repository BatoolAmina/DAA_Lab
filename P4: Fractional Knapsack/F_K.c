#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int weight;
    int value;
    double valuePerWeight;
} Item;
int compare(const void* a, const void* b) {
    Item* item1 = (Item*)a;
    Item* item2 = (Item*)b;
    if (item1->valuePerWeight < item2->valuePerWeight) return 1;
    if (item1->valuePerWeight > item2->valuePerWeight) return -1;
    return 0;
}
double fractionalKnapsack(Item items[], int n, int capacity) {
    qsort(items, n, sizeof(Item), compare); // Sort items by value per weight

    double totalValue = 0.0; // Total value in the knapsack
    for (int i = 0; i < n; i++) {
        if (capacity >= items[i].weight) {
            capacity -= items[i].weight;
            totalValue += items[i].value;
        } else {
            totalValue += items[i].valuePerWeight * capacity;
            break;
        }
    }
    return totalValue;
}
int main() {
    int n, capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);
    Item items[n];
    printf("Enter the weight and value of each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d - Weight: ", i + 1);
        scanf("%d", &items[i].weight);
        printf("Item %d - Value: ", i + 1);
        scanf("%d", &items[i].value);
        items[i].valuePerWeight = (double)items[i].value / items[i].weight;
    }
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);
    double maxValue = fractionalKnapsack(items, n, capacity);
    printf("Maximum value in the knapsack: %.2f\n", maxValue);
    return 0;
}


Output:
Enter the number of items: 3
Enter the weight and value of each item:
Item 1 - Weight: 10
Item 1 - Value: 60
Item 2 - Weight: 20
Item 2 - Value: 100
Item 3 - Weight: 30
Item 3 - Value: 120
Enter the capacity of the knapsack: 50
    
Maximum value in the knapsack: 240.00
