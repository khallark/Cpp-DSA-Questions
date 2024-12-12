#include <stdio.h>
int isPossibleSol(int *weights, int weightsSize, int days, int mid) {
    int sum = 0;
    int i = 0;
    while(days != 0) {
        sum += weights[i];
        if (sum > mid) {
            sum = 0;
            i--;
            days--;
        }
        i++;
        if (i == weightsSize && days != 0) {
            return 1;
        }
    }
    return 0;
}
int allocateBooks(int *weights, int weightsSize, int days) {
    if (days > weightsSize) return -1;
    int s = 0;
    int e = 0;
    int ans = -1;
    for (int i = 0; i < weightsSize; i++) {
        e += weights[i];
    }
    int mid = s + (e - s) / 2;
    while(s <= e) {
        if(isPossibleSol(weights, weightsSize, days, mid)) {
            ans = mid;
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}
int main() {
    int weights[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int weightsSize = sizeof(weights) / sizeof(int);
    int days = 5;
    int minOfMax = allocateBooks(weights, weightsSize, days);
    printf("%d", minOfMax);
    return 0;
}