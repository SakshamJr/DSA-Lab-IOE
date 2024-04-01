#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isBalanced(string exp)
{
    stack<char> st;
    for (char br : exp)
    {
        if (br == '(' || br == '{' || br == '[')
        {
            st.push(br);
        }
        else if (br == ')' || br == '}' || br == ']')
        {
            if (st.empty())
            {
                return false;
            }
            else if ((br == ')' && st.top() != '(') ||
                     (br == '}' && st.top() != '{') ||
                     (br == ']' && st.top() != '['))
            {
                return false;
            }
            st.pop();
        }
    }
    return st.empty(); // If stack is empty, all parentheses are balanced
}

int main()
{
    string exp;
    cout << "Enter an exp with parentheses: ";
    cin >> exp;

    if (isBalanced(exp))
    {
        cout << "Parentheses are balanced!\n";
    }
    else
    {
        cout << "Parentheses are not balanced!\n";
    }

    return 0;
}
