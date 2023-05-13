#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int left, int right, int x)
{
    if (left <= right)
    {
        int mid = left + (right - left) / 2;

        // If the element is present at the middle
        if (arr[mid] == x)
        {
            cout << "We traverse on index: " << mid << endl;
            return mid;
        }

        // If element is smaller than mid
        if (arr[mid] > x)
        {
            cout << "We traverse on index: " << mid << endl;
            return binarySearch(arr, left, mid - 1, x);
        }

        // Else the element is in right subarray
        cout << "We traverse on index: " << mid << endl;
        return binarySearch(arr, mid + 1, right, x);
    }

    // We reach here when element is not present in array
    return -1;
}