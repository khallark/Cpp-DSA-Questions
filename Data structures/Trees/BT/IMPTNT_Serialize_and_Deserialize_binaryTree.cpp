// given -1000 <= node->d <= 1000
#include <iostream>
#include <vector>
#include <matrix.h>
#include "AAAnode.cpp"
using namespace std;
class Codec {
private:
    vector<int> split(string s) {
        vector<int> nodes;
        string num = "";
        for(int i = 0; i < s.length(); i++) {
            if(s[i] != ' ') {
                if(s[i] == 'N') num += "-100000";
                else num += s[i];
            }
            else {
                nodes.push_back(stoi(num));
                num = "";
            }
        }
        return nodes;
    }
public:
    string serialize(Node* root) {
        string ans = "";
        queue<Node*> q;
        q.push(root);
        ans += to_string(root->d) + " ";
        while(!q.empty()) {
            Node *temp = q.front();
            q.pop();
            if(temp->left) q.push(temp->left), ans += to_string(temp->left->d) + " ";
            else ans += "N ";
            if(temp->right) q.push(temp->right), ans += to_string(temp->right->d) + " ";
            else ans += "N ";
        }
        return ans;
    }

    Node* deserialize(string data) {
        vector<int> nodes = split(data);
        int i = 0;
        queue<Node*> q;
        Node *root = new Node(nodes[i]);
        q.push(root);
        while(!q.empty()) {
            Node *temp = q.front();
            q.pop();
            if(nodes[++i] != -100000) {
                Node *node = new Node(nodes[i]);
                temp->left = node;
                q.push(node);
            }
            if(nodes[++i] != -100000) {
                Node *node = new Node(nodes[i]);
                temp->right = node;
                q.push(node);
            }
        }
        return root;
    }
};

void level_order(Node *root) {
    queue<Node*> q;
    q.push(root);
    q.push(nullptr);
    while(!q.empty()) {
        Node *temp = q.front();
        cout << temp->d << " ";
        q.pop();
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
        if(q.front() == nullptr) {
            cout << endl;
            q.pop();
            if(!q.empty()) q.push(nullptr);
        }
    }
}

int main() {
    Node *root = nullptr;
    cout << "Input - ";
    root = build_from_level_order(root);
    // 57 2 64 212 1 -1 3 -1 -1 -1 4 49 100 -1 -1 -1 -1 -1 -1
    // 1000 2000 3000 4000 -1 -1 5000 6000 -1 -1 7000 -1 -1 -1 -1
    // 1 2 3 4 -1 -1 5 -1 -1 -1 -1
    cout << endl << "Before Serializing/Deserializing -" << endl;
    level_order(root);
    cout << endl;
    Codec a;
    root = a.deserialize(a.serialize(root));
    cout << "After Serializing/Deserializing -" << endl;
    level_order(root);
    return 0;
}