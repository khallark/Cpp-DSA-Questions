#include <iostream>
using namespace std;
int split(int *arr, int s, int e) {
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
void merge(int *arr, int s, int e) {
    int mid = s + (e - s) / 2;
    int size1 = mid - s + 1;
    int size2 = e - mid;
    int *split1 = new int[size1];
    int *split2 = new int[size2];
    int mainIndx = s;
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
void quickSort(int *arr, int s, int e) {
    //base case
    if(s >= e) {
        return;
    }
    int mid = split(arr, s, e);
    quickSort(arr, s, mid -1);
    quickSort(arr, mid + 1, e);
}
void mergeSort(int *arr, int s, int e) {
    int mid = s + (e - s) / 2;
    if(s >= e) {
        return;
    }
    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);
    merge(arr, s, e);
}
int main() {
    int arr[] = {6,3,4,2,7,5,3,8,7,2,5,3,7,3,7,1,5,7,3,0,7,3,6,2,7,9};
    int size = sizeof(arr) /sizeof(int);
    mergeSort(arr, 0, size - 1);
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}