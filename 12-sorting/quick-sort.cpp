// Quick sort (divide and conquer): pick a pivot, move smaller elements to its
// left and larger ones to its right, then sort both sides recursively.
// Uses the first element as the pivot (Hoare-style scanning from both ends).
// O(n log n) average, O(n^2) worst (for example, already sorted input with
// this pivot choice). In place, not stable.
// The recursion uses O(log n) stack space on average, O(n) in the worst case.
#include <iostream>
using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j)
    {
        while (arr[i] <= pivot && i < high)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i < j)
            swap(arr[i], arr[j]);
    }

    swap(arr[low], arr[j]); // put the pivot in its final position
    return j;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    cout << "Sorted: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
