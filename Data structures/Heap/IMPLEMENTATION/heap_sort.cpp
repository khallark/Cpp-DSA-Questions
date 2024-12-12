#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
    while(i < n) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        
        if(left < n && arr[largest] < arr[left]) {
            largest = left;
        }
        if(right < n && arr[largest] < arr[right]) {
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

void buildHeap(int arr[], int n) {
    for(int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

void heapSort(int arr[], int n) {
    buildHeap(arr, n);
    for(int i = n - 1; i >= 0; i--) {
        swap(arr[i], arr[0]);
        heapify(arr, i, 0);
    }
}

int main() {
    int arr[] = {6, 3, 9, 1, 4, 2, 7, 3};
    int n = sizeof(arr) / sizeof(int);
    heapSort(arr, n);
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}