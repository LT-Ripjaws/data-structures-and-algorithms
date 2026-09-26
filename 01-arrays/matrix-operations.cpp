// 2D array (matrix) operations: traversal, addition, subtraction,
// multiplication and transpose.
// Addition/subtraction/transpose are O(r * c); multiplication is O(r * c * k).
#include <iostream>
using namespace std;

const int MAX = 10;

void print(const int m[][MAX], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            cout << m[i][j] << "\t";
        cout << endl;
    }
}

void add(const int a[][MAX], const int b[][MAX], int result[][MAX], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result[i][j] = a[i][j] + b[i][j];
}

void subtract(const int a[][MAX], const int b[][MAX], int result[][MAX], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result[i][j] = a[i][j] - b[i][j];
}

// a is rowsA x colsA, b is colsA x colsB. Returns false when the sizes
// do not allow multiplication.
bool multiply(const int a[][MAX], int rowsA, int colsA,
              const int b[][MAX], int rowsB, int colsB,
              int result[][MAX])
{
    if (colsA != rowsB)
        return false;

    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++)
                result[i][j] += a[i][k] * b[k][j];
        }
    }
    return true;
}

void transpose(const int m[][MAX], int result[][MAX], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result[j][i] = m[i][j];
}

int main()
{
    int a[MAX][MAX] = {{1, 2, 3}, {4, 5, 6}};
    int b[MAX][MAX] = {{6, 5, 4}, {3, 2, 1}};
    int c[MAX][MAX] = {{1, 0}, {0, 1}, {2, 3}};
    int result[MAX][MAX];

    cout << "Matrix A (2x3):" << endl;
    print(a, 2, 3);

    cout << "\nA + B:" << endl;
    add(a, b, result, 2, 3);
    print(result, 2, 3);

    cout << "\nA - B:" << endl;
    subtract(a, b, result, 2, 3);
    print(result, 2, 3);

    cout << "\nA x C (2x3 times 3x2):" << endl;
    if (multiply(a, 2, 3, c, 3, 2, result))
        print(result, 2, 2);

    cout << "\nA x B is " << (multiply(a, 2, 3, b, 2, 3, result) ? "possible" : "not possible")
         << " (columns of A must equal rows of B)" << endl;

    cout << "\nTranspose of A:" << endl;
    transpose(a, result, 2, 3);
    print(result, 3, 2);

    return 0;
}
