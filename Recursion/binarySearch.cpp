#include <iostream>
using namespace std;
bool binarySearch(int *arr, int size, int target) {
    int s = 0, e = size - 1, mid = s + (e - s) / 2;
    if(size == 0)
        return false;
    if (target == arr[mid])
        return true;
    else if(target > arr[mid])
        return binarySearch(arr + mid + 1, size - (mid + 1), target);
    else
        return binarySearch(arr, size - (mid + 1), target);
}
int binarySearch2(int *arr, int s, int e, int target) {
    int mid = s + (e - s) / 2;
    if(s > e)
        return -1;
    if(arr[mid] == target)
        return mid + 1;
    else if(arr[mid] < target)
        return binarySearch2(arr, mid + 1, e, target);
    else
        return binarySearch2(arr, s, mid - 1, target);
}
int main() {
    int arr[] = {2,4,6,8,10,12,14,16,18,20};
    int size = sizeof(arr) / sizeof(int);
    cout << binarySearch2(arr, 0, size - 1, 5) << endl;
    return 0;
}