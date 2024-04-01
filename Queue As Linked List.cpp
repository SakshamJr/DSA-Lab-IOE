#include <iostream>

using namespace std;

class Queue
{
    struct node
    {
        int data;
        node *next;
    };
    node *front = NULL, *rear = NULL;

public:
    void enqueue(int val)
    {
        node *n = new node{val};
        if (!front && !rear)
        {
            front = rear = n;
        }
        else
        {
            rear->next = n;
            rear = n;
        }
        cout << val << " enqueued!\n";
    }

    void dequeue()
    {
        if (!front)
        {
            cout << "Empty Queue!\n";
        }
        else
        {
            cout << front->data << " dequeued!\n";
            front = front->next;
        }
    }
};

int main()
{
    system("cls");
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();


    return 0;
}