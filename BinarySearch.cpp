#include <iostream>
#include <array>
using namespace std;
int binarySearch(int a[], int n, int key)
{
    int s = 0, mid;
    int e = n;
    mid = (s + e) / 2;
    while (s <= e)
    {
        mid = (s + e) / 2;
        if (a[mid] == key)
        {
            return mid;
        }
        else if (a[mid] > key)
        {
            e = mid - 1;
        }
        else
            s = mid + 1;
    }
    return e;
}

int binarySearchRecursive(int a[], int key, int start, int end)
{
    int mid = (start + end) / 2;
    if (a[mid] == key)
    {
        return mid;
    }
    else if (a[mid] > key)
    {
        return binarySearchRecursive(a, key, start, mid - 1);
    }
    else
        return binarySearchRecursive(a, key, mid + 1, end);
}
int main()
{
    system("cls");
    int key;
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int n = sizeof(a) / sizeof(a[0]);
    cout << "Enter Key: ";
    cin >> key;
    cout << key << " is at index " << binarySearch(a, n, key) << endl;
    cout << key << " is at index " << binarySearchRecursive(a, key, 0, n) << endl;
    return 0;
}