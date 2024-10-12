#include <iostream>
#include <vector>
using namespace std;

// Define a struct to represent an item
struct Item {
  string name;
  int weight;
  int profit;
};

int knapsack(vector<Item> &items, int max_weight, vector<vector<int>> &dp,
             vector<string> &solution) {
  // Add a dummy item to the beginning of the list to simplify the dynamic
  // programming algorithm
  items.insert(items.begin(), {"#0", 0, 0});

  int n = items.size();

  // Initialize the dynamic programming table with zeros
  dp.resize(n, vector<int>(max_weight + 1, 0));

  // Compute the maximum profit that can be obtained for each item and weight
  // limit combination
  for (int i = 1; i < n; i++) {
    for (int j = 1; j <= max_weight; j++) {
      if (items[i].weight <= j) {
        dp[i][j] =
            max(dp[i - 1][j], items[i].profit + dp[i - 1][j - items[i].weight]);
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }

  // Backtrack through the dynamic programming table to determine the solution
  int i = n - 1, j = max_weight, remain = max_weight;
  while (remain >= 0 && j > 0) {
    if (dp[i][j] > dp[i - 1][j]) {
      solution.push_back(items[i].name);
      remain -= items[i].weight;
      j = remain;
      i--;
    } else {
      i--;
    }
  }

  // Return the maximum profit that can be obtained
  return dp[n - 1][max_weight];
}

int main() {

  /*
The time complexity of the dynamic programming algorithm used in this code is
O(nW), where n is the number of items and W is the maximum weight that can be
carried The space complexity of the algorithm is also O(nW)
*/

  vector<Item> items = {
      {"#1", 1, 4}, {"#2", 3, 9}, {"#3", 5, 12}, {"#4", 4, 11}};
  int max_weight = 8;

  // Define variables for the dynamic programming table and the solution
  vector<vector<int>> dp;
  vector<string> solution;

  // Compute the maximum profit that can be obtained and determine the solution
  int max_profit = knapsack(items, max_weight, dp, solution);

  // Print the maximum profit and the solution
  cout << "Max Profit: " << max_profit << endl;
  cout << "Solution: ";
  for (int i = 0; i < solution.size(); i++) {
    cout << solution[i] << " ";
  }
  cout << endl;

  return 0;
}
