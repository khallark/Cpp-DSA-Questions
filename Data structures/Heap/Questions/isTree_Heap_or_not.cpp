/*
bool isHeap(Node* tree) {
    vector<Node*> v = level_order(tree);
    bool check = false;
    int i = 1;
    int expo = 2;
    int j = expo;
    while(check != true) {
        for(int k = i; k <= j; k += 2) {
            int parent = k / 2;
            Node *left = v[k];
            Node *right = v[k + 1];
            if(check == false) {
                if(left && right) {   
                    if(left->data > v[parent]->data || right->data > v[parent]->data) {
                        return false;
                    }
                }
                else if(!left && right) {   
                    return false;
                }
                else {
                    if(left && !right && left->data > v[parent]->data) {        
                        return false;
                    }
                    check = true;
                }
            }
            else if(left || right) {
                return false;
            }
        }
        i = j + 1;
        expo *= 2;
        j += expo; 
    }
    while(i < v.size()) {
        if(v[i++]) {
            return false;
        }
    }
    return true;
}
*/
#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;
class Node {
public:
    int data;
    Node *left;
    Node *right;
    Node(int val) {
        this->data = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};
Node *build_from_level_order(Node *root) {
    queue<Node*> q;
    cout << "Enter the data for root node : ";
    int data;
    cin >> data;
    root = new Node(data);
    q.push(root);

    while(!q.empty()) {
        Node *temp = q.front();
        q.pop();

        cout << "Enter the left value of node " << temp->data << " : ";
        int data;
        cin >> data;
        if(data != -1) {
            temp->left = new Node(data);
            q.push(temp->left);
        }

        cout << "Enter the right value of node " << temp->data << " : ";
        cin >> data;
        if(data != -1) {
            temp->right = new Node(data);
            q.push(temp->right);
        }
    }
    return root;
}
vector<Node*> level_order(Node *tree) {
    vector<Node*> v;
    queue<Node*> q;
    q.push(tree);
    while(!q.empty()) {
        Node *temp = q.front();
        q.pop();
        v.push_back(temp);
        if(temp) {
            q.push(temp->left);
            q.push(temp->right);
        }
    }
    return v;
}
bool isHeap(Node* tree) {
    vector<Node*> v = level_order(tree);
    bool check = false; // if check becomes true, it means that we have checked the last(incomplete) level.
    int i = 1;
    int expo = 2;
    int j = expo;
    while(check != true) {
        // this loop checks for every node at every level, and also identifies the last (incomplete) level.
        for(int k = i; k <= j; k += 2) {
            int parent = k / 2;
            Node *left = v[k];
            Node *right = v[k + 1];
            if(check == false) {
                if(left && right) {
                    if(left->data > v[parent]->data || right->data > v[parent]->data) return false;
                }
                else if(!left && right) return false;
                else { // if ever reached to this, it means that the program is at the last (incomplete) level.
                    if(left && !right) {
                        if(left->data > v[parent]->data) return false;
                    }
                    check = true; // check becomes true, implying that we need to break the loop and check for the level after the incomplete level.
                }
            }
            else if(left || right) return false; // this only runs when program is at the last (incomplete) level, and if identifies any node which is not NULL, returns false.
        }
        i = j + 1, expo *= 2, j += expo;
    }
    while(i < v.size()) if(v[i++]) return false; // this loop is for checking the left and right children of the nodes of the last (incomplete) level.
    return true;
}

int main() {
    Node *root = build_from_level_order(root);
    // 8 7 6 -1 -1 5 4 -1 -1 -1 -1
    // 8 7 6 3 2 -1 -1 -1 -1 1 -1 -1 -1
    // 8 7 6 3 2 5 4 -1 -1 -1 -1 -1 -1 -1 -1
    // 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 4 -1 -1 -1
    // 7 6 -1 5 -1 4 -1 3 -1 2 -1 1 -1 -1 -1
    // 7 -1 6 -1 5 -1 4 -1 3 -1 2 -1 1 -1 -1
    // 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
    // 6 5 4 3 2 -1 -1 -1 -1 -1 1 -1 -1
    cout << endl << endl << isHeap(root);
}