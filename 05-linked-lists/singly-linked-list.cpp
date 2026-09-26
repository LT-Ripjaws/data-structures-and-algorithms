// Singly linked list: each node holds data and a pointer to the next node.
// Insert/delete at the head: O(1). Insert at the tail, search, delete by
// value: O(n). Reverse: O(n) time, O(1) extra space.
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int value) : data(value), next(nullptr) {}
};

class SinglyLinkedList
{
private:
    Node *head;

public:
    SinglyLinkedList() : head(nullptr) {}

    // Copying would share nodes and delete them twice, so it is disabled.
    SinglyLinkedList(const SinglyLinkedList &) = delete;
    SinglyLinkedList &operator=(const SinglyLinkedList &) = delete;

    ~SinglyLinkedList()
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
        head = node;
    }

    void insertAtTail(int value)
    {
        Node *node = new Node(value);
        if (head == nullptr)
        {
            head = node;
            return;
        }
        Node *current = head;
        while (current->next != nullptr)
            current = current->next;
        current->next = node;
    }

    // Insert so the node ends up at `position` (0 = head).
    bool insertAt(int position, int value)
    {
        if (position < 0)
            return false;
        if (position == 0)
        {
            insertAtHead(value);
            return true;
        }
        Node *current = head;
        for (int i = 0; current != nullptr && i < position - 1; i++)
            current = current->next;
        if (current == nullptr)
            return false;
        Node *node = new Node(value);
        node->next = current->next;
        current->next = node;
        return true;
    }

    // Removes the first node with this value.
    bool remove(int value)
    {
        Node *current = head;
        Node *previous = nullptr;
        while (current != nullptr && current->data != value)
        {
            previous = current;
            current = current->next;
        }
        if (current == nullptr)
            return false;
        if (previous == nullptr)
            head = current->next;
        else
            previous->next = current->next;
        delete current;
        return true;
    }

    bool search(int value) const
    {
        for (Node *current = head; current != nullptr; current = current->next)
            if (current->data == value)
                return true;
        return false;
    }

    // Point every node back at the one before it.
    void reverse()
    {
        Node *previous = nullptr;
        Node *current = head;
        while (current != nullptr)
        {
            Node *next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        head = previous;
    }

    void display() const
    {
        for (Node *current = head; current != nullptr; current = current->next)
            cout << current->data << " -> ";
        cout << "NULL" << endl;
    }
};

int main()
{
    SinglyLinkedList list;
    list.insertAtTail(10);
    list.insertAtTail(20);
    list.insertAtTail(30);
    list.insertAtHead(5);
    list.insertAt(2, 15);
    cout << "List: ";
    list.display();

    cout << "Search 20: " << (list.search(20) ? "found" : "not found") << endl;
    cout << "Search 99: " << (list.search(99) ? "found" : "not found") << endl;

    list.remove(5);
    list.remove(30);
    cout << "After removing 5 and 30: ";
    list.display();

    list.reverse();
    cout << "Reversed: ";
    list.display();

    return 0;
}
