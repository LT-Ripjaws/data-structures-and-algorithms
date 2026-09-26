// Min-heap stored in an array. The tree is complete, so for index i the
// children are at 2i + 1 and 2i + 2 and the parent is at (i - 1) / 2.
// Every parent is smaller than its children, so the minimum is at index 0.
// insert and extractMin: O(log n). getMin: O(1). Used for priority queues.
#include <iostream>
#include <vector>
using namespace std;

class MinHeap
{
private:
    vector<int> heap;

    void siftUp(int i)
    {
        while (i > 0)
        {
            int parent = (i - 1) / 2;
            if (heap[parent] <= heap[i])
                break;
            swap(heap[parent], heap[i]);
            i = parent;
        }
    }

    void siftDown(int i)
    {
        int n = heap.size();
        while (true)
        {
            int smallest = i;
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            if (left < n && heap[left] < heap[smallest])
                smallest = left;
            if (right < n && heap[right] < heap[smallest])
                smallest = right;
            if (smallest == i)
                break;
            swap(heap[i], heap[smallest]);
            i = smallest;
        }
    }

public:
    bool isEmpty() const { return heap.empty(); }

    void insert(int value)
    {
        heap.push_back(value);
        siftUp(heap.size() - 1);
    }

    // getMin and extractMin return false when the heap is empty.
    bool getMin(int &value) const
    {
        if (heap.empty())
            return false;
        value = heap[0];
        return true;
    }

    // Move the last item to the root, then push it down to its place.
    bool extractMin(int &value)
    {
        if (heap.empty())
            return false;
        value = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty())
            siftDown(0);
        return true;
    }

    void display() const
    {
        for (int x : heap)
            cout << x << " ";
        cout << endl;
    }
};

int main()
{
    MinHeap h;
    int values[] = {40, 10, 30, 5, 50, 20, 15};
    for (int v : values)
        h.insert(v);

    cout << "Heap array: ";
    h.display();
    int value;
    if (h.getMin(value))
        cout << "Minimum: " << value << endl;

    cout << "Extracting in order: ";
    while (h.extractMin(value))
        cout << value << " ";
    cout << endl;
    cout << "Extract from empty heap: " << (h.extractMin(value) ? "got a value" : "heap is empty") << endl;

    return 0;
}
