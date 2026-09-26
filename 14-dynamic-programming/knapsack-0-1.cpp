// 0/1 knapsack: each item is either taken whole or left out.
// dp[i][w] = best profit using the first i items with capacity w.
//   Skip item i: dp[i-1][w]
//   Take item i: dp[i-1][w - weight[i]] + profit[i]   (if it fits)
// O(n * W) time and space. Greedy by profit/weight fails here; the demo
// below is a case where it would.
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int knapsack(const vector<int> &weight, const vector<int> &profit, int capacity, vector<int> &chosen)
{
    int n = weight.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            dp[i][w] = dp[i - 1][w];
            if (weight[i - 1] <= w)
                dp[i][w] = max(dp[i][w], dp[i - 1][w - weight[i - 1]] + profit[i - 1]);
        }
    }

    // Walk back from the last item. If the best value changed when item i was
    // allowed, item i was taken, so remove its weight and continue.
    chosen.clear();
    int w = capacity;
    for (int i = n; i > 0; i--)
    {
        if (dp[i][w] != dp[i - 1][w])
        {
            chosen.push_back(i);
            w -= weight[i - 1];
        }
    }
    reverse(chosen.begin(), chosen.end()); // list items in input order
    return dp[n][capacity];
}

int main()
{
    vector<int> weight = {10, 20, 30};
    vector<int> profit = {60, 100, 120};
    int capacity = 50;

    vector<int> chosen;
    int best = knapsack(weight, profit, capacity, chosen);

    cout << "Maximum profit: " << best << endl;
    cout << "Items taken: ";
    for (int item : chosen)
        cout << item << " ";
    cout << endl;
    cout << "(Greedy by profit/weight would take items 1 and 2 for 160.)" << endl;

    return 0;
}
