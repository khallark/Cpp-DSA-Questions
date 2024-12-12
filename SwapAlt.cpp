#include <iostream>
using namespace std;

void swapAlt(int *arr, int size) {
    for (int i = 0; i < size; i++)
    {
        if(i != size - 1) {
            swap(arr[i], arr[i + 1]);
            i++;
        }
    }
}

int main()
{
    int arr[] = {2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(int);
    swapAlt(arr, size);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}