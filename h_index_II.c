#include <stdio.h>
int hIndex(int* citations, int citationsSize) {
    if (citations[citationsSize - 1] == 0) return 0;
    int s = 0;
    int e = citationsSize - 1;
    int mid = s + (e - s) / 2;
    int dist = 0;
    while(1) {
        dist = e - s + 1;
        if (citations[s] == dist) {
            return dist;
        }
        else if (citations[s] > dist) {
            int diff = citations[s] - dist;
            int i = 1;
            while (i <= diff) {
                if (s != 0 && citations[s - i] >= dist + 1) {
                    dist++;
                }
                else {
                    return dist;
                }
                i++;
            }
            break;
        }
        s = mid + 1;
        mid = s + (e - s) / 2;
    }
    return dist;
}
int main() {
    int arr[] = {0};
    int size = sizeof(arr) / sizeof(int);
    printf("%d", hIndex(arr, size));
    return 0;
}