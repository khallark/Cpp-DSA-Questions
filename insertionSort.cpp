#include <iostream>
using namespace std;
void insertionSort(int *arr, int size) {
    for (int i = 1; i < size; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (arr[j - 1] > arr[j]) {
                int temp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = temp;
                continue;
            }
            break;
        }
    }
}
int main() {
    int arr[] = {4, 1, 2, 3};
    int size = sizeof(arr) / sizeof(int);
    insertionSort(arr, size);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << ' ';
    }
    return 0;
}