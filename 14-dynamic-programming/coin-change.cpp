// Coin change, two classic versions.
// - Fewest coins to make an amount:
//     minCoins[a] = 1 + min(minCoins[a - coin]) over every coin <= a
// - Number of ways to make an amount (order does not matter): loop over
//   coins first so each combination is counted once.
//     ways[a] += ways[a - coin]
// Both are O(amount * number of coins).
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int fewestCoins(const vector<int> &coins, int amount)
{
    vector<int> minCoins(amount + 1, INT_MAX);
    minCoins[0] = 0;
    for (int a = 1; a <= amount; a++)
        for (int coin : coins)
            if (coin <= a && minCoins[a - coin] != INT_MAX)
                minCoins[a] = min(minCoins[a], minCoins[a - coin] + 1);
    return minCoins[amount] == INT_MAX ? -1 : minCoins[amount];
}

long long countWays(const vector<int> &coins, int amount)
{
    vector<long long> ways(amount + 1, 0);
    ways[0] = 1;
    for (int coin : coins)
        for (int a = coin; a <= amount; a++)
            ways[a] += ways[a - coin];
    return ways[amount];
}

int main()
{
    vector<int> coins = {1, 5, 10, 25};
    int amount = 63;
    cout << "Coins {1, 5, 10, 25}, amount " << amount << endl;
    cout << "Fewest coins: " << fewestCoins(coins, amount) << endl;
    cout << "Number of ways: " << countWays(coins, amount) << endl;

    // Greedy (largest coin first) gives 4 + 1 + 1 = 3 coins for 6 here,
    // but 3 + 3 = 2 coins is better.
    vector<int> tricky = {1, 3, 4};
    cout << "\nCoins {1, 3, 4}, amount 6, fewest coins: " << fewestCoins(tricky, 6) << endl;

    vector<int> noOnes = {2};
    cout << "Coins {2}, amount 3, fewest coins: " << fewestCoins(noOnes, 3) << " (impossible)" << endl;

    return 0;
}
