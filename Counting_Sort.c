#include <stdio.h>
#include <stdlib.h>
int *countingSort(int *arr, int size) {
    int max = arr[0];
    int *retArr = (int *)calloc(size, sizeof(int));
    int i = 0;
    for (i = 0; i < size; i++) {
        max = arr[i] > max ? arr[i] : max;
    }
    int *temp = (int *)calloc((max + 1), sizeof(int));
    for (i = 0; i < size; i++) {
        temp[arr[i]]++;
    }
    int sum = 0;
    for (i = 0; i < max + 1; i++) {
        sum += temp[i];
        temp[i] = sum;
    }
    for (i = size - 1; i >= 0; i--) {
        retArr[temp[arr[i]] - 1] = arr[i];
        temp[arr[i]]--;
    }
    return retArr;
}
int main() {
    int arr[] = {2,4,7,87,5,22,45,67,98,986,43,34,5678,9};
    int size = sizeof(arr) / sizeof(int);
    int *arr2 = countingSort(arr, size);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr2[i]);
    }
    return 0;
}