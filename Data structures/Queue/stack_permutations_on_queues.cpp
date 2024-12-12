#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
bool isStackPermutation(int N,vector<int> &A,vector<int> &B){
    queue<int> inq;
    queue<int> outq;
    stack<int> st;
    for(int i = 0; i < A.size(); i++) {
        inq.push(A[i]);
        outq.push(B[i]);
    }
    while(!inq.empty()) { // Runs until input queue becomes empty.
        int element = inq.front();
        inq.pop();
        if(element == outq.front()) { // Executes if the front of input queue == front of output queue.
            outq.pop();
            while(!st.empty()) { // Iterates until or unless stack becomes empty or stack top != output queue's front.
                if(st.top() == outq.front()) {
                    st.pop();
                    outq.pop();
                }
                else {
                    break;
                }
            }
        }
        else { // If the front of input queue != front of output queue, pushes input front into stack.
            st.push(element);
        }
    }
    return outq.empty(); // Basically, the permutation is possible if and only if both the queues and the stack, are empty, else not. We can also write this as "return st.empty();"
}
int main() {
    vector<int> inq = {1, 2, 3};
    vector<int> outq = {2, 1, 3};
    cout << isStackPermutation(inq.size(), inq, outq) << endl;
    return 0;
}