#include <bits/stdc++.h>
using namespace std;
int jumpSearch(int arr[], int x, int n)
{
    // TODO: print the traversed indexes and return the index of value x in array if x is found, otherwise, return -1.
    int step = sqrt(n);
    int prev = 0;
    int curr = step;

    // traverse the array using jump steps
    while (arr[min(curr, n) - 1] < x)
    {
        cout << min(prev, n) << " ";
        prev = curr;
        curr += step;
        if (prev >= n)
        {
            return -1; // element not found
        }
    }

    // perform a linear search in the block where the element is found
    while (arr[prev] < x)
    {
        cout << prev << " ";
        prev++;
        if (prev == min(curr, n))
        {
            return -1; // element not found
        }
    }

    // element found
    if (arr[prev] == x)
    {
        cout << prev << " ";
        return prev;
    }

    return -1; // element not found
}