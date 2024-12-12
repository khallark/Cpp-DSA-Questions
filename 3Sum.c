#include <stdio.h>
#include <stdlib.h>
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int maxTriplets = (numsSize * (numsSize - 1) * (numsSize - 2)) / (3 * 2);
    int **retArr = (int **)malloc(maxTriplets * sizeof(int *));
    *returnColumnSizes = (int *)malloc(maxTriplets * sizeof(int));
    *returnSize = 0;
    qsort(nums, numsSize, sizeof(nums[0]), compare);
    int num1 = 0, num2 = 0;
    for(int i = 0; i < numsSize - 2; i++) {
        if(i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        num1 = nums[i];
        int j = i + 1;
        num2 = nums[j];
        while(j < numsSize - 1) {
            int ans = 0 - (num1 + num2);
            if(j > i + 1 && nums[j] == nums[j - 1] || ans > nums[numsSize - 1]) {
                j++;
                num2 = nums[j];
                continue;
            }
            int s = j + 1;
            int e = numsSize - 1;
            int mid = s + (e - s) / 2;
            while(s <= e) {
                if(nums[mid] == ans) {
                    (*returnColumnSizes)[*returnSize] = 3;
                    retArr[*returnSize] = (int *)malloc(3 * sizeof(int));
                    retArr[*returnSize][0] = num1;
                    retArr[*returnSize][1] = num2;
                    retArr[*returnSize][2] = ans;
                    *returnSize = *returnSize + 1;
                    break;
                }
                else if(nums[mid] < ans) {
                    s = mid + 1;
                }
                else {
                    e = mid - 1;
                }
                mid = s + (e - s) / 2;
            }
            j++;
            num2 = nums[j];
        }
    }
    return retArr;
}

int main() {
    int nums[] = {-7,-4,-6,6,4,-6,-9,-10,-7,5,3,-1,-5,8,-1,-2,-8,-1,5,-3,-5,4,2,-5,-4,4,7};
    int numsSize = sizeof(nums) / sizeof(int);
    int returnSize = 0;
    int *returnColumnSizes = NULL;
    int **arr = threeSum(nums, numsSize, &returnSize, &returnColumnSizes);
    for (int i = 0; i < returnSize; i++)
    {
        printf("[");
        for (int j = 0; j < returnColumnSizes[i]; j++)
        {
            if(j < returnColumnSizes[i] - 1) printf("%d,", arr[i][j]);
            else printf("%d", arr[i][j]);
        }
        if(i < returnSize - 1) printf("],");
        else printf("]");
    }
    return 0;
}
