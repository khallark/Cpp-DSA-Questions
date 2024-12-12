#include <iostream>
#include <queue>
using namespace std;
class median {
    priority_queue<int> max;
    priority_queue<int, vector<int>, greater<int>> min;
    double median = 0;
    int signum(int a, int b) {
        if(a == b) return 0;
        if(a > b) return 1;
        if(a < b) return -1;
    }
public:
    double find_median(int num) {
        switch(signum(max.size(), min.size())) {
        case 0:
            if(num > median) {
                min.push(num);
                median = min.top();
            }
            else {
                max.push(num);
                median = max.top();
            }
            break;
        case 1:
            if(num > median) {
                min.push(num);
            }
            else {
                min.push(max.top());
                max.pop();
                max.push(num);
            }
            median = (max.top() + min.top()) / 2.0;
            break;
        case -1:
            if(num > median) {
                max.push(min.top());
                min.pop();
                min.push(num);
            }
            else {
                max.push(num);
            }
            median = (max.top() + min.top()) / 2.0;
            break;
        }
        return median;
    }
};
int main() {
    vector<double> medians;
    median m;
    cout << m.find_median(5) << "  ";
    cout << m.find_median(10) << "  ";
    cout << m.find_median(15) << "  ";
    return 0;
}