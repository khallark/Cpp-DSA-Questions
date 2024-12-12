#include <iostream>
using namespace std;
#define PI 3.14
#define MAX(a, b) (a > b ? a : b)
#define MIN(a, b) (a < b ? a : b)
#define AREAS CIRCLE
#define CIRCLE(r) (PI * r * r)
#define RECTANGLE(l, b) (l * b)
#define TRIANGLE(b, h) (0.5 * b * h)
#define ELE 1, \
            2, \
            3
#define GCD_MACRO(a, b) \
    ({ \
        int temp; \
        while (b != 0) { \
            temp = b; \
            b = a % b; \
            a = temp; \
        } \
        a; \
    })
int main() {
    int arr[] = {ELE};
    cout << AREAS(4) << endl;
    return 0;
}
