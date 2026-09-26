// Backtracking with recursion.
// - permutations: fix one character at each position, recurse, then undo
//   the swap. n! results, O(n * n!) time.
// - subsets: for each element, either take it or skip it. 2^n results.
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void permutations(string &s, int index)
{
    if (index == (int)s.length())
    {
        cout << s << " ";
        return;
    }
    for (int i = index; i < (int)s.length(); i++)
    {
        swap(s[index], s[i]);
        permutations(s, index + 1);
        swap(s[index], s[i]); // undo so the next iteration starts clean
    }
}

void subsets(const vector<int> &items, int index, vector<int> &current)
{
    if (index == (int)items.size())
    {
        cout << "{ ";
        for (int x : current)
            cout << x << " ";
        cout << "} ";
        return;
    }
    current.push_back(items[index]); // take it
    subsets(items, index + 1, current);
    current.pop_back(); // skip it
    subsets(items, index + 1, current);
}

int main()
{
    string s = "abc";
    cout << "Permutations of " << s << ": ";
    permutations(s, 0);

    vector<int> items = {1, 2, 3};
    vector<int> current;
    cout << "\nSubsets of {1, 2, 3}: ";
    subsets(items, 0, current);
    cout << endl;

    return 0;
}
