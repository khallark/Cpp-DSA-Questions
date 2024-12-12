    
#include <iostream>
#include <vector>
using namespace std;
template <typename data>
class deque {
public:
    int size;
    data *arr;
    int front = -1;
    int rear = -1;
    deque() {}
    deque(int size) : size(size) {
        arr = new data[size];
        for(int i = 0; i < size; i++) {
            arr[i] = -1;
        }
    }
    void push_front(data d) {
        if(isFull()) {
            return;
        }
        if(isEmpty()) {
            front = rear = 0;
        }
        else if(front == 0  && rear != size - 1) {
            front = size - 1;
        }
        else {
            front--;
        }
        arr[front] = d;
    }
    void push_rear(data d) {
        if(isFull()) {
            return;
        }
        if(isEmpty()) {
            front = rear = 0;
        }
        else if(rear = size - 1 && front != 0) {
            rear = 0;
        }
        else {
            rear++;
        }
        arr[rear] = d;
    }
    data pop_front() {
        if(isEmpty()) {
            return 0;
        }
        data val = arr[front];
        arr[front] = -1;
        if(front == rear) {
            front = rear = -1;
        }
        else if(front == size - 1) {
            front = 0;
        }
        else {
            front++;
        }
        return val;
    }
    data pop_rear() {
        if(isEmpty()) {
            return 0;
        }
        data val = arr[rear];
        arr[rear] = -1;
        if(front == rear) {
            front = rear = -1;
            return 0;
        }
        if(rear == 0) {
            rear = size - 1;
        }
        else {
            rear--;
        }
        return val;
    }
    data getFront() {
        if(isEmpty()) {
            return 0;
        }
        return arr[front];
    }
    data getRear() {
        if(isEmpty()) {
            return 0;
        }
        return arr[rear];
    }
    bool isEmpty() {
        if(front == -1)
            return true;
        else
            return false;
    }
    bool isFull() {
		if((front == 0 && rear == size-1) || (front != 0 && rear == (front - 1) % (size - 1))) {
            return true;
        }
        else {
            return false;
        }
    }
};
int main() {
    deque<int> q(6);
    q.push_front(2);
    q.push_front(3);
    // q.push_rear(4);  
    for(int i = 0; i < q.size; i++) {
        cout << q.arr[i] << " ";
    }
    return 0;
}