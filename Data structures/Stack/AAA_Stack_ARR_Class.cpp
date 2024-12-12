#include <iostream>
using namespace std;
template <typename DataType>
class stack {
    int topIndx = -1;
    int maxSize = 0;
    DataType *arr;
public:
    stack() {
    }
    stack(int maxSize) : maxSize(maxSize) {arr = new DataType[maxSize];}
    void push(int data) {
        if(topIndx == maxSize - 1) return;
        topIndx++;
        arr[topIndx] = data;
    }
    DataType pop() {
        if(topIndx == -1) return 0;
        return arr[topIndx--];
    }
    DataType top() {
        if(topIndx == -1) return 0;
        return arr[topIndx];
    }
    bool empty() {
        return topIndx == -1;
    }
    int size() {
        return topIndx + 1;
    }
};