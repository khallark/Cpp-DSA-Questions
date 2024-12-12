#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;
vector<int> SumArr(vector<int> a, int m, vector<int> b, int n) {
    vector<int> c;
    int carry = 0;
    int a_sum = a[m - 1];
    int b_sum = b[n - 1];
    int a_indx = m - 1;
    int b_indx = n - 1;
    while(1) {
        a_sum = a_indx >= 0 ? a[a_indx--] : 0;
        b_sum = b_indx >= 0 ? b[b_indx--] : 0;
        if(a_sum == 0 && b_sum == 0 && carry == 0) {
            break;
        }
        c.push_back((a_sum + b_sum + carry) % 10);
        carry = (a_sum + b_sum + carry) / 10; 
    }
    reverse(c.begin(), c.end());
    return c;
}
int main() {
    vector<int> a = {9,9,9,9,9,9,9,9};
    vector<int> b = {9,9,9,9,9,9};
    vector<int> c = SumArr(a, a.size(), b, b.size());
    for (int i:c)
    {
        cout << i << "";
    }
    // cout << endl << INT_MAX << endl;
    return 0;
}