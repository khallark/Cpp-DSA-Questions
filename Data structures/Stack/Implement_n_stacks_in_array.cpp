#include <iostream>
using namespace std;
class NStack {
public:
    int *arr;
    int *top;
    int *next;
    int n, s;
    int freeSpot; // tells the first most free space of the remaining.

    // Initialize your data structure.
    NStack(int N, int S) {
        n = N; // number of stacks
        s = S; // size of array

        //Giving appropriate sizes to arrays.
        arr = new int[s];
        top = new int[n];
        next = new int[s];
        
        // initialize top.
        for(int i = 0; i < n; i++) {
            top[i] = -1;
        }

        // initialize next.
        for(int i = 0; i < s; i++) {
            next[i] = i + 1;
        }
        next[s - 1] = -1; // last index in next is -1 because there is no free block after the last one

        // initializing freeSpot.
        freeSpot = 0;
    }
    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m) {
        // check for overflow
        if(freeSpot == -1) return false;
        
        // get the free index to put the data in.
        int index = freeSpot;

        // modifying freeSpot to the next free space in arr.
        freeSpot = next[index];

        // putting value in original arr.
        arr[index] = x;

        // changing the definition of next[].
        next[index] = top[m - 1];

        // modifying the top of the mth stack.
        top[m - 1] = index;
        
        // successful implimentation returns TRUE
        return true;
    }
    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m) {
        // check for underflow.
        if(top[m - 1] == -1) return -1;

        // get the top index which is to be freed.
        int index = top[m - 1];

        // modify the top of that mth stack with the value in the "index" index of the next.
        top[m - 1] = next[index];

        // since the space at "index" is freed, next the next's index to point to the next free space
        // using "freeSpot".
        next[index] = freeSpot;

        // shift the "freeSpot" to the most recently "FREED SPOT".
        freeSpot = index;

        // return the value popped
        return arr[index];
    }
};
int main() {
    NStack s(3, 6);
}