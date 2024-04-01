#include <iostream>

using namespace std;

void selection_sort(int a[], int n)
{
    int min, i, j;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[min] > a[j])
            {
                min = j;
            }
        }
        cout << min << " " << i << endl;
        int temp = a[min];
        a[min] = a[i];
        a[i] = temp;
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
    cout << endl;
    selection_sort(a, n);
    cout << endl;
    for (int i : a)
    {
        cout << i << " ";
    }
    return 0;
}