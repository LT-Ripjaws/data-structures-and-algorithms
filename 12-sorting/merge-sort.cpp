// Merge sort (divide and conquer): split the array in half, sort each half
// recursively, then merge the two sorted halves.
// T(n) = 2T(n/2) + O(n), so O(n log n) in every case. Stable.
// Needs O(n) extra space for the merge.
#include <iostream>
#include <vector>
using namespace std;

void merge(int arr[], int left, int middle, int right)
{
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // Copy both halves out, because merging writes back into arr.
    vector<int> leftPart(n1), rightPart(n2);
    for (int i = 0; i < n1; i++)
        leftPart[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightPart[j] = arr[middle + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        // <= keeps equal elements in their original order (stability).
        if (leftPart[i] <= rightPart[j])
        {
            arr[k] = leftPart[i];
            i++;
        }
        else
        {
            arr[k] = rightPart[j];
            j++;
        }
        k++;
    }

    // One half may still have items left; copy them over.
    while (i < n1)
    {
        arr[k] = leftPart[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = rightPart[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int middle = low + (high - low) / 2;
        mergeSort(arr, low, middle);
        mergeSort(arr, middle + 1, high);
        merge(arr, low, middle, high);
    }
}

int main()
{
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);

    cout << "Sorted: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
