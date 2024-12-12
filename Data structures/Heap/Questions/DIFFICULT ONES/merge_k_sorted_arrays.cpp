#include <iostream>
#include <queue>
using namespace std;
class node {
  public:
  int data;
  int i;
  int j;
  node(int data, int i, int j) : data(data), i(i), j(j) {}
};
class compare {
    public:
    bool operator()(node *a, node *b) {
        return a->data > b->data;
    }
};

//Function to merge k sorted arrays.
vector<int> mergeKArrays(vector<vector<int>> arr, int K)
{
    priority_queue<node*, vector<node*>, compare> q;
    for(int i = 0; i < K; i++) {
        node *temp = new node(arr[i][0], i, 0);
        q.push(temp);
    }
    
    vector<int> ans(K * K);
    int index = 0;
    
    while(q.size()) {
        node *temp = q.top();
        
        ans[index++] = q.top()->data;
        q.pop();
        
        int i = temp->i;
        int j = temp->j;
        
        if(j + 1 < K) {
            temp->data = arr[i][j + 1];
            temp->j = j + 1;
            q.push(temp);
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> v = {{7, 8, 9}, {1, 2, 3}, {4, 5, 6}};
    vector<int> ans = mergeKArrays(v, v.size());
    for(auto i : ans) {
        cout << i << " ";
    }
    return 0;
}