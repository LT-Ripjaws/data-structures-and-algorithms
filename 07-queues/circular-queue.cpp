// Circular queue on a fixed array. When rear reaches the end it wraps to
// index 0, so slots freed by dequeue are reused. A count field tells full
// from empty. enqueue/dequeue: O(1).
#include <iostream>
using namespace std;

const int CAPACITY = 5;

class CircularQueue
{
private:
    int arr[CAPACITY];
    int front; // index of the first item
    int count; // number of items stored

public:
    CircularQueue() : front(0), count(0) {}

    bool isEmpty() const { return count == 0; }
    bool isFull() const { return count == CAPACITY; }

    bool enqueue(int value)
    {
        if (isFull())
        {
            cout << "Queue full, cannot enqueue " << value << endl;
            return false;
        }
        int rear = (front + count) % CAPACITY;
        arr[rear] = value;
        count++;
        return true;
    }

    bool dequeue(int &value)
    {
        if (isEmpty())
            return false;
        value = arr[front];
        front = (front + 1) % CAPACITY;
        count--;
        return true;
    }

    void display() const
    {
        cout << "[ ";
        for (int i = 0; i < count; i++)
            cout << arr[(front + i) % CAPACITY] << " ";
        cout << "] front index = " << front << endl;
    }
};

int main()
{
    CircularQueue q;
    for (int i = 1; i <= 6; i++) // the 6th enqueue fails
        q.enqueue(i * 10);
    q.display();

    int value;
    q.dequeue(value);
    q.dequeue(value);
    cout << "Dequeued two items, last was " << value << endl;
    q.display();

    // These wrap around into the two freed slots at the start of the array.
    q.enqueue(60);
    q.enqueue(70);
    q.display();

    cout << "Draining: ";
    while (q.dequeue(value))
        cout << value << " ";
    cout << endl;

    return 0;
}
