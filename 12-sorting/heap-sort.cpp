// Heap sort: build a max-heap in the array, then repeatedly swap the root
// (the largest element) to the end and restore the heap on the rest.
// O(n log n) in every case, O(1) extra space. Not stable.
#include <iostream>
using namespace std;

// Push arr[i] down until both children are smaller, within the first n items.
void heapify(int arr[], int n, int i)
{
    while (true)
    {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < n && arr[left] > arr[largest])
            largest = left;
        if (right < n && arr[right] > arr[largest])
            largest = right;
        if (largest == i)
            return;
        swap(arr[i], arr[largest]);
        i = largest;
    }
}

void heapSort(int arr[], int n)
{
    // Build the heap from the last non-leaf node upwards: O(n).
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int end = n - 1; end > 0; end--)
    {
        swap(arr[0], arr[end]);
        heapify(arr, end, 0);
    }
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n);

    cout << "Sorted: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
