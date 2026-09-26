// Remove duplicate values from an array in place, keeping the first
// occurrence of each value. O(n^2) time, O(1) extra space.
#include <iostream>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 5, 3, 6, 7, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    bool unique = true;

    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                // Shift the rest left over the duplicate.
                for (int k = j; k < size - 1; k++)
                    arr[k] = arr[k + 1];
                size--;
                j--; // re-check the element that moved into position j
                unique = false;
            }
        }
    }

    if (unique)
    {
        cout << "Array already unique!" << endl;
    }
    else
    {
        cout << "Changed array: ";
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    return 0;
}
