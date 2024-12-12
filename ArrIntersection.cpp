#include <iostream>
using namespace std;

int *arrIntersection(int *arr1, int size1, int *arr2, int size2, int *returnSize) {
    int *retArr = (int *)malloc((size1 + size2) * sizeof(int));
    *returnSize = 0;
    int i = 0, j = 0;
    while(i < size1 && j < size2) {
        if(arr1[i] == arr2[j]) {
            retArr[*returnSize] = arr1[i];
            *returnSize = *returnSize + 1;
            i++, j++;
        }
        else if (arr1[i] > arr2[j]) {
            j++;
        }
        else {
            i++;
        }
    }
    return retArr;
}
int main() {
    int arr1[] = {1,1,2,3,4,4,5,6,7,7,7,8,9};
    int size1 = sizeof(arr1) / sizeof(int);
    int arr2[] = {1,2,2,3,3,4,5,5,6,7,7,8,9,9};  
    int size2 = sizeof(arr2) / sizeof(int);
    int returnSize = 0;
    int *intersction = arrIntersection(arr1, size1, arr2, size2, &returnSize);
    for (int i = 0; i < returnSize; i++)
    {
        cout << intersction[i] << " ";
    }
    return 0;
}