// Reverse a string with two pointers and check whether it is a palindrome.
// Both are O(n) time and O(1) extra space.
#include <iostream>
#include <string>
using namespace std;

void reverseInPlace(string &s)
{
    int left = 0;
    int right = (int)s.length() - 1;
    while (left < right)
        swap(s[left++], s[right--]);
}

bool isPalindrome(const string &s)
{
    int left = 0;
    int right = (int)s.length() - 1;
    while (left < right)
    {
        if (s[left] != s[right])
            return false;
        left++;
        right--;
    }
    return true;
}

int main()
{
    string words[] = {"racecar", "level", "hello", "a", ""};

    for (string word : words)
    {
        string reversed = word;
        reverseInPlace(reversed);
        cout << "\"" << word << "\" reversed is \"" << reversed << "\", "
             << (isPalindrome(word) ? "palindrome" : "not a palindrome") << endl;
    }

    return 0;
}
