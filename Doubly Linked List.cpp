#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;

    node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

void insertAtHead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    if (head != NULL)
        head->prev = n;
    head = n;
    cout << "Added " << val << " to the Head of Linked List!\n";
}

void insertAtTail(node *&head, int val)
{
    if (head == NULL)
    {
        cout << "Linked List Initialized! \n";
        insertAtHead(head, val);
        return;
    }
    node *n = new node(val);
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
    cout << "Added " << val << " to the Tail of Linked List!\n";
}

void displayLinkedList(node *head)
{
    node *temp = head;
    cout << "\nThe contents of the Linked List Are: \n";
    while (temp != NULL)
    {
        cout << temp->data << " <--> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void insertAfterN(node *&head, int val, int index)
{
    int count = 0;
    node *temp = head;
    node *n = new node(val);
    while (temp->next != NULL && count != index)
    {
        temp = temp->next;
        count++;
    }
    if (temp->next == NULL && count != index)
    {
        cout << "Index out of Bound!\n";
        delete n;
        return;
    }
    temp->next->prev = n;
    n->next = temp->next;
    temp->next = n;
    n->prev = temp;
    cout << val << " inserted after index " << index << endl;
}

void insertBeforeN(node *&head, int val, int index)
{
    int count = 0;
    node *temp = head;
    node *n = new node(val);
    while (temp != NULL && count != index)
    {
        ++count;
        temp = temp->next;
    }
    if (temp == NULL && count != index)
    {
        cout << "Index out of Bound!\n";
        delete n;
        return;
    }
    temp->prev->next = n;
    n->prev = temp->prev;
    n->next = temp;
    temp->prev = n;
    cout << val << " inserted before index " << index << endl;
}

void deleteFromHead(node *&head)
{
    if (head)
    {
        node *temp = head;
        cout << "Deleted " << temp->data << " from Head!\n";
        head = head->next;
        head->prev = NULL;
        delete temp;
    }
    else
        cout << "List is Empty!\n";
}

void deleteFromTail(node *&head)
{
    if (!head)
        cout << "List is Empty!\n";
    else
    {
        node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        cout << "Deleted " << temp->data << " from Tail!\n";
        temp->prev->next = NULL;
        delete temp;
    }
}

void deleteAfter(node *&head, int val)
{
    // traverse garna lai
    node *temp = head;
    while (temp->data != val && temp != NULL)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        cout << "Node not Found!\n";
        return;
    }
    // bahira niskida samma tyo element ma aaisakeko hunxa jasko AFTER ko element lai hataune ho
    if (temp->next != NULL)
    {
        if (temp->next->next == NULL)
        {
            deleteFromTail(head);
            return;
        }
        cout << temp->next->data << " deleted!\n";
        temp->next->next->prev = temp;
        temp->next = temp->next->next;
    }
    else
    {
        cout << "No Element after " << temp->data << endl;
    }
}

void deleteBefore(node *&head, int val)
{
    // traverse garna lai
    node *temp = head;
    while (temp->data != val && temp != NULL)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        cout << "Node not Found!\n";
        return;
    }
    // bahira niskida samma tyo element ma aaisakeko hunxa jasko BEFORE ko element lai hataune ho
    if (temp->prev != NULL)
    {
        if (temp->prev->prev == NULL)
        {
            deleteFromHead(head);
            return;
        }
        cout << temp->prev->data << " deleted!\n";
        temp->prev->prev->next = temp;
        temp->prev = temp->prev->prev;
    }
    else
    {
        cout << "No Element Before " << temp->data << endl;
    }
}

void displayMenu()
{
    cout << "1. INSERT NODE AT BEGINNING OF THE LIST\n"
         << "2. INSERT NODE AT END OF THE LIST\n"
         << "3. INSERT NODE AFTER SPECIFIC NODE\n"
         << "4. INSERT NODE BEFORE SPECIFIC NODE\n"
         << "5. DELETE NODE FROM BEGINNING OF THE LIST\n"
         << "6. DELETE NODE FROM END OF THE LIST\n"
         << "7. DELETE NODE AFTER SPECIFIC NODE\n"
         << "8. DELETE NODE BEFORE SPECIFIC NODE\n"
         << "9. DISPLAY THE LINKED LIST\n"
         << "ENTER 0 TO QUIT\n";
}

int main()
{
    system("cls");
    node *head = NULL;
    int choice, value, index;
    displayMenu();
    do
    {
        cout << "Enter the operation you want to do: " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the Value that you want to insert at the beginning: ";
            cin >> value;
            insertAtHead(head, value);
            break;

        case 2:
            cout << "Enter the Value that you want to insert at the end: ";
            cin >> value;
            insertAtTail(head, value);
            break;

        case 3:
            cout << "Enter the Value that you want to insert after the node: ";
            cin >> value;
            cout << "Enter the index after which you want to insert the value: ";
            cin >> index;
            insertAfterN(head, value, index);
            break;

        case 4:
            cout << "Enter the Value that you want to insert before th node: ";
            cin >> value;
            cout << "Enter the index after which you want to insert the value: ";
            cin >> index;
            insertBeforeN(head, value, index);
            break;

        case 5:
            deleteFromHead(head);
            break;

        case 6:
            deleteFromTail(head);
            break;

        case 7:
            cout << "Enter the Value after which you want to delete the node: ";
            cin >> value;
            deleteAfter(head, value);
            break;

        case 8:
            cout << "Enter the Value before which you want to delete the node: ";
            cin >> value;
            deleteBefore(head, value);
            break;

        case 9:
            displayLinkedList(head);
            break;

        case 0:
            cout << "Thanks For Using Linked List Implementation by Saksham078BCT072 :) \n";
            break;

        default:
            cout << "Enter Valid Choice! " << endl;
            break;
        }
    } while (choice != 0);

    return 0;
}