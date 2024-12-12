#include <stdio.h>
#include <math.h>
int reverseint(int x) {
    int newNum = 0;
    int i = 1;
    while(x / i >= 10) {
        i *= 10;
    }
    // printf("%d\n", x);
    while(x > 0) {
        newNum += (x % 10) * i;
        // printf("%d\n", newNum);
        i /= 10;
        x /= 10;
    }
    return newNum;
}
int main() {
    int x = 321;
    printf("%d", reverseint(x));
    return 0;
}