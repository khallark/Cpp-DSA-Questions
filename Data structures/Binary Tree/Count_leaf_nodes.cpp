#include <iostream>
#include <queue>
using namespace std;

class node {
public:
    int d;
    node *left;
    node *right;
    node(int val) {
        this->d = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

node *build_from_level_order(node *root) {
    queue<node*> q;
    cout << "Enter the data for root node : ";
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);

    while(!q.empty()) {
        node *temp = q.front();
        q.pop();

        cout << "Enter the left value of node " << temp->d << " : ";
        int data;
        cin >> data;
        if(data != -1) {
            temp->left = new node(data);
            q.push(temp->left);
        }

        cout << "Enter the right value of node " << temp->d << " : ";
        cin >> data;
        if(data != -1) {
            temp->right = new node(data);
            q.push(temp->right);
        }
    }
    return root;
}

void solve(node *root, int &count ) {
    if(root == nullptr) {
        return;
    }
    else if(root->left == nullptr && root->right == nullptr) {
        count++;
        return;
    }
    solve(root->left, count);
    solve(root->right, count);
}
int count_Leaf_Nodes(node *root) {
    int count = 0;
    solve(root, count);
    return count;
}

int main() {
    node *root;
    root = build_from_level_order(root);
    /*
        1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
    
                                                1
                                               / \
                                              /   \
                                             /     \
                                            /       \
                                           /         \
                                          /           \
                                         /             \
                                        2               3
                                       / \             / \
                                      /   \           /   \
                                     /     \         /     \
                                    4       5       6       7
                                   / \     / \     / \     / \
                                  8   9   10 11   12 13   14 15
    */
    cout << endl;
    cout << count_Leaf_Nodes(root);
    return 0;
}