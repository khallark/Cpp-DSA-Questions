#include <stdio.h>
#include <stdlib.h>
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}
int* findRightInterval(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize) {
    *returnSize = intervalsSize;
    int *tempArr = (int *)malloc(intervalsSize * sizeof(int));
    int *retArr = (int *)malloc(intervalsSize * sizeof(int));
    for(int i = 0; i < intervalsSize; i++) {
        tempArr[i] = intervals[i][0];
    }
    qsort(tempArr, intervalsSize, sizeof(tempArr[0]), compare);
    int s = 0;
    int e = intervalsSize - 1;
    int mid = s + (e - s) / 2;
    int ans = -1;
    for(int i = 0; i < intervalsSize; i++) {
        while(s <= e) {
            if(intervals[i][1] == tempArr[mid]) {
                ans = tempArr[mid];
                break;
            }
            else if(intervals[i][1] < tempArr[mid]) {
                ans = tempArr[mid];
                e = mid - 1;
            }
            else {
                s = mid + 1;
            }
            mid = s + (e - s) / 2;
        }
        retArr[i] = ans;
        ans = -1;
        s = 0;
        e = intervalsSize - 1;
        mid = s + (e - s) / 2;
    }
    return retArr;
}
int main() {
    int row = 3, col = 2;
    int **arr = (int **)malloc(row * sizeof(int *));
    for (int i = 0; i < row; i++)
    {
        arr[i] = (int *)malloc(col * sizeof(int));
    }
    arr[0][0] = 1;
    arr[0][1] = 4;
    arr[1][0] = 2;
    arr[1][1] = 3;
    arr[2][0] = 3;
    arr[2][1] = 4;
    int returnSize = 0;
    int *arr2 = findRightInterval(arr, row, &col, &returnSize);
    for (int i = 0; i < returnSize; i++)
    {
        printf("%d ", arr2[i]);
    }
    return 0;
}
// [1,4],[2,3],[3,4]