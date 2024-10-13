#include <iostream>
#include <vector>

using namespace std;

// Function to solve the 0-1 Knapsack problem using dynamic programming
int knapsack(int W, vector<int>& weights, vector<int>& values, int n) {
    // Create a 2D DP table to store the maximum values for subproblems
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Build the table dp[][] in a bottom-up manner
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            // If the item i can be included (weight <= w)
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            }
            // If the item i cannot be included
            else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // The last cell of dp table contains the maximum value for the full knapsack
    return dp[n][W];
}

int main() {
    int W = 50; // Capacity of the knapsack
    vector<int> values = {60, 100, 120}; // Values of the items
    vector<int> weights = {10, 20, 30}; // Weights of the items
    int n = values.size(); // Number of items

    cout << "Maximum value we can obtain = " << knapsack(W, weights, values, n) << endl;

    return 0;
}
