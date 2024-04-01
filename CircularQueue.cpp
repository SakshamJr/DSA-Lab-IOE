#include <iostream>
#define MAX 3
using namespace std;

template <class T>
class Queue
{
private:
    int front, rear;
    T q[MAX];

public:
    Queue() // Initialize Queue
    {
        front = -1;
        rear = -1;
    }

    // Enqueue Elements
    void enqueue(T x)
    {
        if (front == -1 && rear == -1) // Empty Queue
        {
            front = rear = 0;
            q[rear] = x;
            cout << x << " Enqueued!" << endl;
        }
        else if (front == ((rear + 1) % MAX)) // Full Queue
        {
            cout << "Queue is Full! Cannot Enqueue " << x << endl;
        }
        else // Normal Case
        {
            rear = ((rear + 1) % MAX);
            q[rear] = x;
            cout << x << " Enqueued!" << endl;
        }
    }

    // Dequeue Elements
    void dequeue()
    {
        if (front == -1 && rear == -1) // Empty Queue
        {
            cout << "Queue is Empty! Nothing to Dequeue!" << endl;
        }
        else if (rear == front) // One Element Left
        {
            cout << q[front] << " Dequeued!" << endl;
            front = rear = -1;
        }
        else
        {
            cout << q[front] << " Dequeued!" << endl;
            front = (front + 1) % MAX;
        }
    }

    // Peek Front Element
    T peek()
    {
        if (front != -1)
            return q[front];
        else
        {
            cout << "Nothing at the Front!" << endl;
        }
    }
};

int main()
{
    system("cls");
    Queue<int> q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.dequeue();
    q.dequeue();
    q.enqueue(5);
    cout << "Element at front right now is:" << q.peek() << endl;
    return 0;
}