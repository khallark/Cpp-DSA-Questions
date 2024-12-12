#include <iostream>
#include <deque>
#include <vector>
using namespace std;
vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {
    vector<int> v(N, 0);
    int vind = 0;
    vector<long long> ans;
    int i, j;
    for(i = 0; i < K; i++) {
        if(A[i] < 0){
            v[vind++] = A[i];
        }
    }
    j = i - 1;
    i = 0;
    int ind = 0;
    int data = v[ind];
    while(j < N) {
        j++;
        if(A[j] < 0) {
            v[vind++] = A[j]; 
            ans.push_back(data); // Part of proccessing of the current window
            data = v[ind]; // Information being Updated
        }
        else {
            ans.push_back(data); // Part of proccessing of the current window
        }
        if(A[i] == data) {
            data = v[++ind];
        }
        i++;
    }
    return ans;
}
int main() {
    long long int a[] = {1,2,-3};
    long long int size = sizeof(a) / sizeof(long long);
    vector<long long> ans = printFirstNegativeInteger(a, size, 2);
    for(auto i: ans) {
        cout << i << " ";
    }
    return 0;
}