// Longest common subsequence (LCS) of two strings.
// dp[i][j] = LCS length of the first i characters of X and the first j of Y.
//   If X[i-1] == Y[j-1]: dp[i][j] = dp[i-1][j-1] + 1
//   Otherwise:           dp[i][j] = max(dp[i-1][j], dp[i][j-1])
// Walking back from dp[m][n] recovers one LCS. O(m * n) time and space.
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string lcs(const string &X, const string &Y)
{
    int m = X.length();
    int n = Y.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (X[i - 1] == Y[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // Walk back from the bottom-right corner. A match means that character is
    // part of the LCS; otherwise move toward the larger neighbour.
    // Characters are found last-to-first, so the result is reversed at the end.
    string result = "";
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (X[i - 1] == Y[j - 1])
        {
            result += X[i - 1];
            --i;
            --j;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            --i;
        }
        else
        {
            --j;
        }
    }
    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    string pairs[][2] = {{"ABCD", "ACDF"}, {"AGGTAB", "GXTXAYB"}, {"ABC", "XYZ"}};

    for (auto &p : pairs)
    {
        string result = lcs(p[0], p[1]);
        cout << p[0] << ", " << p[1] << " -> \"" << result << "\" (length " << result.length() << ")" << endl;
    }

    return 0;
}
