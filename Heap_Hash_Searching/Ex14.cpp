#include <bits/stdc++.h>
using namespace std;

void reheapDown(int maxHeap[], int numberOfElements, int index)
{
    int parent = index;
    int child = 2 * parent + 1; // left child

    while (child < numberOfElements)
    {
        // if right child exists and greater than left child, use it instead
        if (child + 1 < numberOfElements && maxHeap[child] < maxHeap[child + 1])
        {
            child++;
        }

        // if parent is greater than or equal to the larger child, we're done
        if (maxHeap[parent] >= maxHeap[child])
        {
            break;
        }

        // swap parent and child
        int temp = maxHeap[parent];
        maxHeap[parent] = maxHeap[child];
        maxHeap[child] = temp;

        // move down to child level
        parent = child;
        child = 2 * parent + 1;
    }
}

void reheapUp(int maxHeap[], int numberOfElements, int index)
{
    int child = index;
    int parent = (child - 1) / 2;

    while (child > 0 && maxHeap[child] > maxHeap[parent])
    {
        // swap child and parent
        int temp = maxHeap[child];
        maxHeap[child] = maxHeap[parent];
        maxHeap[parent] = temp;

        // move up to parent level
        child = parent;
        parent = (child - 1) / 2;
    }
}