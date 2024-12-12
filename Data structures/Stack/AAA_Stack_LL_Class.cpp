#include <iostream>
#include "C:\Users\ABC\Documents\C++\Data structures\Linked List\AAASingly_LL.cpp"
using namespace std;
template <typename DataType>
class stack {
    int topIndx = -1;
    LinkedList<DataType> l;
    int MaxSize = 0;
public:
    stack() {};
    stack(int MaxSize) : MaxSize(MaxSize) {};
    
    void push(const DataType& data) {
        if(topIndx == MaxSize - 1) return;
        topIndx++;
        l.addEnd(data);
    }

    DataType pop() {
        if(topIndx == -1) return -1;
        topIndx--;
        DataType val = l.getTail()->data;
        l.deleteEnd();
        return val;
    }

    DataType top() {
        if(topIndx == -1) return -1;
        return l.getTail()->data;
    }

    bool empty() {
        return l.getTail() == nullptr;
    }

    int size() {
        return topIndx + 1;
    }
};