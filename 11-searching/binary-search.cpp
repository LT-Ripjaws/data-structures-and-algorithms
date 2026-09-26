// Binary search on a sorted array: compare with the middle element and
// discard the half that cannot contain the target. O(log n).
// Includes iterative and recursive versions, plus a lower-bound search that
// finds the first position where the target could be inserted.
#include <iostream>
using namespace std;

int binarySearch(const int arr[], int n, int target)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2; // avoids overflow of (low + high)
        if (arr[mid] == target)
            return mid;
        if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int binarySearchRecursive(const int arr[], int low, int high, int target)
{
    if (low > high)
        return -1;
    int mid = low + (high - low) / 2;
    if (arr[mid] == target)
        return mid;
    if (arr[mid] < target)
        return binarySearchRecursive(arr, mid + 1, high, target);
    return binarySearchRecursive(arr, low, mid - 1, target);
}

// First index whose value is >= target (n if every value is smaller).
int lowerBound(const int arr[], int n, int target)
{
    int low = 0, high = n;
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}

int main()
{
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = sizeof(arr) / sizeof(arr[0]);

    int targets[] = {23, 2, 91, 40};
    for (int t : targets)
    {
        cout << "Search " << t << ": iterative " << binarySearch(arr, n, t)
             << ", recursive " << binarySearchRecursive(arr, 0, n - 1, t)
             << ", lower bound " << lowerBound(arr, n, t) << endl;
    }

    return 0;
}
