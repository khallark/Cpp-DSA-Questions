#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;
struct Node {
  int data;
  Node* left;
  Node* right;

  Node(int x) {
    data = x;
    left = nullptr;
    right = nullptr;
  }
};

Node *build_from_level_order(Node *root) {
    queue<Node*> q;
    cout << "Enter the data for root Node : ";
    int data;
    cin >> data;
    if(data == -1) {
        return root;
    }
    root = new Node(data);
    q.push(root);

    while(!q.empty()) {
        Node *temp = q.front();
        q.pop();

        cout << "Enter the left value of Node " << temp->data << " : ";
        int data;
        cin >> data;
        if(data != -1) {
            temp->left = new Node(data);
            q.push(temp->left);
        }

        cout << "Enter the right value of Node " << temp->data << " : ";
        cin >> data;
        if(data != -1) {
            temp->right = new Node(data);
            q.push(temp->right);
        }
    }
    return root;
}

int minTime(Node* root, int target)  {
    // Step 1:
    queue<Node*> q;
    unordered_map<Node*, Node*> nodeToParent;
    q.push(root);
    nodeToParent[root] = nullptr;
    Node *target_node = nullptr;
    while(!q.empty()) {
        Node *temp = q.front();
        q.pop();
        if(temp->data == target) {
            target_node = temp;
        }
        if(temp->left) {
            q.push(temp->left);
            nodeToParent[temp->left] = temp;
        }
        if(temp->right) {
            q.push(temp->right);
            nodeToParent[temp->right] = temp;
        }
    }

    // Step 2:
    int time = 0;
    unordered_map<Node*, bool> visited;
    visited[target_node] = true;
    q.push(target_node);
    while(!q.empty()) {
        int added_or_not = false;
        int size = q.size();
        for(int i = 0; i < size; i++) {
            Node *temp = q.front();
            q.pop();

            if(temp->left && visited[temp->left] == false) {
                q.push(temp->left);
                visited[temp->left] = true;
                added_or_not = true;
            }
            if(temp->right && visited[temp->right] == false) {
                q.push(temp->right);
                visited[temp->right] = true;
                added_or_not = true;
            }
            if(nodeToParent[temp] && visited[nodeToParent[temp]] == false) {
                q.push(nodeToParent[temp]);
                visited[nodeToParent[temp]] = true;
                added_or_not = true;
            }
        }

        if(added_or_not) {
            time++;
        }

        added_or_not = false;
    }

    // Step 3:
    return time;
}
int main() {
    Node *root = build_from_level_order(root);
    // 1 2 3 4 5 -1 6 -1 -1 7 8 -1 9 -1 -1 -1 -1 -1 10 -1 -1
    cout << endl << minTime(root, 2) << endl;
    return 0;
}