#include <iostream>
using namespace std;
int findPivot(int *arr, int s, int e, int size) {
    if(size == 0)
        return -1;
    if(s == e)
        return arr[s] < arr[0] && s != 0 ? s : -1;
    int mid = s + (e - s) / 2;
    int ans = mid;
    if(mid == 0 || arr[mid] > arr[0])
        ans = findPivot(arr, mid + 1, e, size);
    else if(arr[mid] < arr[0])
        ans = findPivot(arr, s, mid, size);
    return ans;
}
int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int size = sizeof(arr) / sizeof(int);
    cout << findPivot(arr, 0, size - 1, size);
    return 0;
}