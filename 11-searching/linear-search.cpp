// Linear search: check each element in turn until the target is found.
// Works on unsorted data. O(n) worst and average case, O(1) best case.
#include <iostream>
using namespace std;

int linearSearch(const int arr[], int n, int target)
{
    for (int i = 0; i < n; i++)
        if (arr[i] == target)
            return i;
    return -1;
}

int main()
{
    int arr[] = {34, 7, 23, 32, 5, 62};
    int n = sizeof(arr) / sizeof(arr[0]);

    int targets[] = {23, 5, 100};
    for (int t : targets)
    {
        int index = linearSearch(arr, n, t);
        if (index != -1)
            cout << t << " found at index " << index << endl;
        else
            cout << t << " not found" << endl;
    }

    return 0;
}
