// Counting sort for non-negative integers: count how often each value occurs,
// turn the counts into end positions (prefix sums), then place each element.
// O(n + k) where k is the largest value. Stable (the last loop walks backwards).
// Not comparison based, so it can beat O(n log n) when k is small.
#include <iostream>
#include <vector>
using namespace std;

void countingSort(int arr[], int n)
{
    if (n <= 0)
        return;
    int maxValue = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > maxValue)
            maxValue = arr[i];

    vector<int> count(maxValue + 1, 0);
    vector<int> output(n);

    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    for (int i = 1; i <= maxValue; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

int main()
{
    int arr[] = {4, 2, 2, 8, 3, 3, 1, 0, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    countingSort(arr, n);

    cout << "Sorted: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
