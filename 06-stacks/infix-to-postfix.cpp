// Expression evaluation with stacks.
// 1. Convert infix (a + b * c) to postfix (a b c * +) with the shunting-yard
//    method: operands go straight to the output, operators wait on a stack
//    until an operator of lower precedence arrives.
// 2. Evaluate the postfix expression with a stack of numbers.
// Both steps are O(n). Operands are single digits to keep parsing simple,
// and the input is assumed to be a valid expression (no error checking).
#include <cctype>
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int precedence(char op)
{
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

// Should the operator on top of the stack be output before pushing `incoming`?
// Yes if it binds tighter. On a tie, yes for left-to-right operators
// (9 - 4 - 2 means (9 - 4) - 2), but no for ^, which groups right to left
// (2 ^ 3 ^ 2 means 2 ^ (3 ^ 2)).
bool popBefore(char top, char incoming)
{
    if (top == '(')
        return false;
    if (precedence(top) > precedence(incoming))
        return true;
    if (precedence(top) == precedence(incoming) && incoming != '^')
        return true;
    return false;
}

string infixToPostfix(const string &infix)
{
    string output;
    stack<char> ops;

    for (char c : infix)
    {
        if (c == ' ')
            continue;
        if (isdigit(c) || isalpha(c))
        {
            output += c;
        }
        else if (c == '(')
        {
            ops.push(c);
        }
        else if (c == ')')
        {
            while (!ops.empty() && ops.top() != '(')
            {
                output += ops.top();
                ops.pop();
            }
            if (!ops.empty())
                ops.pop(); // discard '('
        }
        else
        {
            while (!ops.empty() && popBefore(ops.top(), c))
            {
                output += ops.top();
                ops.pop();
            }
            ops.push(c);
        }
    }

    while (!ops.empty())
    {
        output += ops.top();
        ops.pop();
    }
    return output;
}

int power(int base, int exp)
{
    int result = 1;
    while (exp-- > 0)
        result *= base;
    return result;
}

int evaluatePostfix(const string &postfix)
{
    stack<int> values;
    for (char c : postfix)
    {
        if (isdigit(c))
        {
            values.push(c - '0');
            continue;
        }
        int right = values.top();
        values.pop();
        int left = values.top();
        values.pop();
        if (c == '+')
            values.push(left + right);
        else if (c == '-')
            values.push(left - right);
        else if (c == '*')
            values.push(left * right);
        else if (c == '/')
            values.push(left / right);
        else if (c == '^')
            values.push(power(left, right));
    }
    return values.top();
}

int main()
{
    string expressions[] = {"3 + 4 * 2", "(3 + 4) * 2", "2 ^ 3 ^ 2", "9 - 4 - 2", "(1 + 2) * (3 + 4) / 7"};

    for (const string &e : expressions)
    {
        string postfix = infixToPostfix(e);
        cout << e << "  ->  " << postfix << "  =  " << evaluatePostfix(postfix) << endl;
    }

    cout << "a + b * (c - d)  ->  " << infixToPostfix("a + b * (c - d)") << endl;

    return 0;
}
