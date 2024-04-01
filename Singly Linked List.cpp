#include <iostream>

using namespace std;

class node
{
public:
    int data;
    node *next;

    // Construct a new Node
    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertAtTail(node *&head, int val)
{
    // Insert garna lai new Node banako
    node *n = new node(val);

    if (head == NULL)
    { // List ma kei xadai xaina bhane
        head = n;
        cout << "Linked List Initialized! \n";
        cout << "Added " << val << " to the Tail of Linked List!\n";
        return;
    }

    // Start to end samma traverse garna lai banako
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    // Loop bata bahira aauda samma last element ma aaisakeko xa sure
    temp->next = n;
    cout << "Added " << val << " to the Tail of Linked List!\n";
}

void insertAtHead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    head = n;
    cout << "Added " << val << " to the Head of Linked List!\n";
}

void displayLinkedList(node *head)
{
    node *temp = head;
    cout << "\nThe contents of the Linked List Are: \n";
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void insertAfterN(node *&head, int val, int index)
{
    int count = 0;
    node *n = new node(val);
    node *temp = head;

    while (count != index && temp != NULL)
    {
        temp = temp->next;
        count++;
    }

    if (temp == NULL && count != index)
    {
        cout << "Index out of range! \n";
        delete n; // Clean up the newly created node
        return;
    }
    n->next = temp->next;
    temp->next = n;
    cout << val << " inserted after index " << index << endl;
}

void insertBeforeN(node *&head, int val, int index)
{
    int count = 1;
    // Insert garni node
    node *n = new node(val);
    // Traverse garni temporary pointer
    node *temp = head;
    while (count != index && temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    // Bahira niskida samma temp pointer index ko location ma aaisakxa
    if (temp == NULL)
    {
        cout << "Index out of range! \n";
        delete n;
        return;
    }
    n->next = temp->next;
    temp->next = n;
    cout << val << " inserted before index " << index << endl;
}

void deleteFromHead(node *&head)
{
    if (head)
    {
        node *temp = head;
        head = head->next; // Move head to the next node
        delete temp;       // Deallocate memory of the previous head
    }
}

void deleteFromTail(node *&head)
{
    node *temp = head;
    node *ntemp; // END ko agadi ko address hold garna lai
    while (temp->next != NULL)
    {
        ntemp = temp;
        temp = temp->next;
    }
    ntemp->next = NULL;
    temp = ntemp;
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
    node *ntemp = temp;
    temp = (temp->next)->next;
    ntemp->next = temp;
}

int main()
{
    system("cls");
    node *head = NULL;
    int choice, value, index;
    cout << "1. INSERT NODE AT BEGINNING OF THE LIST\n"
         << "2. INSERT NODE AT END OF THE LIST\n"
         << "3. INSERT NODE AFTER SPECIFIC NODE\n"
         << "4. INSERT NODE BEFORE SPECIFIC NODE\n"
         << "5. DELETE NODE FROM BEGINNING OF THE LIST\n"
         << "6. DELETE NODE FROM END OF THE LIST\n"
         << "7. DELETE NODE AFTER SPECIFIC NODE\n"
         << "8. DISPLAY THE LINKED LIST\n"
         << "ENTER 0 TO QUIT\n";
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
            displayLinkedList(head);
            break;

        default:
            cout << "Enter Valid Choice! " << endl;
            break;
        }
    } while (choice != 0);

    return 0;
}