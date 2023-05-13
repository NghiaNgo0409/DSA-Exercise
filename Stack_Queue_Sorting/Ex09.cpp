#include <bits/stdc++.h>
using namespace std;
// iostream, vector and queue are included
// You can write helper methods

long long nthNiceNumber(int n)
{
    queue<string> q;
    q.push("2");
    q.push("5");
    string num;
    for (int i = 1; i <= n; i++)
    {
        num = q.front();
        q.pop();
        q.push(num + "2");
        q.push(num + "5");
    }

    long long res = stoll(num);

    return res;
}