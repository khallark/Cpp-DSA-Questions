#include <iostream>
#include <vector>
using namespace std;

int *findDuplicates(int *nums, int numsSize, int *returnSize)
{
    *returnSize = 0;
    int *retArr = (int *)malloc((numsSize / 2) * sizeof(int));
    int retIndx = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[abs(nums[i]) - 1] < 0)
        {
            retArr[retIndx++] = abs(nums[i]);
            *returnSize++;
            continue;
        }
        nums[abs(nums[i]) - 1] -= 2 * nums[abs(nums[i]) - 1];
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
        cout << arr2[i] << " ";
    }
    return 0;
}