#include <iostream>
using namespace std;
class heap {
    int arr[100];
    int size = 0;
public:
    void put(int data) {
        int index = ++size;
        arr[index] = data;
        int i = index;
        while(i > 1) {
            if(arr[i / 2] < arr[i]) {
                swap(arr[i / 2], arr[i]);
                i = i / 2;
            }
            else {
                return;
            }
        }
    }
    
    void call() {
        if(size == 0) {
            return;
        }
        arr[1] = arr[size];
        size--;

        int i = 1;
        while(i <= size) {
            int largest = i;
            int left = 2 * i;
            int right = 2 * i + 1;
            if(left <= size && arr[largest] < arr[left]) {
                largest = left;
            }
            if(right <= size && arr[largest] < arr[right]) {
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

    int top() {
        return arr[1];
    }

    void print() {
        for(int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        }
    }
};
int main() {
    heap h;
    // 12 10 9 5 6 2 7
    h.put(10);
    h.put(5);
    h.put(6);
    h.put(2);
    h.put(12);
    h.put(7);
    h.put(9);
    // h.call();
    // h.call();
    // h.call();
    // h.call();
    // h.call();
    // h.call();
    // h.call();
    // h.call();
    // h.call();
    h.print();
    // cout << endl << h.top();
    return 0;
}