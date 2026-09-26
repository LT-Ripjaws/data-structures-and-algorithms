// Stack on a fixed-size array. LIFO: the last item pushed is the first popped.
// push, pop, peek: O(1).
#include <iostream>
using namespace std;

const int MAX_SIZE = 5;

class Stack
{
private:
    int arr[MAX_SIZE];
    int top; // index of the top item, -1 when empty

public:
    Stack() : top(-1) {}

    bool isEmpty() const { return top == -1; }
    bool isFull() const { return top == MAX_SIZE - 1; }

    bool push(int value)
    {
        if (isFull())
        {
            cout << "Stack overflow, cannot push " << value << endl;
            return false;
        }
        arr[++top] = value;
        return true;
    }

    // Returns false on underflow; the popped value goes into `value`.
    bool pop(int &value)
    {
        if (isEmpty())
        {
            cout << "Stack underflow" << endl;
            return false;
        }
        value = arr[top--];
        return true;
    }

    bool peek(int &value) const
    {
        if (isEmpty())
            return false;
        value = arr[top];
        return true;
    }
};

int main()
{
    Stack s;
    for (int i = 1; i <= 6; i++) // the 6th push overflows
        s.push(i * 10);

    int value;
    if (s.peek(value))
        cout << "Top: " << value << endl;

    cout << "Popping: ";
    while (!s.isEmpty())
    {
        s.pop(value);
        cout << value << " ";
    }
    cout << endl;

    s.pop(value); // popping an empty stack reports underflow

    return 0;
}
