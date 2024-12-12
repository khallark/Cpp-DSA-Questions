#include <iostream>
#include <list>
using namespace std;
int main()
{
    list<int> l;
    for (int i = 0; i < 10; i++)
    {
        l.push_back(i);
    }
    while (l.size() != 0)
    {
        for (int i : l)
        {
            cout << i << " ";
        }
        l.erase(l.begin());
        cout << endl;
    }

    return 0;
}