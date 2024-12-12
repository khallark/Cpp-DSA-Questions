#include <iostream>
#include <vector>
#include <deque>
using namespace std;
int sumOfKSubarrays(vector<int> v, int k) {
    deque<int> max;
    deque<int> min;
    int sum = 0;
    for(int i = 0; i < k; i++) {
        if(max.empty() || v[i] > v[max.front()]) {
            if(!max.empty()) max.pop_front();
            max.push_back(i);
        }
        if(min.empty() || v[i] < v[min.front()]) {
            if(!min.empty()) min.pop_front();
            min.push_back(i);
        }
    }
    for(int i = k; i < v.size(); i++) {
        sum += v[max.front()] + v[min.front()];
        
    }
}
int main() {
    vector<int> v = {2,5,-1,7,-3,-1,-2};
    cout << sumOfKSubarrays(v, 4) << endl;
}