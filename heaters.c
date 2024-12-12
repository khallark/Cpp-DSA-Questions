#include <stdio.h>
#include <stdlib.h>
int findRadius(int* houses, int housesSize, int* heaters, int heatersSize) {
    
}
int main() {
    int houses[] = {432, 567, 632, 654, 765, 789, 947};
    int housesSize = sizeof(houses) / sizeof(int);
    int heaters = {567, 646, 835, 867, 1001};
    int heatersSize = sizeof(heaters) / sizeof(int);
    printf("%d", findRadius(houses, housesSize, heaters, heatersSize));
    return 0;
}