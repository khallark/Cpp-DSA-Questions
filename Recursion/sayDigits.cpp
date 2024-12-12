#include <iostream>
#include <vector>
using namespace std;
void sayDigits(int x) {
    vector<string> nums = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    if(x < 10) {
        cout << nums[x] << " ";
        return;
    }
    sayDigits(x / 10);
    cout << nums[x % 10] << " ";
}
int main() {
    int x = 100000000;
    sayDigits(x);
}