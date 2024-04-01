#include <iostream>
#define SIZE 3 // Change the size of the queue here
using namespace std;

template <class T>
class Queue {
private:
    T items[SIZE];
    int front, rear;
public:
    Queue() {
        front = -1;
        rear = -1;
    }

    void enqueue(T element) {
        if (rear == SIZE - 1) {
            cout << "Queue is full! Cannot Enqueue " << element << endl;
        } else {
            if (front == -1)
                front = 0;
            rear++;
            items[rear] = element;
            cout << "Enqueued " << element << endl;
        }
    }

    T peek() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty!" << endl;
        } else {
            return items[front];
        }
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty!" << endl;
        } else {
            T element = items[front];
            front++;
            cout << "Dequeued " << element << endl;

            if (front > rear) {
                front = -1;
                rear = -1;
            }
        }
    }
};

int main() {
    Queue<int> q;  
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.dequeue();
    q.dequeue();
    q.enqueue(5);
    cout << "Element at front right now is: " << q.peek() << endl;
    return 0;
}
