#include <iostream>
using namespace std;
bool linearSearch(int *arr, int size, int target) {
    if(size == 0)
        return false;
    if(arr[size - 1] == target)
        return true;
    return linearSearch(arr, size - 1, target);
}
int main() {
    int arr[] = {0, 1, 6, 3, 8, 2, 9};
    int size = sizeof(arr) / sizeof(int);
    cout << linearSearch(arr, size, 6);
    return 0;
}