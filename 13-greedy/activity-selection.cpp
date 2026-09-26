// Activity selection (greedy): choose the largest number of activities that
// do not overlap. Sort by finish time and always pick the activity that
// finishes first among those that start after the last chosen one ends.
// O(n log n) for the sort.
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Activity
{
    char name;
    int start;
    int finish;
};

bool compareByFinish(const Activity &a, const Activity &b)
{
    return a.finish < b.finish;
}

int main()
{
    vector<Activity> activities = {
        {'A', 1, 4}, {'B', 3, 5}, {'C', 0, 6}, {'D', 5, 7}, {'E', 3, 9},
        {'F', 5, 9}, {'G', 6, 10}, {'H', 8, 11}, {'I', 8, 12}, {'J', 2, 14},
    };

    sort(activities.begin(), activities.end(), compareByFinish);

    int lastFinish = -1;
    int count = 0;
    cout << "Selected: ";
    for (const Activity &a : activities)
    {
        if (a.start >= lastFinish)
        {
            cout << a.name << "(" << a.start << "-" << a.finish << ") ";
            lastFinish = a.finish;
            count++;
        }
    }
    cout << "\nTotal activities: " << count << endl;

    return 0;
}
