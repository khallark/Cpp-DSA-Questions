#include <iostream>
using namespace std;
void mergeArrs(int *arr, int s, int e) {
    int mid = s + (e - s) / 2;
    int size1 = mid - s + 1;
    int size2 = e - mid;
    int mainIndx = s;
    int *split1 = new int[size1];
    int *split2 = new int[size2];
    for(int i = 0; i < size1; i++) {
        split1[i] = arr[mainIndx++];
    }
    for(int i = 0; i < size2; i++) {
        split2[i] = arr[mainIndx++];
    }
    int indx1 = 0;
    int indx2 = 0;
    mainIndx = s;
    while(indx1 < size1 && indx2 < size2) {
        if(split1[indx1] > split2[indx2]) {
            arr[mainIndx++] = split2[indx2++];
        }
        else {
            arr[mainIndx++] = split1[indx1++];
        }
    }
    while(indx1 < size1) {
        arr[mainIndx++] = split1[indx1++];
    }
    while(indx2 < size2) {
        arr[mainIndx++] = split2[indx2++];
    }
    delete []split1;
    delete []split2;
}
void mergeSort(int *arr, int s, int e) {
    if(s >= e) return;
    int mid = s + (e - s) / 2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);
    mergeArrs(arr, s, e);
}
int main() {
    int arr[] = {123, 43, 546, 6, 3, 221, 23435, 67876, 54, 23, 34, 567, 78, 564, 32, 34, 56, 7879, 876, 54, 4343, 56, 768, 67, 54, 43, 4, 356, 7, 89, 87, 65, 4, 5, 56, 78, 89 };
    int size = sizeof(arr) / sizeof(int);
    mergeSort(arr, 0, size - 1);
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}