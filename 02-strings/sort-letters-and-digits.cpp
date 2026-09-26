// For each word, sort its letters among the letter positions and its digits
// among the digit positions, leaving each character type where it was.
// Example: "d4c3b2a1" -> "a1b2c3d4". O(L^2) per word.
#include <cctype>
#include <iostream>
#include <string>
using namespace std;

string sortLettersAndDigits(string s)
{
    int len = s.length();

    for (int j = 0; j < len; ++j)
        for (int k = j + 1; k < len; ++k)
            if (isalpha(s[j]) && isalpha(s[k]) && s[j] > s[k])
                swap(s[j], s[k]);

    for (int j = 0; j < len; ++j)
        for (int k = j + 1; k < len; ++k)
            if (isdigit(s[j]) && isdigit(s[k]) && s[j] > s[k])
                swap(s[j], s[k]);

    return s;
}

int main()
{
    string words[] = {"d4c3b2a1", "zy91x", "hello42", "321cba"};

    for (const string &word : words)
        cout << word << " -> " << sortLettersAndDigits(word) << endl;

    return 0;
}
