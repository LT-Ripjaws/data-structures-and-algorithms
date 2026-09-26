// Merge two arrays into a third one and print it in reverse order.
// O(n + m).
#include <iostream>
using namespace std;

int main()
{
    const int sizeA = 3;
    const int sizeB = 4;
    const int sizeMerged = sizeA + sizeB;
    int arrA[sizeA] = {4, 8, 15};
    int arrB[sizeB] = {16, 23, 42, 7};
    int merged[sizeMerged];

    for (int i = 0; i < sizeA; i++)
        merged[i] = arrA[i];

    for (int i = 0; i < sizeB; i++)
        merged[sizeA + i] = arrB[i];

    cout << "Merged array: ";
    for (int i = 0; i < sizeMerged; i++)
        cout << merged[i] << " ";

    cout << "\nMerged array in reverse order: ";
    for (int i = sizeMerged - 1; i >= 0; i--)
        cout << merged[i] << " ";
    cout << endl;

    return 0;
}
