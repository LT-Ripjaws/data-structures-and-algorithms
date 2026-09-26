// Pointers as function parameters:
// - swap two values through pointers
// - arrays are passed as a pointer, so the function changes the caller's array
// - void* can point to any type; the function casts it back using the size
#include <iostream>
using namespace std;

void swapValues(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void doubleArray(int arr[], int length)
{
    for (int i = 0; i < length; i++)
        arr[i] *= 2;
}

void printArray(const int arr[], int length)
{
    for (int i = 0; i < length; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void increase(void *data, int size)
{
    if (size == sizeof(char))
    {
        char *pchar = (char *)data; // cast back to the real type first
        (*pchar)++;
    }
    else if (size == sizeof(int))
    {
        int *pint = (int *)data;
        (*pint)++;
    }
}

void decrease(void *data, int size)
{
    if (size == sizeof(char))
    {
        char *pchar = (char *)data;
        (*pchar)--;
    }
    else if (size == sizeof(int))
    {
        int *pint = (int *)data;
        (*pint)--;
    }
}

int main()
{
    int num1 = 44, num2 = 33;
    swapValues(&num1, &num2);
    cout << "After swap: num1 = " << num1 << ", num2 = " << num2 << endl;

    int numbers[3] = {11, 22, 33};
    doubleArray(numbers, 3);
    cout << "Doubled array: ";
    printArray(numbers, 3);

    char c = 'f';
    int n = 1000;
    increase(&c, sizeof(c));
    increase(&n, sizeof(n));
    cout << "After increase: " << c << ", " << n << endl;

    decrease(&c, sizeof(c));
    decrease(&n, sizeof(n));
    cout << "After decrease: " << c << ", " << n << endl;

    return 0;
}
