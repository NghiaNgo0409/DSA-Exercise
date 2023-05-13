#include <bits/stdc++.h>
using namespace std;

int sumOfMaxSubarray(vector<int> &nums, int k)
{
    // STUDENT ANSWER
    int n = nums.size();
    deque<int> dq;

    for (int i = 0; i < k; i++)
    {
        while (!dq.empty() && nums[i] >= nums[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    int sum = nums[dq.front()];

    for (int i = k; i < n; i++)
    {
        if (!dq.empty() && dq.front() <= i - k)
        {
            dq.pop_front();
        }
        while (!dq.empty() && nums[i] >= nums[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);
        sum += nums[dq.front()];
    }

    return sum;
}