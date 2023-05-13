#include <bits/stdc++.h>
using namespace std;

int sumOfMinSubarray(vector<int> &nums)
{
    // STUDENT ANSWER
    const int mod = 10000;
    int n = nums.size();
    stack<int> s;
    vector<int> left(n), right(n);
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && nums[s.top()] >= nums[i])
        {
            s.pop();
        }
        left[i] = (s.empty() ? -1 : s.top());
        s.push(i);
    }
    while (!s.empty())
    {
        s.pop();
    }
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && nums[s.top()] >= nums[i])
        {
            s.pop();
        }
        right[i] = (s.empty() ? n : s.top());
        s.push(i);
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int len = (i - left[i]) * (right[i] - i);
        sum = (sum + (nums[i] * len) % mod) % mod;
    }
    return sum;
}