// Pointer basics: addresses, dereferencing, and how an array name acts as a
// pointer to its first element (arr[i] is the same as *(arr + i)).
#include <cstdint>
#include <iostream>
using namespace std;

int main()
{
    int a = 99;
    int *p = &a;
    int b = *p; // copy of the value p points to

    cout << "Address of a:           " << (uintptr_t)&a << endl;
    cout << "Value of a:             " << a << endl;
    cout << "Address of p itself:    " << (uintptr_t)&p << endl;
    cout << "Address stored in p:    " << (uintptr_t)p << endl;
    cout << "Value p points to (*p): " << *p << endl;
    cout << "Value of b:             " << b << endl;

    *p = 7; // writes through the pointer, so a changes and b does not
    cout << "After *p = 7: a = " << a << ", b = " << b << endl;

    float r[5] = {12.5, 24.8, 36.8, 49.1, 58.3};
    cout << "\nr[0] = " << r[0] << ", *r = " << *r << endl;
    cout << "r[2] = " << r[2] << ", *(r + 2) = " << *(r + 2) << endl;
    cout << "*r + 1 = " << *r + 1 << " (adds 1 to the value, not the address)" << endl;

    float *q = r; // same as &r[0]
    for (int i = 0; i < 5; i++, q++)
        cout << "Element " << (i + 1) << " is " << *q << endl;

    return 0;
}
