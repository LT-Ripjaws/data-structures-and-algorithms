// Hash table (hash map) with separate chaining.
// A hash function turns a key into a bucket index. Keys that land in the
// same bucket are kept together in that bucket's list.
// When there are more entries than buckets, the table doubles its bucket
// count and re-inserts every entry. That keeps the lists short, so insert,
// find and remove are O(1) on average. The worst case is O(n) if every key
// lands in the same bucket.
#include <iostream>
#include <list>
#include <string>
#include <vector>
using namespace std;

struct Entry
{
    string key;
    int value;
};

class HashTable
{
private:
    vector<list<Entry>> buckets;
    int entryCount;

    // Polynomial rolling hash, reduced to a bucket index.
    int indexFor(const string &key) const
    {
        unsigned long hash = 0;
        for (char c : key)
            hash = hash * 31 + (unsigned char)c;
        return hash % buckets.size();
    }

    void grow()
    {
        vector<list<Entry>> oldBuckets = buckets;
        buckets.clear();
        buckets.resize(oldBuckets.size() * 2);
        for (const list<Entry> &bucket : oldBuckets)
            for (const Entry &entry : bucket)
                buckets[indexFor(entry.key)].push_back(entry);
    }

public:
    // Always at least one bucket, so indexFor never divides by zero.
    HashTable(int bucketCount = 7)
    {
        if (bucketCount < 1)
            bucketCount = 1;
        buckets.resize(bucketCount);
        entryCount = 0;
    }

    int size() const { return entryCount; }
    int bucketCount() const { return buckets.size(); }

    // Inserts the key, or updates its value if it already exists.
    void put(const string &key, int value)
    {
        list<Entry> &bucket = buckets[indexFor(key)];
        for (Entry &entry : bucket)
        {
            if (entry.key == key)
            {
                entry.value = value;
                return;
            }
        }
        bucket.push_back({key, value});
        entryCount++;

        if (entryCount > bucketCount())
            grow();
    }

    bool get(const string &key, int &value) const
    {
        const list<Entry> &bucket = buckets[indexFor(key)];
        for (const Entry &entry : bucket)
        {
            if (entry.key == key)
            {
                value = entry.value;
                return true;
            }
        }
        return false;
    }

    bool remove(const string &key)
    {
        list<Entry> &bucket = buckets[indexFor(key)];
        for (auto it = bucket.begin(); it != bucket.end(); ++it)
        {
            if (it->key == key)
            {
                bucket.erase(it);
                entryCount--;
                return true;
            }
        }
        return false;
    }

    void display() const
    {
        for (int i = 0; i < bucketCount(); i++)
        {
            cout << "bucket " << i << ": ";
            for (const Entry &entry : buckets[i])
                cout << "(" << entry.key << ", " << entry.value << ") ";
            cout << endl;
        }
    }
};

int main()
{
    // Word frequency counting, one of the common uses of a hash map.
    string words[] = {"apple", "banana", "apple", "cherry", "date",
                      "banana", "apple", "fig", "grape", "cherry"};

    HashTable counts;
    for (const string &word : words)
    {
        int current = 0;
        counts.get(word, current);
        counts.put(word, current + 1);
    }
    counts.display();

    int value;
    if (counts.get("apple", value))
        cout << "\napple appears " << value << " times" << endl;

    counts.remove("banana");
    cout << "banana after remove: " << (counts.get("banana", value) ? "found" : "not found") << endl;

    // The bucket count doubles whenever entries outnumber buckets.
    HashTable ids(2);
    cout << "\nStart: " << ids.bucketCount() << " buckets" << endl;
    for (int i = 1; i <= 20; i++)
    {
        int bucketsBefore = ids.bucketCount();
        ids.put("user" + to_string(i), i);
        if (ids.bucketCount() != bucketsBefore)
            cout << "Entry " << i << " made it grow to " << ids.bucketCount() << " buckets" << endl;
    }

    return 0;
}
