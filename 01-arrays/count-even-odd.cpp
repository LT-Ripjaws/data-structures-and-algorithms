// Count even and odd numbers in an array. O(n).
#include <iostream>
using namespace std;

int main()
{
    int arr[10] = {2, 12, 6, 8, 16, 11, 13, 15, 17, 34};
    int evenCount = 0;
    int oddCount = 0;

    for (int i = 0; i < 10; i++)
    {
        if (arr[i] % 2 == 0)
            evenCount++;
        else
            oddCount++;
    }

    cout << "Number of even: " << evenCount << endl;
    cout << "Number of odd: " << oddCount << endl;

    return 0;
}
