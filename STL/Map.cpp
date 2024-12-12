#include <iostream>
#include <map>
using namespace std;
int main() {
    map<string , int> m;
    m["Dipanshu"] = 16;
    m["Kunal"] = 19;
    m["Rohit"] = 19;
    m["Rahul"] = 23;
    m.insert({"Kusum", 43});
    for(auto i:m) {
        cout << i.first << " " << i.second << endl;
    }
    m.erase("Kusum");
    cout << endl;
    for(auto i:m) {
        cout << i.first << " " << i.second << endl;
    }
    cout << endl;
    auto it = m.find("Kunal");
    while (it != m.end())
    {
        cout << (*it).first << " ";
        it++;
    }
}