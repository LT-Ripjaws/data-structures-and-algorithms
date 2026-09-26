// Fractional knapsack (greedy): items can be split, so always take as much
// as possible of the item with the highest profit per unit of weight.
// O(n log n) for the sort. Greedy is optimal here; for the 0/1 version
// (no splitting) see ../14-dynamic-programming/knapsack-0-1.cpp.
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Item
{
    int id; // 1-based position in the input, kept through the sort
    int weight;
    int profit;
};

// Higher profit per unit of weight comes first.
bool compareByRatio(const Item &a, const Item &b)
{
    double ratioA = (double)a.profit / a.weight;
    double ratioB = (double)b.profit / b.weight;
    return ratioA > ratioB;
}

double fractionalKnapsack(vector<Item> items, int capacity)
{
    sort(items.begin(), items.end(), compareByRatio);

    double totalProfit = 0.0;
    int remaining = capacity;

    cout << "Item  Fraction taken" << endl;
    for (const Item &item : items)
    {
        if (remaining == 0)
            break;
        if (item.weight <= remaining)
        {
            remaining -= item.weight;
            totalProfit += item.profit;
            cout << item.id << "     1" << endl;
        }
        else
        {
            double fraction = (double)remaining / item.weight;
            totalProfit += item.profit * fraction;
            cout << item.id << "     " << fraction << endl;
            remaining = 0;
        }
    }
    return totalProfit;
}

int main()
{
    int capacity = 50;
    vector<Item> items = {
        {1, 10, 60},
        {2, 20, 100},
        {3, 30, 120},
    };

    double profit = fractionalKnapsack(items, capacity);
    cout << "Maximum profit: " << profit << endl;
    return 0;
}
