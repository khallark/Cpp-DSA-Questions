#include <stdio.h>
#include <stdlib.h>
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int *retArr = (int *)malloc(2 * sizeof(int));
    *returnSize = 2;
    int start = 0;
    int end = numsSize - 1;
    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        if(nums[mid] == target) {
            int min = mid, max = mid;
            while(1) {
                if(min == 0 || nums[min - 1] != target) {
                    retArr[0] = min;
                    break;
                }
                min--;
            }
            while(1) {
                if(max == numsSize - 1 || nums[max + 1] != target) {
                    retArr[1] = max;
                    break;
                }
                max++;
            }
            return retArr;
        }
        else if (target > nums[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    retArr[0] = retArr[1] = -1;
    return retArr;
}
int main() {
    int arr[] = {5,7,7,8,8,10};
    int size = sizeof(arr) / sizeof(int);
    int returnSize = 0;
    int *retArr = searchRange(arr, size, 5, &returnSize);
    for (int i = 0; i < 2; i++)
    {
        printf("%d ", retArr[i]);
    }
    return 0;
}