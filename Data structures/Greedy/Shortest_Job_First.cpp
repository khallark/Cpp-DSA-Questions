#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

double SJF_CPU_SCHEDULING(vector<int> &jobs) {
    sort(jobs.begin(), jobs.end());
    int waiting_time = 0;
    int total_waiting_process = 0;
    for(auto i : jobs) {
        total_waiting_process += waiting_time;
        waiting_time += i;
    }
    return (double(total_waiting_process) / jobs.size());
}

int main() {
    vector<int> jobs = {4, 3, 7, 1, 2};
    cout << SJF_CPU_SCHEDULING(jobs);
    return 0;
}