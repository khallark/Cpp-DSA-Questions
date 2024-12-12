#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Node {
public:
    vector<Node*> chars;
    bool isTerminal;
    Node() : chars(26, nullptr), isTerminal(false) {}
};

class Trie {
public:
    Node* head = new Node();
    Trie() {}
    void insert(string word) {
        Node *temp = head;
        for(auto i : word) {
            if(!temp->chars[i - 'a']) {
                Node* newC = new Node();
                temp->chars[i - 'a'] = newC;
            }
            temp = temp->chars[i - 'a'];
        }
        temp->isTerminal = true;
    }
    
    bool search(string word) {
        Node *temp = head;
        for(auto i : word) {
            if(!temp->chars[i - 'a']) {
                return false;
            }
            temp = temp->chars[i - 'a'];
        }
        return temp->isTerminal;
    }
    
    bool startsWith(string prefix) {
        Node *temp = head;
        for(auto i : prefix) {
            if(!temp->chars[i - 'a']) {
                return false;
            }
            temp = temp->chars[i - 'a'];
        }
        return true;
    }
};

bool solve(string A, int ind, Node* orgn, Node* head) {
    if (ind == A.length()) return head->isTerminal;
    if (head->isTerminal) {
        // Try to start a new word from the root of the Trie
        if (solve(A, ind, orgn, orgn)) return true;
    }
    if (head->chars[A[ind] - 'a']) {
        return solve(A, ind + 1, orgn, head->chars[A[ind] - 'a']);
    }
    return false;
}

bool wordBreak(string A, vector<string>& B) {
    Trie t;
    for(auto& i : B) t.insert(i);
    Node* head = t.head;
    return solve(A, 0, head, head);
}

int main() {
    string A = "imobilelikesamsunggoicecream";
    vector<string> B = {"i", "like", "sams", "sung", "samsung", "mobile", "ice", "icecream", "man", "go", "mango"};
    cout << wordBreak(A, B);
    return 0;
}