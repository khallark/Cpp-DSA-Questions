#include <iostream>
#include <vector>
using namespace std;
template <typename data>
class queue {
    int size;
    data *arr;
    int front = -1;
    int rear = -1;
public:
    queue() {}
    queue(int size) : size(size) {
        arr = new data[size];
    }
    void enqueue(data d) {
        if(rear == (front - 1) || (rear == size - 1 && front == 0)) {
            return;
        }
        if(front == -1) {
            front = 0;
            rear = 0;
        }
        else if(rear == size - 1) {
            rear = 0;
        }
        else {
            rear++;
        }
        arr[rear] = d;
    }
    data dequeue() {
        if(front == -1) {
            return 0;
        }
        data val = arr[front];
        arr[front] = -1;
        if(front == rear) {
            front = rear = -1;
            return 0;
        }
        if(front == size - 1) {
            front = 0;
        }
        else {
            front++;
        }
        return val;
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
int main() {
    return 0;
}