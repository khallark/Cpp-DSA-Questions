#include <iostream>
using namespace std;
int getSum(int *arr, int size) {
    if(size == 0)
        return 0;
    if(size == 1)
        return arr[0];
    return arr[size - 1] + getSum(arr, size - 1);
}
int main() {
    int arr[] = {1, 49, 5, 5};
    int size = sizeof(arr) / sizeof(int);
    cout << getSum(arr, size) << endl;
    return 0;
}