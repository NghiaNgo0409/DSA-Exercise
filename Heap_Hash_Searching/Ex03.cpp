#include <bits/stdc++.h>
using namespace std;
int pairMatching(vector<int> &nums, int target)
{
    std::unordered_map<int, int> count;
    int pairs = 0;
    for (int num : nums)
    {
        int complement = target - num;
        if (count[complement] > 0)
        {
            pairs++;
            count[complement]--;
        }
        else
        {
            count[num]++;
        }
    }
    return pairs;
}