#include <bits/stdc++.h>
using namespace std;

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
    void printHeap()
    {
        cout << "Max Heap [ ";
        for (int i = 0; i < count; i++)
            cout << elements[i] << " ";
        cout << "]";
    }

private:
    void ensureCapacity(int minCapacity);
    void reheapUp(int position);
};

// Your code here
template <class T>
void Heap<T>::push(T item)
{
    if (count == capacity)
        ensureCapacity(capacity * 2);
    elements[count++] = item;
    reheapUp(count - 1);
}

template <class T>
void Heap<T>::ensureCapacity(int minCapacity)
{
    T *oldElements = elements;
    elements = new T[minCapacity];
    memcpy(elements, oldElements, count * sizeof(T));
    capacity = minCapacity;
    delete[] oldElements;
}

template <class T>
void Heap<T>::reheapUp(int position)
{
    int parent = (position - 1) / 2;
    T temp = elements[position];
    while (position > 0 && temp > elements[parent])
    {
        elements[position] = elements[parent];
        position = parent;
        parent = (position - 1) / 2;
    }
    elements[position] = temp;
}