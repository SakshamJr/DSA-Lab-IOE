#include <iostream>
#define MAX 3 // Change the MAX of the deque here
using namespace std;

template <class T>
class Deque {
private:
    T dq[MAX];
    int f, r;

public:
    Deque() {
        f = -1;
        r = -1;
    }

    bool isFull() {
        return (f == 0 && r == MAX - 1) || (f == r + 1);
    }

    bool isEmpty() {
        return f == -1;
    }

    void insertf(T x) {
        if (isFull()) {
            cout << "Deque is full! Cannot insert at f " << x << endl;
        } else {
            if (f == -1) {
                f = 0;
                r = 0;
            } else if (f == 0) {
                f = MAX - 1;
            } else {
                f--;
            }
            dq[f] = x;
            cout << x << " inserted at f" << endl;
        }
    }

    void insertr(T x) {
        if (isFull()) {
            cout << "Deque is full! Cannot insert at r " << x << endl;
        } else {
            if (f == -1) {
                f = 0;
                r = 0;
            } else if (r == MAX - 1) {
                r = 0;
            } else {
                r++;
            }
            dq[r] = x;
            cout << x << " inserted at r" << endl;
        }
    }

    void deletef() {
        if (isEmpty()) {
            cout << "Deque is empty! Cannot delete from f" << endl;
        } else {
            cout <<dq[f] << " deleted from f" << endl;
            if (f == r) {
                f = -1;
                r = -1;
            } else if (f == MAX - 1) {
                f = 0;
            } else {
                f++;
            }
        }
    }

    void deleter() {
        if (isEmpty()) {
            cout << "Deque is empty! Cannot delete from r" << endl;
        } else {
            cout << dq[r] << " deleted from r" << endl;
            if (f == r) {
                f = -1;
                r = -1;
            } else if (r == 0) {
                r = MAX - 1;
            } else {
                r--;
            }
        }
    }
};

int main() {
    Deque<int> dq;
    dq.insertf(1);
    dq.insertr(2);
    dq.insertf(3);
    dq.insertr(4);
    dq.deletef();
    dq.deleter();
    dq.insertf(5);
    return 0;
}
