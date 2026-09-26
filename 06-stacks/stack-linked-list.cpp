// Stack on a singly linked list. The head of the list is the top, so push
// and pop are O(1) and the stack has no fixed capacity.
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class Stack
{
private:
    Node *top;

public:
    Stack() : top(nullptr) {}

    // Copying would share nodes and delete them twice, so it is disabled.
    Stack(const Stack &) = delete;
    Stack &operator=(const Stack &) = delete;

    ~Stack()
    {
        while (top != nullptr)
        {
            Node *temp = top;
            top = top->next;
            delete temp;
        }
    }

    void push(int x)
    {
        Node *node = new Node();
        node->data = x;
        node->next = top;
        top = node;
    }

    // Returns the value that was removed, or -1 if the stack is empty.
    int pop()
    {
        if (top == nullptr)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        int data = top->data;
        Node *temp = top;
        top = top->next;
        delete temp;
        return data;
    }

    int peek() const
    {
        if (top == nullptr)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return top->data;
    }

    bool isEmpty() const { return top == nullptr; }
};

int main()
{
    Stack s;
    s.push(5);
    s.push(10);
    s.push(15);
    cout << "Pushed 5, 10, 15" << endl;
    cout << "Top element: " << s.peek() << endl;
    cout << "Popped: " << s.pop() << endl;
    cout << "Popped: " << s.pop() << endl;
    cout << "Top element now: " << s.peek() << endl;
    cout << "Popped: " << s.pop() << endl;
    cout << "Empty: " << (s.isEmpty() ? "yes" : "no") << endl;
    return 0;
}
