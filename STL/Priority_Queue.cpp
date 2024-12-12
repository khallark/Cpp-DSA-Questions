#include <iostream>
#include <queue>
using namespace std;
int main() {
    // max heap (default)
    priority_queue<int> max;

    // mini heap 
    priority_queue<int, vector<int>, greater<int>>mini;

    max.push(2);
    max.push(4);
    max.push(6);
    max.push(1);
    max.push(9);
    max.push(10);
    max.push(23);

    mini.push(2);
    mini.push(4);
    mini.push(6);
    mini.push(1);
    mini.push(9);
    mini.push(10);
    mini.push(23);

    int j = max.size();
    int k = mini.size();

    for (int i = 0; i < j; i++)
    {
        cout << max.top() << " ";
        max.pop();
    }

    cout << endl;
    for (int i = 0; i < j; i++)
    {
        cout << mini.top() << " ";
        mini.pop();
    }
    return 0;
}
