#include <bits/stdc++.h>
using namespace std;

// iostream and queue are included
// Hint: Use a queue to simulate the process

int numberOfTheWinner(int N, int k)
{
    queue<int> q;
    for (int i = 1; i <= N; i++)
    {
        q.push(i);
    }
    while (q.size() > 1)
    {
        for (int i = 1; i < k; i++)
        {
            q.push(q.front());
            q.pop();
        }
        q.pop();
    }
    return q.front();
}