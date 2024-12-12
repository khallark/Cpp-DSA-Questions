#include <iostream>
using namespace std;
void push_negs_to_left(int arr[], int size) {
    int left = 0;
    int right = size - 1;
    while(left < right) {
        if(arr[left] > 0 && arr[right] < 0) {
            swap(arr[left++], arr[right--]);
        }
        else if(arr[left] < 0) {
            left++;
        }
        else {
            right--;
        }
    }
}
int main() {
    int arr[] = {-7, 2, -6, -3, 4, -7, 4, -7, 1, -2, 5, -3, 6, -4, -9, 6, -4, 9};
    int size = sizeof(arr) / sizeof(int);
    push_negs_to_left(arr, size);
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}