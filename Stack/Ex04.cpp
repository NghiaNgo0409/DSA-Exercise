#include <iostream>
#include <stack>
#include <queue>
#include <string>

using namespace std;

string removeDuplicate(string S)
{
    stack<char> q;
    string result;
    for (unsigned int i = 0; i < S.size(); i++)
    {
        if (!q.empty() && q.top() == S[i])
        {
            q.pop();
        }
        else
        {
            q.push(S[i]);
        }
    }
    while (!q.empty())
    {
        result += q.top();
        q.pop();
    }
    // Reverse string result
    stack<char> reverse_s;
    for (unsigned int i = 0; i < result.size(); i++)
    {
        reverse_s.push(result[i]);
    }
    string result_reverse;
    while (!reverse_s.empty())
    {
        result_reverse += reverse_s.top();
        reverse_s.pop();
    }
    return result_reverse;
}

int main()
{
    string s = "aab";
    cout << removeDuplicate(s);
}