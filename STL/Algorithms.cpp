#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 4, 4, 5, 7, 8, 9};

    auto it = std::upper_bound(vec.begin(), vec.end(), 4);

    std::cout << "Upper bound of 4 is at position: " << std::lower_bound(vec.begin(), vec.end(), 4) - vec.begin() << std::endl;

    return 0;
}