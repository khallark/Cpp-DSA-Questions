#include <stdio.h>
#include <stdlib.h>
int *twoSum(int *numbers, int numbersSize, int target, int *returnSize)
{
    *returnSize = 2;
    int *retArr = (int *)malloc(2 * sizeof(int));
    int left = 0, right = numbersSize - 1;
    while(numbers[left] + numbers[right] != target) {
        if (numbers[left] + numbers[right] > target) {
            right--;
        }
        else if (numbers[left] + numbers[right] < target) {
            left++;
        }
    }
    retArr[0] = left + 1;
    retArr[1] = right + 1;
    return retArr;
}
int main()
{
    int arr[] = {-1, 0};
    int size = sizeof(arr) / sizeof(int);
    int returnSize = 0;
    int *retArr = twoSum(arr, size, -1, &returnSize);
    for (int i = 0; i < returnSize; i++)
    {
        printf("%d ", retArr[i]);
    }
    return 0;
}