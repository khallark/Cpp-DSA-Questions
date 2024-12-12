#include <iostream>
#include <vector>
using namespace std;
template <typename data>
class queue {
    int front = -1;
    int rear = -1;
    int size;
    data *arr;
    queue() {}
    queue(int size) : size(size) {
        arr = new data[size];
        front = 0;
        rear = 0;
    }
    void enqueue(data d) {
        if(rear == size) {
            return;
        }
        arr[rear] = data;
        rear++;
    }
    data dequeue() {
        if(front == rear) {
            return;
        }
        data value = arr[front];
        front++;
        if(front == rear) {
            front = 0;
            rear = 0;
        }
        return value;
    }
    data getFront() {
        if(front == rear) {
            return 0;
        }
        return arr[front];
    }
    bool isEmpty() {
        return front == rear;
    }
};