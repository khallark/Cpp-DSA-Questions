#include <stdio.h>
int getPivot(int *arr, int n) {
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;
    while(s < e) {
        if (arr[mid] >= arr[0]) {
            s = mid + 1;
        }
        else {
            e = mid;
        }
        mid = s + (e - s) / 2;
    }
    return s == n - 1 ? (arr[s] < arr[s - 1] ? s : -1) : s;
}
int main() {
    int arr[] = {5, 7, 8, 12, 23, 45, 0, 2, 3, 4};
    int size = sizeof(arr) / sizeof(int);
    int a = getPivot(arr, size);
    printf("%d", a);
    return 0;
}