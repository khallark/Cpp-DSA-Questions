#include <iostream>
#include <vector>
using namespace std;
bool isSorted(int *arr, int size) {
    if(size == 0 || size == 1)
        return true;
    if(!isSorted(arr, size - 1))
        return false;
    if(arr[size - 1] >= arr[size - 2])
        return true;
    return false;
}
int main() {
    int arr[] = {1, 2, 3, 4, 5, 7};
    int size = sizeof(arr) / sizeof(int);
    cout << isSorted(arr, size) << endl;
    return 0;
}