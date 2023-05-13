#include <bits/stdc++.h>
using namespace std;
bool isValidParentheses(string s)
{
    /*TODO*/
    stack<char> stk;
    for (char c : s)
    {
        if (c == '(' || c == '{' || c == '[')
        {
            stk.push(c);
        }
        else
        {
            if (stk.empty())
            {
                return false;
            }
            char top = stk.top();
            stk.pop();
            if ((c == ')' && top != '(') || (c == '}' && top != '{') || (c == ']' && top != '['))
            {
                return false;
            }
        }
    }
    return stk.empty();
}