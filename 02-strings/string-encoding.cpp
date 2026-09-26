// Encode a string by shifting every (step + 1)-th character forward by 2,
// starting at index `step`. Example: step 1 shifts indexes 1, 3, 5, ... O(n).
#include <iostream>
#include <string>
using namespace std;

string encode(string s, int step)
{
    for (size_t i = step; i < s.length(); i += step + 1)
        s[i] += 2;
    return s;
}

int main()
{
    string input = "abcdefgh";

    for (int step = 0; step <= 3; step++)
        cout << "step " << step << ": " << encode(input, step) << endl;

    return 0;
}
