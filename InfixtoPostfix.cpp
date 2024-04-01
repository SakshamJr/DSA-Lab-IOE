#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string infixToPostPrefix(string infix, bool toPrefix = false)
{
    stack<char> s;
    string fix;
    if (toPrefix)
    {
        reverse(infix.begin(), infix.end());
    }
    
    for (char c : infix)
    {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            fix += c;
        }
        else if ((!toPrefix && c == '(') || (toPrefix && c == ')'))
        {
            s.push(c);
        }
        else if ((!toPrefix && c == ')') || (toPrefix && c == '('))
        {
            while (!toPrefix && !s.empty() && s.top() != '(' || toPrefix && !s.empty() && s.top() != ')')
            {
                fix += s.top();
                s.pop();
            }
            if (!toPrefix && !s.empty() && s.top() == '(' || toPrefix && !s.empty() && s.top() == ')')
                s.pop();
        }
        else
        {
            while (!s.empty() && precedence(c) <= precedence(s.top()))
            {
                fix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    while (!s.empty())
    {
        fix += s.top();
        s.pop();
    }
    if (toPrefix)
    {
        reverse(fix.begin(), fix.end());
    }
    return fix;
}

int main()
{
    string infix, postfix, prefix;
    cout << "Enter Infix Expression: ";
    cin >> infix;

    postfix = infixToPostPrefix(infix, false);
    cout << "Postfix Expression: " << postfix << endl;

    prefix = infixToPostPrefix(infix, true);
    cout << "Prefix Expression: " << prefix << endl;
    return 0;
}
