#include <iostream>
using namespace std;
/*
FIND THE FACTORIAL FOR GIVEN NUMBER ‘N’.
FIND THE FIBONACCI NUMBER FOR GIVEN TERM ‘N’.
SOLVE ABOVE QUESTIONS USING TAIL RECURSION.
SOLVE TOWER OF HANOI PROBLEM FOR ‘N’ DISCS.
*/

long factorialNonTail(long n)
{
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorialNonTail(n - 1);
}

long factorialTail(long n, long result = 1)
{
    if (n == 0 || n == 1)
        return result;
    else
        return factorialTail(n - 1, result * n);
}

long fibonacciNonTail(long n)
{
    if (n == 1)
        return 0;
    else if (n == 2)
        return 1;
    else
        return fibonacciNonTail(n - 1) + fibonacciNonTail(n - 2);
}

long fibonacciTail(long n, long a = 0, long b = 1)
{
    if (n == 1)
        return a;
    else if (n == 2)
        return b;
    else
        return fibonacciTail(n - 1, b, a + b);
}

void TOH(int n, char A, char B, char C) // source, auxiliary, destination
{
    if (n == 1)
    {
        cout << A << " to " << C << endl;
        return;
    }
    TOH(n - 1, A, C, B);
    cout << A << " to " << C << endl;
    TOH(n - 1, B, A, C);
}

void displayMenu()
{
    cout << "1. Factorial of Number Using Non Tail Rcursion\n"
         << "2. Factorial of a Number Using Tail Recursion\n"
         << "3. Find nth Fibonacci Number using Non Tail Recursion\n"
         << "4. Find nth Fibonacci Number using Tail Recursion\n"
         << "5. Tower of Hanoi Solver\n"
         << "Enter 0 to exit\n\n";
}
int main()
{
    system("cls");
    long choice, n;
    cout << "Recursion MultiTools By SakshamJr!\n";
    cout << "----------------------------------\n\n";
    do
    {
        displayMenu();
        cout << "Enter the Tool You Want to Use: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            system("cls");
            cout << "Enter the Number: ";
            cin >> n;
            cout << "Factorial = " << factorialNonTail(n) << endl;
            break;
        case 2:
            system("cls");
            cout << "Enter the Number: ";
            cin >> n;
            cout << "Factorial = " << factorialTail(n) << endl;
            break;
        case 3:
            system("cls");
            cout << "Enter n: ";
            cin >> n;
            if (n == 1)
                cout << "1st Fibonacci Number = 0";
            else if (n == 0)
                cout << "0th Fibonacci Number Doesnt Exist!\n";
            else
                cout << n << "th Fibonacci Number = " << fibonacciNonTail(n) << endl;
            break;
        case 4:
            system("cls");
            cout << "Enter n: ";
            cin >> n;
            if (n == 1)
                cout << "1st Fibonacci Number = 0";
            else if (n == 0)
                cout << "0th Fibonacci Number Doesnt Exist!\n";
            else
                cout << n << "th Fibonacci Number = " << fibonacciTail(n) << endl;
            break;
        case 5:
            system("cls");
            cout << "Enter Number of Disc in Tower of Hanoi: ";
            cin >> n;
            cout << "The Tower of Hanoi of " << n << " discs can be solved by moving: \n";
            TOH(n, 'A', 'B', 'C');
            cout << "One Disc at a time!\n";
            break;
        case 0:
            cout << "Thanks For Using Recursion Multitools by SakshamJr!\n";
            break;
        default:
            cout << "Enter Valid Choice!\n";
            break;
        }
        cout << endl;
    } while (choice != 0);
    return 0;
}