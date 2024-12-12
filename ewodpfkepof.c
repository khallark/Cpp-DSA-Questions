#include <stdio.h>
int main() {
    int sum = 0;
    for (int i = 'a'; i <= 'z'; i++)
    {
        sum += i;
    }
    printf("%d", sum);
    return 0;
}