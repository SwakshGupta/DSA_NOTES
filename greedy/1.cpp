/*

so we are given with the array of value and weights we have a limit of weight now we have for the given weight 
we have to compute the maximum value  of it 

1.  explanation in note book we can first find value/weight for each item and then sort the array according to it and then 
apply greedy algorithm according to it 


*/
#include <iostream>
#include <algorithm>
using namespace std;

struct Item {
    int value;
    int weight;
};

// items a = {60, 10}; this is how the items looks like in it 

// comparator function to sort items by value/weight ratio

bool comp(Item a, Item b) { // we have created this so that we can sort our item array according to the ratio of value/weight
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2; 
}

double fractionalKnapsack(int W, Item arr[], int n) {
    // sort items based on value/weight ratio
    sort(arr, arr + n, comp);

    int curWeight = 0; 
    double finalValue = 0.0; 

    for (int i = 0; i < n; i++) {
        if (curWeight + arr[i].weight <= W) { // if the current weight+given weight is lesser then we ca take that item 
            curWeight += arr[i].weight;
            finalValue += arr[i].value;
        }
        else {
            // take fraction of the item
            int remain = W - curWeight;
            finalValue += arr[i].value * ((double)remain / arr[i].weight);
            break;
        }
    }

    return finalValue;
}

int main() {
    int W = 50; // capacity of knapsack
    Item arr[] = {{60, 10}, {100, 20}, {120, 30}};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Maximum value in Knapsack = " << fractionalKnapsack(W, arr, n);
    return 0;
}
