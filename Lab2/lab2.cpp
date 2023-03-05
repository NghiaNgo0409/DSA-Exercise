#include <iostream>
#include "SLL.h"
#include "Queue.h"
using namespace std;
int main()
{
    Queue<int> queue;
    for (int i = 0; i < 10; i++)
    {
        queue.push(i);
    }
    queue.print();
    cout << queue.size() << endl;
    cout << queue.pop() << endl;
    cout << queue.size() << endl;
    queue.print();
    cout << queue.peek() << endl;
    queue.remove(5);
    queue.print();
    // zxcxz
}