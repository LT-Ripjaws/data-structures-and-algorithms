// Array operations: traverse, sum, max/min, linear search, count odd/even,
// insert at a position, delete at a position.
// Insert/delete shift elements, so they cost O(n); index access is O(1).
#include <iostream>
using namespace std;

const int CAPACITY = 100;

void display(const int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int sum(const int arr[], int size)
{
    int total = 0;
    for (int i = 0; i < size; i++)
        total += arr[i];
    return total;
}

// Start from the first element, not 0, so arrays with only negative
// numbers still give the right answer.
void maxMin(const int arr[], int size, int &maximum, int &minimum)
{
    maximum = minimum = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > maximum)
            maximum = arr[i];
        if (arr[i] < minimum)
            minimum = arr[i];
    }
}

// Returns the index of the first match, or -1.
int search(const int arr[], int size, int item)
{
    for (int i = 0; i < size; i++)
        if (arr[i] == item)
            return i;
    return -1;
}

void countOddEven(const int arr[], int size, int &odd, int &even)
{
    odd = even = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] % 2 == 0)
            even++;
        else
            odd++;
    }
}

// Shift everything from pos one step right, then write the value.
bool insertAt(int arr[], int &size, int pos, int value)
{
    if (size == CAPACITY || pos < 0 || pos > size)
        return false;
    for (int i = size; i > pos; i--)
        arr[i] = arr[i - 1];
    arr[pos] = value;
    size++;
    return true;
}

// Shift everything after pos one step left.
bool deleteAt(int arr[], int &size, int pos)
{
    if (pos < 0 || pos >= size)
        return false;
    for (int i = pos; i < size - 1; i++)
        arr[i] = arr[i + 1];
    size--;
    return true;
}

int main()
{
    int arr[CAPACITY] = {12, -4, 7, 30, 18, 5};
    int size = 6;

    cout << "Array: ";
    display(arr, size);

    cout << "Sum: " << sum(arr, size) << endl;

    int maximum, minimum;
    maxMin(arr, size, maximum, minimum);
    cout << "Max: " << maximum << ", Min: " << minimum << endl;

    cout << "Index of 30: " << search(arr, size, 30) << endl;
    cout << "Index of 99: " << search(arr, size, 99) << endl;

    int odd, even;
    countOddEven(arr, size, odd, even);
    cout << "Odd: " << odd << ", Even: " << even << endl;

    insertAt(arr, size, 0, 1);    // at the start
    insertAt(arr, size, size, 99); // at the end
    insertAt(arr, size, 3, 50);   // in the middle
    cout << "After inserts: ";
    display(arr, size);

    deleteAt(arr, size, 0);
    deleteAt(arr, size, size - 1);
    cout << "After deleting first and last: ";
    display(arr, size);

    return 0;
}
