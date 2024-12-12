#include <iostream>
using namespace std;
void heapify_recursive(int *arr, int n, int i) {
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if(left <= n && arr[largest] < arr[left]) {
        largest = left;
    }
    if(right <= n && arr[largest] < arr[right]) {
        largest = right;
    }

    if(largest != i) {
        swap(arr[largest], arr[i]);
        heapify_recursive(arr, n, largest);
    }
}
void heapify_iterative(int *arr, int n, int i) {
    while(i <= n) {
        int largest = i;
        int left = 2 * i;
        int right = 2 * i + 1;

        if(left <= n && arr[largest] < arr[left]) {
            largest = left;
        }
        if(right <= n && arr[largest] < arr[right]) {
            largest = right;
        }

        if(largest != i) {
            swap(arr[largest], arr[i]);
            i = largest;
        }
        else {
            return;
        }
    }
}

void convert_to_heap(int *arr, int n) {
    for(int i = n / 2; i > 0; i--) {
        heapify_iterative(arr, n, i);
    }
}
int main() {
    int arr[] = {-1, 4, 1, 3, 9, 7};
    int n = sizeof(arr) / sizeof(int);
    convert_to_heap(arr, n - 1);
    for(int i = 1; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}