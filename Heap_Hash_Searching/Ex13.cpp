#include <bits/stdc++.h>
using namespace std;

int reduceSum(vector<int> &nums)
{
    // STUDENT ANSWER
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int num : nums)
    {
        minHeap.push(num);
    }

    int totalCost = 0;
    while (minHeap.size() > 1)
    {
        // Remove the two smallest elements from the minHeap
        int a = minHeap.top();
        minHeap.pop();
        int b = minHeap.top();
        minHeap.pop();

        // Calculate the sum and add it to the minHeap
        int sum = a + b;
        minHeap.push(sum);

        // Add the cost of the operation to the total cost
        totalCost += sum;
    }

    return totalCost;
}