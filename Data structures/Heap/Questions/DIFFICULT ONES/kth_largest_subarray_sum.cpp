#include <iostream>
#include <queue>
using namespace std;
int kthLargest(vector<int> &Arr,int N,int K){
    priority_queue<int, vector<int>, greater<int>> q;
    int sum = 0;
    for(int i = 0; i < N; i++) {
        for(int j = i; j < N; j++) {
            sum += Arr[j];
            q.push(sum);
            if(q.size() > K) {
                q.pop();
            }
        }
        sum = 0;
    }
    return q.top();
}
int main() {
    vector<int> Arr = {2, 6, 4, 1};
    int N = Arr.size();
    int K = 3;
    cout << kthLargest(Arr, N, K);
    return 0;
}