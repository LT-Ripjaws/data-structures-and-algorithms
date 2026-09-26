// Doubly linked list: each node points to both the next and previous node,
// so the list can be walked in both directions.
// Insert/delete at either end: O(1) (a tail pointer is kept).
// Search and delete by value: O(n).
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList
{
private:
    Node *head;
    Node *tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Copying would share nodes and delete them twice, so it is disabled.
    DoublyLinkedList(const DoublyLinkedList &) = delete;
    DoublyLinkedList &operator=(const DoublyLinkedList &) = delete;

    ~DoublyLinkedList()
    {
        while (head != nullptr)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insertAtHead(int value)
    {
        Node *node = new Node(value);
        node->next = head;
        if (head != nullptr)
            head->prev = node;
        else
            tail = node;
        head = node;
    }

    void insertAtTail(int value)
    {
        Node *node = new Node(value);
        node->prev = tail;
        if (tail != nullptr)
            tail->next = node;
        else
            head = node;
        tail = node;
    }

    bool removeHead()
    {
        if (head == nullptr)
            return false;
        Node *old = head;
        head = head->next;
        if (head != nullptr)
            head->prev = nullptr;
        else
            tail = nullptr;
        delete old;
        return true;
    }

    // O(1) because of the tail pointer and prev links; a singly linked list
    // would have to walk the whole list to find the node before the tail.
    bool removeTail()
    {
        if (tail == nullptr)
            return false;
        Node *old = tail;
        tail = tail->prev;
        if (tail != nullptr)
            tail->next = nullptr;
        else
            head = nullptr;
        delete old;
        return true;
    }

    // Removes the first node with this value. The prev pointer means no
    // separate "previous" variable is needed while searching.
    bool remove(int value)
    {
        Node *current = head;
        while (current != nullptr && current->data != value)
            current = current->next;
        if (current == nullptr)
            return false;

        if (current->prev != nullptr)
            current->prev->next = current->next;
        else
            head = current->next;

        if (current->next != nullptr)
            current->next->prev = current->prev;
        else
            tail = current->prev;

        delete current;
        return true;
    }

    void displayForward() const
    {
        cout << "NULL <- ";
        for (Node *current = head; current != nullptr; current = current->next)
            cout << current->data << (current->next ? " <-> " : " ");
        cout << "-> NULL" << endl;
    }

    void displayBackward() const
    {
        for (Node *current = tail; current != nullptr; current = current->prev)
            cout << current->data << " ";
        cout << endl;
    }
};

int main()
{
    DoublyLinkedList list;
    list.insertAtTail(10);
    list.insertAtTail(20);
    list.insertAtTail(30);
    list.insertAtHead(5);

    cout << "Forward:  ";
    list.displayForward();
    cout << "Backward: ";
    list.displayBackward();

    list.removeHead(); // 5
    list.removeTail(); // 30
    cout << "After removing head and tail: ";
    list.displayForward();

    list.insertAtTail(40);
    list.remove(10);
    list.remove(99); // not present
    cout << "After adding 40 and removing 10: ";
    list.displayForward();

    return 0;
}
