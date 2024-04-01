#include <iostream>
using namespace std;

const int MAX_SIZE = 10;

class List
{
private:
    int data[MAX_SIZE];
    int size;

public:
    List()
    {
        size = 0;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    bool isFull()
    {
        return size == MAX_SIZE;
    }

    void insertAtFront(int value)
    {
        if (!isFull())
        {
            for (int i = size; i > 0; --i)
            {
                data[i] = data[i - 1];
            }
            data[0] = value;
            size++;
            cout << "Inserted " << value << " at the front.\n";
        }
        else
        {
            cout << "List is full. Cannot insert at the front.\n";
        }
    }

    void insertAtEnd(int value)
    {
        if (!isFull())
        {
            data[size] = value;
            size++;
            cout << "Inserted " << value << " at the end.\n";
        }
        else
        {
            cout << "List is full. Cannot insert at the end.\n";
        }
    }

    void deleteFront()
    {
        if (!isEmpty())
        {
            cout << "Deleted " << data[0] << " from the front.\n";
            for (int i = 0; i < size - 1; ++i)
            {
                data[i] = data[i + 1];
            }
            size--;
        }
        else
        {
            cout << "List is empty. Cannot delete from the front.\n";
        }
    }

    void deleteRear()
    {
        if (!isEmpty())
        {
            cout << "Deleted " << data[size - 1] << " from the rear.\n";
            size--;
        }
        else
        {
            cout << "List is empty. Cannot delete from the rear.\n";
        }
    }

    void insertAtIndex(int index, int value)
    {
        if (index >= 0 && index <= size && !isFull())
        {
            for (int i = size; i > index; --i)
            {
                data[i] = data[i - 1];
            }
            data[index] = value;
            size++;
            cout << "Inserted " << value << " at index " << index << ".\n";
        }
        else
        {
            cout << "Invalid index or list is full. Cannot insert at index " << index << ".\n";
        }
    }

    void deleteAtIndex(int index)
    {
        if (index >= 0 && index < size)
        {
            cout << "Deleted " << data[index] << " at index " << index << ".\n";
            for (int i = index; i < size - 1; ++i)
            {
                data[i] = data[i + 1];
            }
            size--;
        }
        else
        {
            cout << "Invalid index. Cannot delete from index " << index << ".\n";
        }
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "List is empty.\n";
            return;
        }
        cout << "List contents: ";
        for (int i = 0; i < size; ++i)
        {
            cout << data[i] << " ";
        }
        cout << "\n";
    }

    void deleteBefore(int val)
    {
        int count = 0;
        while (data[count] != val && count <= MAX_SIZE)
        {
            count++;
        }
        if (count >= MAX_SIZE)
        {
            cout << "Value Not Found!\n";
            return;
        }
        cout << "Deleted data before " << val << endl;
        // loop bata niskida samma count ko value tyo index ma hunxa jasko before ko element lai hataune ho
        // aba before lai hatayera shift garna paryo
        for (int i = count; i < size; i++)
        {
            data[i - 1] = data[i];
        }
        size--;
    }
};

int main()
{
    List list;

    list.insertAtEnd(5);
    list.insertAtEnd(10);
    list.insertAtEnd(4);
    list.insertAtEnd(3);
    list.insertAtEnd(2);
    list.insertAtEnd(15);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(45);
    list.insertAtEnd(70);
    list.display();
    list.insertAtFront(25);
    list.insertAtIndex(2, 12);
    list.display();
    // list.deleteFront();
    // list.deleteRear();
    list.deleteAtIndex(2);
    list.display();
    list.deleteBefore(15);
    list.display();

    return 0;
}
