// Queue on an array (FIFO), used to check whether a string is a palindrome.
// The string is enqueued in reverse, then dequeued and compared with the
// original from the front. enqueue/dequeue: O(1); the check is O(n).
// This is a linear queue: space before `front` is not reused. See
// circular-queue.cpp for the version that reuses it.
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Queue
{
private:
    vector<char> arr;
    int front, rear;

public:
    explicit Queue(int capacity) : arr(capacity), front(-1), rear(-1) {}

    bool isEmpty() const { return front == -1; }
    bool isFull() const { return rear == (int)arr.size() - 1; }

    void enqueue(char x)
    {
        if (isFull())
        {
            cout << "Error: queue is full." << endl;
            return;
        }
        if (isEmpty())
            front = 0;
        arr[++rear] = x;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Error: queue is empty." << endl;
            return;
        }
        if (front == rear) // removed the last item
            front = rear = -1;
        else
            front++;
    }

    char getFront() const { return isEmpty() ? '\0' : arr[front]; }
};

bool isPalindrome(const string &str)
{
    int n = str.length();
    Queue q(n); // room for every character, however long the string

    for (int i = n - 1; i >= 0; i--)
        q.enqueue(str[i]);

    for (int i = 0; i < n; i++)
    {
        if (q.getFront() != str[i])
            return false;
        q.dequeue();
    }
    return true;
}

int main()
{
    string words[] = {"madam", "racecar", "queue", "noon"};

    for (const string &w : words)
    {
        if (isPalindrome(w))
            cout << w << " is a palindrome." << endl;
        else
            cout << w << " is not a palindrome." << endl;
    }

    return 0;
}
