#include <iostream>

using namespace std;

int binarySearch(int arr[], int size, int key)
{
    // time complexity = O(logn)

    int start = 0;
    int end = size - 1;

    // int mid = (start + end) / 2;
    int mid = start + (end-start) / 2;  // optimisation : as int has a range of 2^31-1, so that value of mid does not cross this range

    while (start <= end)
    {
        if (arr[mid] == key)
        {
            return mid;
        }

        // go to right part
        if (key > arr[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }

        mid = start + (end-start) / 2;
    }
    return -1;
}

int main()
{
    int even[6] = {2, 4, 6, 8, 12, 18};
    int odd[5] = {3, 8, 11, 14, 16};

    int index = binarySearch(even, 6, 18);
    cout << "The index of 18 is " << index << endl;

    index = binarySearch(odd, 5, 3);
    cout << "The index of 3 is " << index << endl;

    return 0;
}