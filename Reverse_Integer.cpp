#include <iostream>
#include <limits.h>
#include <math.h>
using namespace std;
int reverseInt(int x) {
        if(x == INT_MIN) return 0;
        int maxNum = INT_MAX;
        int newNum = 0;
        int isNegative = x < 0 ? 1 : 0;
        int powOfTen = 1;
        x = x < 0 ? 0 - x : x;
        while(x / powOfTen >= 10) {
            powOfTen *= 10;
        }
        int i2 = powOfTen;
        int a = 0;
        while(x > 0) {
            if(i2 == 1000000000) {
                if(a == 0) {
                    if (x % 10 < (maxNum / powOfTen) % 10) {
                        a = 1;
                    }
                    else if(x % 10 > (maxNum / powOfTen) % 10) {
                        return 0;
                    }
                }
                newNum += (x % 10) * powOfTen;
                maxNum = maxNum % powOfTen;
            }
            else {
                newNum += (x % 10) * powOfTen;
            }
            powOfTen /= 10;
            x /= 10;
        }
        newNum = isNegative == 1 ? 0 - newNum : newNum;
        return newNum;
}
int main() {
    int x = 1563847412;
    cout << reverseInt(x) << endl;
    string s = "Kuna  l";
    cout << s.size() << endl;
    return 0;
}

