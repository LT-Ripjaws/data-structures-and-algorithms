// Recursion basics.
// - factorial: n! = n * (n - 1)!, base case 0! = 1. O(n) calls.
// - naive Fibonacci: two recursive calls per step, O(2^n) time.
// - memoised Fibonacci: store each answer once, O(n) time.
#include <iostream>
using namespace std;

long long factorial(int n)
{
    if (n <= 1)
        return 1;
    return n * factorial(n - 1);
}

long long fibNaive(int n)
{
    if (n <= 1)
        return n;
    return fibNaive(n - 1) + fibNaive(n - 2);
}

long long memo[100]; // 0 means "not computed yet" for n >= 2

long long fibMemo(int n)
{
    if (n <= 1)
        return n;
    if (memo[n] != 0)
        return memo[n]; // already computed
    memo[n] = fibMemo(n - 1) + fibMemo(n - 2);
    return memo[n];
}

int main()
{
    for (int n = 0; n <= 10; n++)
        cout << n << "! = " << factorial(n) << endl;

    cout << "\nFibonacci (naive): ";
    for (int n = 0; n <= 15; n++)
        cout << fibNaive(n) << " ";

    cout << "\nFibonacci(80) with memoisation: " << fibMemo(80) << endl;

    return 0;
}
