#include <bits/stdc++.h>
using namespace std;

int leastAfter(vector<int> &nums, int k)
{
    // STUDENT ANSWER
    priority_queue<int, vector<int>, greater<int>> minHeap(nums.begin(), nums.end());
    for (int i = 0; i < k; i++)
    {
        int minElement = minHeap.top();
        minHeap.pop();
        minHeap.push(minElement * 2);
    }
    return minHeap.top();
}