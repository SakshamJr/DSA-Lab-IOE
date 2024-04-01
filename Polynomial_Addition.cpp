#include <iostream>

using namespace std;

struct Node
{
    int coeff, exp;
    Node *next = nullptr;
};

int main()
{
    system("cls");
    Node *p1 = NULL, *p2 = NULL, *p = NULL;
    int n1, n2;
    cout << "Enter the number of terms in the first polynomial: ";
    cin >> n1;

    cout << "Enter the number of terms in the second polynomial: ";
    cin >> n2;

    cout << "\nEnter coefficient and exponent of each term of first polynomial:\n";
    for (int i = 0; i < n1; i++)
    {
        int coeff, exp;
        cin >> coeff >> exp;
        Node *temp = new Node{coeff, exp};
        temp->next = p1;
        p1 = temp; // p1 bhaneko polynomial 1 ko head
    }

    cout << "\nEnter coefficient and exponent of each term of second polynomial:\n";
    for (int i = 0; i < n2; i++)
    {
        int coeff, exp;
        cin >> coeff >> exp;
        Node *temp = new Node{coeff, exp};
        temp->next = p2;
        p2 = temp; // p2 = polynomial 2 ko head
    }
    while (p1 && p2)
    {
        if (p1->exp == p2->exp)
        {
            Node *temp = new Node{p1->coeff + p2->coeff, p1->exp};
            temp->next = p;
            p = temp; // p = result polynomial ko head
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->exp > p2->exp)
        {
            Node *temp = new Node{p1->coeff, p1->exp};
            temp->next = p;
            p = temp;
            p1 = p1->next;
        }
        else if (p1->exp < p2->exp)
        {
            Node *temp = new Node{p2->coeff, p2->exp};
            temp->next = p;
            p = temp;
            p2 = p2->next;
        }
    }
    while (p1)
    {
        Node *temp = new Node{p1->coeff, p1->exp};
        temp->next = p;
        p = temp;
        p1 = p1->next;
    }
    while (p2)
    {
        Node *temp = new Node{p2->coeff, p2->exp};
        temp->next = p;
        p = temp;
        p2 = p2->next;
    }
    cout << "The Added Polynomial is:\n";
    while (p != NULL)
    {
        cout << p->coeff << "x^" << p->exp << " + ";
        p = p->next;
    }
    return 0;
}