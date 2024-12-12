#include <stdio.h>
int isPossibleSol(int* position, int positionSize, int m, int mid) {
    
}
int maxDistance(int* position, int positionSize, int m) {
    int s = 0;
    int e = position[0];
    for (int i = 0; i < positionSize; i++) {
        e = position[i] > e ? position[i] : e;
    }
    int ans = -1;
    int mid = s + (e - s) / 2;
    while(s <= e) {
        if(isPossibleSol(position, positionSize, m, mid)) {
            ans = mid;
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
    }
    return ans;
}
int main() {
    int position[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int positionSize = sizeof(position) / sizeof(int);
    int m = 5;
    int MaxDis = maxDistance(position, positionSize, m);
    printf("%d", MaxDis);
    return 0;
}