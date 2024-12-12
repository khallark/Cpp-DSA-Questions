#include <iostream>
#include <vector>
using namespace std;
void bubbleSort_Recursive_Iterative(vector<int>& arr, int size) {
    int ye__To_Pehle_Se_Hi_Sorted_Hai = true;
    if(size == 0 || size == 1)
        return;
    for(int i = 0; i < size - 1; i++) if(arr[i] > arr[i + 1]) ye__To_Pehle_Se_Hi_Sorted_Hai = false, swap(arr[i], arr[i + 1]);
    if(ye__To_Pehle_Se_Hi_Sorted_Hai) return;
    bubbleSort_Recursive_Iterative(arr, size - 1);
}
void bubbleSort_Pure_Recusive(vector<int>& arr, int size1, int size2) {
    if(size1 == 0 || size1 == 1) return;
    int a = size2 - size1;
    if(arr[a] > arr[a + 1]) swap(arr[a], arr[a + 1]);
    bubbleSort_Pure_Recusive(arr, size1 - 1, size2);
    if(size1 == size2) bubbleSort_Pure_Recusive(arr, size1 - 1, size2 - 1);
}
int main() {
    vector<int> arr = {9,8,7,6,5,4,3,2,1};
    // bubbleSort_Recursive_Iterative(arr, arr.size());
    bubbleSort_Pure_Recusive(arr, arr.size(), arr.size());
    for(auto i: arr) cout << i << " ";
    return 0;
}