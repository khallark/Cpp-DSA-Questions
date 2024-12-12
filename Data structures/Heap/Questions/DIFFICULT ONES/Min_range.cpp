#include <iostream>
#include <limits.h>
#include <queue>
#define N 1000
using namespace std;

class node {
    public:
    int data;
    int i;
    int j;
    node(int data, int i, int j) : data(data), i(i), j(j) {}
};
class compareMin {
    public:
    bool operator()(node *a, node *b) {
        return a->data > b->data;
    }
};

pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k)
{
    priority_queue<node*, vector<node*>, compareMin> minHeap;


    int maxi = -1;
    for(int i = 0; i < k; i++) {
        node *temp = new node(KSortedArray[i][0], i, 0);
        maxi = max(KSortedArray[i][0], maxi);
        minHeap.push(temp);
    }


    pair<int, int> ans = make_pair(minHeap.top()->data, maxi);
    int done = 0;
    int minSum = maxi - minHeap.top()->data;


    while(!minHeap.empty()) {
        node *temp = minHeap.top();
        minHeap.pop();
        

        if(maxi - temp->data < minSum) {
            ans.first = temp->data;
            ans.second = maxi;
            minSum = ans.second - ans.first;
        }
        

        int i = temp->i;
        int j = temp->j;
        if(j + 1 < n) {
            maxi = max(KSortedArray[i][j + 1], maxi);
            temp->data = KSortedArray[i][j + 1];
            temp->j = j + 1;
            minHeap.push(temp);
        }
        else {
            break;
        }
    }

    
    return ans;
}

int main() {
    int arr[][N] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = sizeof(arr[0]) / sizeof(arr[0][0]);
    pair<int, int> ans = findSmallestRange(arr, n, 3);
    cout << ans.first << ", " << ans.second;
    return 0;
}