#include <iostream>
using namespace std;
void bubbleSort(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        int swapCount = 0;
        for (int j = 1; j < size - i; j++) {
            if (arr[j - 1] > arr[j]) {
                int temp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = temp;
                swapCount++;
            }
        }
        if (swapCount == 0) {
            break;
        }
    }
}
int main() {
    int arr[] = {-7,-4,-6,6,4,-6,-9,-10,-7,5,3,-1,-5,8,-1,-2,-8,-1,5,-3,-5,4,2,-5,-4,4,7};
    // int arr[] = {1,7,3,9,9,7,2,8,4,0,5};
    int size = sizeof(arr) / sizeof(int);
    bubbleSort(arr, size);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << ", ";
    }
    return 0;
}