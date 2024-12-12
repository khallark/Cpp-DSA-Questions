#include <iostream>
#include <cmath>
using namespace std;

/*
Problem Statement :
    Given 2 digits, m and n, find the location of the given combination.
Example :
    m = 4, n = 7, num = 474
    output = 11
Explaination :
    4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, (747) -> 11th number
*/

int find_lucky_number(int d1, int d2, int num) {
    string str = to_string(num);
    string bigger_digit = to_string(max(d1, d2));
    int val = (1 << str.length()) - 2;
    for(string s = str; !s.empty(); s = s.substr(1))
        if(s[0] == bigger_digit[0])
            val += 1 << (s.length() - 1);
    return val;
}

int main() {
    cout << find_lucky_number(4, 7, 777777777);
    return 0;
}