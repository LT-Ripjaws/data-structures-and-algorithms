// Tower of Hanoi: move n disks from one rod to another using a helper rod,
// never placing a larger disk on a smaller one.
// Move n-1 disks out of the way, move the largest, then move the n-1 back on
// top. Takes 2^n - 1 moves, so O(2^n) time and O(n) recursion depth.
#include <iostream>
using namespace std;

int moves = 0;

void hanoi(int n, char from, char to, char via)
{
    if (n == 0)
        return;
    hanoi(n - 1, from, via, to);
    cout << "Move disk " << n << " from " << from << " to " << to << endl;
    moves++;
    hanoi(n - 1, via, to, from);
}

int main()
{
    int disks = 3;
    hanoi(disks, 'A', 'C', 'B');
    cout << "Total moves: " << moves << endl;
    return 0;
}
