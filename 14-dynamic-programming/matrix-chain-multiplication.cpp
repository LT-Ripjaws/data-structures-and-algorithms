// Matrix chain multiplication (MCM): find the parenthesisation of
// A1 x A2 x ... x An that needs the fewest scalar multiplications.
// Matrix Ai has size dims[i-1] x dims[i].
// cost[i][j] = min over k of cost[i][k] + cost[k+1][j] + dims[i-1]*dims[k]*dims[j]
// Fill by increasing chain length. O(n^3) time, O(n^2) space.
#include <climits>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string parenthesise(const vector<vector<int>> &split, int i, int j)
{
    if (i == j)
        return "A" + to_string(i);
    int k = split[i][j];
    return "(" + parenthesise(split, i, k) + " x " + parenthesise(split, k + 1, j) + ")";
}

int matrixChainOrder(const vector<int> &dims, string &order)
{
    int n = dims.size() - 1; // number of matrices
    vector<vector<int>> cost(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> split(n + 1, vector<int>(n + 1, 0));

    for (int length = 2; length <= n; length++)
    {
        for (int i = 1; i + length - 1 <= n; i++)
        {
            int j = i + length - 1;
            cost[i][j] = INT_MAX;
            for (int k = i; k < j; k++)
            {
                int c = cost[i][k] + cost[k + 1][j] + dims[i - 1] * dims[k] * dims[j];
                if (c < cost[i][j])
                {
                    cost[i][j] = c;
                    split[i][j] = k;
                }
            }
        }
    }

    order = parenthesise(split, 1, n);
    return cost[1][n];
}

int main()
{
    // A1: 10x30, A2: 30x5, A3: 5x60
    vector<int> dims = {10, 30, 5, 60};
    string order;
    int cost = matrixChainOrder(dims, order);
    cout << "Minimum multiplications: " << cost << endl;
    cout << "Order: " << order << endl;

    // A1: 40x20, A2: 20x30, A3: 30x10, A4: 10x30
    dims = {40, 20, 30, 10, 30};
    cost = matrixChainOrder(dims, order);
    cout << "\nMinimum multiplications: " << cost << endl;
    cout << "Order: " << order << endl;

    return 0;
}
