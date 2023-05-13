#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define SEPARATOR "#<ab@17943918#@>#"
template <class T>
class Heap
{
protected:
    T *elements;
    int capacity;
    int count;

public:
    Heap()
    {
        this->capacity = 10;
        this->count = 0;
        this->elements = new T[capacity];
    }
    ~Heap()
    {
        delete[] elements;
    }
    void push(T item);

    bool isEmpty();
    bool contains(T item);
    T peek();
    bool pop();
    int size();

    void printHeap()
    {
        cout << "Max Heap [ ";
        for (int i = 0; i < count; i++)
            cout << elements[i] << " ";
        cout << "]\n";
    }

private:
    void ensureCapacity(int minCapacity);
    void reheapUp(int position);
    void reheapDown(int position);
};
// Your code goes here

template <class T>
int Heap<T>::size()
{
    return count;
}

template <class T>
bool Heap<T>::isEmpty()
{
    return count == 0;
}

template <class T>
T Heap<T>::peek()
{
    if (isEmpty())
        return -1;
    return elements[0];
}

template <class T>
bool Heap<T>::contains(T item)
{
    for (int i = 0; i < count; i++)
    {
        if (elements[i] == item)
            return true;
    }
    return false;
}

template <class T>
bool Heap<T>::pop()
{
    if (isEmpty())
        return false;
    elements[0] = elements[count - 1];
    count--;
    reheapDown(0);
    return true;
}