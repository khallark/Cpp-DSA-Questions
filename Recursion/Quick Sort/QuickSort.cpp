#include <iostream>
using namespace std;
int partitioning(int *arr, int s, int e) {
    int count = 0; 
    for(int i = s + 1; i <= e; i++) {
        if(arr[s] >= arr[i]) count++;
    }
    swap(arr[s], arr[s + count]);
    int i = s, j = e;
    while(i < s + count && j > s + count) {
        while(arr[i] <= arr[s + count]) {
            i++;
        }
        while(arr[j] > arr[s + count]) {
            j--;
        }
        if(i < s + count && j > s + count) {
            swap(arr[i++], arr[j--]);
        }
    }
    return s + count;
}
void quickSort(int *arr, int s, int e) {
    if(s >= e) return;
    int p;
    p = partitioning(arr, s, e);
    quickSort(arr, s, p - 1);
    quickSort(arr, p + 1, e);
}
int main() {
    int arr[] = {5, 2, 6, 7, 3, 8, 6, 3, 8, 1};
    int size = sizeof(arr) / sizeof(int);
    // for(int i = 0; i < size; i++) {
    //     cout << arr + i << " ";
    // }
    // cout << endl;
    quickSort(arr, 0, size - 1);
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}