#include <iostream>
using namespace std;

int findDuplicate(int *arr, int size)
{
    int requiredSum = 0, actualSum = 0;
    for (int i = 0; i < size; i++)
    {
        requiredSum += i + 1 < size ? i + 1 : 0;
        actualSum += arr[i];
    }
    return actualSum - requiredSum;
}

int main()
{
    int arr[] = {1,9,3,7,4,1,2,6,8,5};
    int size = sizeof(arr) / sizeof(int);
    int a = findDuplicate(arr, size);
    cout << a << endl;
    return 0;
}