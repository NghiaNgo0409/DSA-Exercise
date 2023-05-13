#include <iostream>
#include <stack>
#include <utility>
using namespace std;
template <typename Iterator>
void reverse(Iterator begin, Iterator end)
{
    while (begin < end)
    {
        std::swap(*begin++, *--end);
    }
}

string deleteDuplicate(string s, int k)
{
    stack<pair<char, int>> st;
    for (char c : s)
    {
        if (st.empty() || st.top().first != c)
        {
            st.push(make_pair(c, 1));
        }
        else
        {
            st.top().second++;
            if (st.top().second == k)
            {
                st.pop();
            }
        }
    }
    string res;
    while (!st.empty())
    {
        auto p = st.top();
        st.pop();
        for (int i = 0; i < p.second; i++)
        {
            res.push_back(p.first);
        }
    }
    reverse(res.begin(), res.end());
    return res;
}
