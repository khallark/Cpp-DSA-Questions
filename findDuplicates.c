#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int *findDuplicates(int *nums, int numsSize, int *returnSize)
{
    *returnSize = 0;
    int *retArr = (int *)malloc((numsSize / 2) * sizeof(int));
    int absolute = 0;
    for (int i = 0; i < numsSize; i++)
    {
        absolute = fabs(nums[i]);
        if (nums[absolute - 1] < 0)
        {
            retArr[*returnSize] = absolute;
            *returnSize = *returnSize + 1;
            continue;
        }
        nums[absolute - 1] -= 2 * nums[absolute - 1];
    }
    return retArr;
}

int main()
{
    int arr[] = {4, 3, 2, 7, 8, 2, 3, 1};
    int size = sizeof(arr) / sizeof(int);
    int returnSize = 0;
    int *arr2 = findDuplicates(arr, size, &returnSize);
    for (int i = 0; i < returnSize; i++)
    {
        printf("%d ", arr2[i]);
    }
    return 0;
}