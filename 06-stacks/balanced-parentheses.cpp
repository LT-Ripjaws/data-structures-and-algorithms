// Check whether (), [] and {} are balanced using a stack.
// Push every opening bracket; on a closing bracket the top of the stack must
// be the matching opener. The string is balanced if the stack ends empty. O(n).
#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isMatchingPair(char open, char close)
{
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

bool isBalanced(const string &expr)
{
    stack<char> st;
    for (char c : expr)
    {
        if (c == '(' || c == '[' || c == '{')
        {
            st.push(c);
        }
        else if (c == ')' || c == ']' || c == '}')
        {
            if (st.empty())
                return false;
            char open = st.top();
            st.pop();
            if (!isMatchingPair(open, c))
                return false;
        }
    }
    return st.empty();
}

int main()
{
    string tests[] = {"{[()]}", "(a + b) * [c - d]", "([)]", "((()", "())", ""};

    for (const string &t : tests)
        cout << "\"" << t << "\": " << (isBalanced(t) ? "balanced" : "not balanced") << endl;

    return 0;
}
