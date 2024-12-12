#include <iostream>
#include <vector>
#include "AAASingly_LL.h"
using namespace std;
int main() {
    LinkedList<LinkedList<int>*> l;
    vector<int> arr;
    int N, n;
    cout << endl << "Enter the numbers of nodes --> ";
    cin >> N;
    cout << endl;
    for(int i = 0; i < N; i++) {
        cout << i + 1 << ")" << "Enter the number of sub-nodes --> ";
        cin >> n;
        arr.push_back(n);
        LinkedList<int> *SubList = new LinkedList<int>;
        l.addEnd(SubList);
        for(int j = 0; j < n; j++) {
            cout << "  Enter element" << " (" << i << ", " << j << ") --> ";
            int num;
            cin >> num;
            SubList->addEnd(num);
        }
    }
    cout << endl << "Here's the Jagged Linked List :" << endl;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < arr[i]; j++) {
            cout << (*l[i])[j] << " ";
        }
        cout << endl;
    }
    for(int i = 0; i < N; i++) {
        delete l[i];
    }
    cout << endl;
    return 0;
}