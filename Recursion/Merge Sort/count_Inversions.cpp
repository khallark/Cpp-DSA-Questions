#include <iostream>
using namespace std;
int merge(int *arr, int s, int e) {
    int counter = 0;
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
    while(indx1 < size1 && indx2 < size2){
        if(split1[indx1] > split2[indx2]) {
            counter += size1 - indx1;
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
    return counter;
}
int count_Inversions(int *arr, int s, int e) {
    if(s >= e) return 0;
    int mid = s + (e - s) / 2;
    int ans = 0;
    ans += count_Inversions(arr, s, mid);
    ans += count_Inversions(arr, mid + 1, e);
    return ans + merge(arr, s, e);
}
int main() {
    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int size = sizeof(arr) / sizeof(int);
    int num_Inversions = count_Inversions(arr, 0, size - 1);
    // int num_Inversions = merge(arr, 0, size - 1);
    cout << "The number of inversions = " << num_Inversions << endl;
    return 0;
}