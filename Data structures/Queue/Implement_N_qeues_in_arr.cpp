#include <iostream>
using namespace std;
class Nqeues {
    int n;
    int s;
    int *arr;
    int *front;
    int *rear;
    int *next;
    int freeSpot = 0;
public:
    Nqeues() {}
    Nqeues(int N, int S) : n(N), s(S) {
        arr = new int[n];
        front = new int[s];
        rear = new int[s];
        next = new int[n];
        for(int i = 0; i < s; i++) {
            front[i] = rear[i] = -1;
        }
        for(int i = 0; i < n - 1; i++) {
            next[i] = i + 1;
        }
        next[n - 1] = -1;
    }
    void push(int data, int m) {
        if(freeSpot == -1) return;
        
        int index = freeSpot;

        freeSpot = next[index];

        arr[index] = data;

        if(front[m - 1] == -1) {
            front[m - 1] = index;
        }
        else {
            next[rear[m - 1]] = index;
        }
        next[index] = -1;
        rear[m - 1] = index;
    }
    void pop(int m) {
        if(front[m - 1] == -1) return;
        
        int index = front[m - 1];

        front[m - 1] = next[index];
        
        next[index] = freeSpot;

        freeSpot = index;
    }
};
int main() {

}