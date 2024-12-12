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
int hIndex(int *citations, int citationsSize) {
    int *arr = countingSort(citations, citationsSize);
    int s = 0, e = citationsSize - 1;
    int mid = s + (e - s) / 2, ans = 0;
    while(s <= e) {
        if(arr[mid] == citationsSize - mid) {
            return citationsSize - mid;
        } else if(arr[mid] > citationsSize - mid) {
            ans = citationsSize - mid;
            e = mid - 1;
        } else {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int main() {
    int citations[] = {1,1};
    int citationsSize = sizeof(citations) / sizeof(int);
    int *arr = countingSort(citations, citationsSize);
    printf("%d", H_index(citations, citationsSize));
    return 0;
}