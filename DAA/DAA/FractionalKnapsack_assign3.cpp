#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an item with value and weight
struct Item {
    int value, weight;

    // Constructor
    Item(int v, int w) : value(v), weight(w) {}
};

// Function to compare items according to their value-to-weight ratio
bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

// Function to solve the fractional knapsack problem
double fractionalKnapsack(int W, vector<Item> items) {
    // Sort items by value-to-weight ratio in descending order
    sort(items.begin(), items.end(), compare);

    int currentWeight = 0; // Current weight in knapsack
    double finalValue = 0.0; // Total value in knapsack

    // Loop through all items
    for (auto &item : items) {
        // If adding the whole item doesn't exceed the capacity, take it
        if (currentWeight + item.weight <= W) {
            currentWeight += item.weight;
            finalValue += item.value;
        }
        // If adding the whole item exceeds capacity, take the fractional part
        else {
            int remainingCapacity = W - currentWeight;
            finalValue += item.value * ((double)remainingCapacity / item.weight);
            break; // The knapsack is full
        }
    }

    return finalValue;
}

int main() {
    int W = 50; // Capacity of the knapsack
    vector<Item> items = { {60, 10}, {100, 20}, {120, 30} };

    cout << "Maximum value we can obtain = " << fractionalKnapsack(W, items) << endl;

    return 0;
}
