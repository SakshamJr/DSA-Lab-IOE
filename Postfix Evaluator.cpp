#include <iostream>
#include <cmath>
#include <stack>

using namespace std;

float evaluate(string postfix)
{
    stack<float> st;

    for (char ch : postfix)
    {
        if (ch >= '0' && ch <= '9')
            st.push(ch - '0');
        else
        {
            float b = st.top();
            st.pop();

            float a = st.top();
            st.pop();

            if (ch == '^')
                st.push(pow(a, b));
            else if (ch == '/')
                st.push(a / b);
            else if (ch == '*')
                st.push(a * b);
            else if (ch == '+')
                st.push(a + b);
            else if (ch == '-')
                st.push(a - b);
        }
    }
    return st.top();
}

int main()
{
    cout << evaluate("137*+24/+9+") << '\n';
    cout << evaluate("52^3+") << '\n';

    return 0;
}