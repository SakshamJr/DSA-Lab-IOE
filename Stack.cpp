#include <iostream>
#define MAX 5
using namespace std;

class Stack
{
private:
    int top;
    char elements[MAX];

public:
    Stack()
    {
        top = -1;
    }

    bool isEmpty()
    {
        return (top == -1);
    }

    bool isFull()
    {
        return (top == MAX - 1);
    }

    void push(char c)
    {
        if (!isFull())
        {
            top++;
            elements[top] = c;
            cout << c << " pushed to Stack!\n";
        }
        else
        {
            cout << "Stack is Full! Cannot Push " << c << " to the Stack!\n";
        }
    }

    void pop()
    {
        if (!isEmpty())
        {
            cout << elements[top] << " popped from Stack!\n";
            top--;
        }
        else
        {
            cout << "Stack is Empty! Cannot Pop!\n";
        }
    }

    char topElement()
    {
        return elements[top];
    }
};

int main()
{
    Stack myStack;
    string message = "PYTHON";

    for (char letter : message)
    {
        myStack.push(letter);
    }

    cout << "Top of Stack is " << myStack.topElement() << endl;

    while (!myStack.isEmpty())
    {
        myStack.pop();
    }
    myStack.pop();
    return 0;
}
