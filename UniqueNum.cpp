#include <iostream>
using namespace std;

int findUnique(int *arr, int size)
{
    int a = 0;
    for (int i = 0; i < size; i++)
    {
        a ^= arr[i];
    }
    return a;
}

int main()
{
    int arr[] = {1, 2, 1, 2, 3, 3, 9, 4, 4, 5, 5, 6, 6};
    int size = sizeof(arr) / sizeof(int);
    int a = findUnique(arr, size);
    cout << a << endl;
    return 0;
}