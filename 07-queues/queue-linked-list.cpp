// Queue on a linked list with front and rear pointers. Enqueue at the rear,
// dequeue from the front, both O(1), with no fixed capacity.
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int value) : data(value), next(nullptr) {}
};

class Queue
{
private:
    Node *front;
    Node *rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    // Copying would share nodes and delete them twice, so it is disabled.
    Queue(const Queue &) = delete;
    Queue &operator=(const Queue &) = delete;

    ~Queue()
    {
        int ignored;
        while (dequeue(ignored))
        {
        }
    }

    bool isEmpty() const { return front == nullptr; }

    void enqueue(int value)
    {
        Node *node = new Node(value);
        if (rear == nullptr)
        {
            front = rear = node;
            return;
        }
        rear->next = node;
        rear = node;
    }

    bool dequeue(int &value)
    {
        if (front == nullptr)
            return false;
        Node *temp = front;
        value = temp->data;
        front = front->next;
        if (front == nullptr) // queue became empty
            rear = nullptr;
        delete temp;
        return true;
    }

    void display() const
    {
        cout << "front -> ";
        for (Node *n = front; n != nullptr; n = n->next)
            cout << n->data << " ";
        cout << "<- rear" << endl;
    }
};

int main()
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.display();

    int value;
    q.dequeue(value);
    cout << "Dequeued: " << value << endl;
    q.enqueue(4);
    q.display();

    return 0;
}
