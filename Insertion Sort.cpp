#include <iostream>

using namespace std;

void insertion_sort(int a[], int n)
{
    int i, j, temp;
    for (i = 1; i < n; i++)
    {
        temp = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > temp)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
}
int main()
{
    system("cls");
    int a[] = {4, 2, 9, 8, 5, 6, 3, 7, 1};
    int n = sizeof(a) / sizeof(a[0]);
    for (int i : a)
    {
        cout << i << " ";
    }
    insertion_sort(a, n);
    cout << endl;
    for (int i : a)
    {
        cout << i << " ";
    }
    return 0;
}