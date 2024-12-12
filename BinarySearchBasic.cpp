#include <iostream>
using namespace std;

int BinarySearch(int *arr, int size, int target)
{
    int start = 0;
    int end = size - 1;
    int indx = start + (end - start) / 2;
    while (start <= end)
    {
        if (arr[indx] == target)
        {
           return indx;
        }
        else if (target > arr[indx])
        {
            start = indx + 1;
        }
        else
        {
            end = indx - 1;
        }
        indx = start + (end - start) / 2;
    }
    return -1;
}

int linearSearch(int *arr, int size, int target) {
    for (int i = 0; i < size; i++)
    {
        if(arr[i] == target) return i;
    }
    return -1;
}
int main()
{
    int arr[] = {221,227,230,277,282,306,314,316,321,325,328,336,337,363,365,368,370,370,371,375,384,387,394,400,404,414,422,422,427,430,435,457,493,506,527,531,538,541,546,568,583,585,587,650,652,677,691,730,737,740,751,755,764,778,783,785,789,794,803,809,815,847,858,863,863,874,887,896,916,920,926,927,930,933,957,981,997};
    int size = sizeof(arr) / sizeof(int);
    int a = BinarySearch(arr, size, 321);
    cout << a << endl;
    return 0;
}
