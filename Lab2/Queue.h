#ifndef QUEUE_H
#define QUEUE_H

#include "D:\Study\DSC\dsaframework\dsacpp\include\stacknqueue\IDeck.h"
#include "SLL.h"
using namespace std;

template <class T>
class Queue : public IDeck<T>
{
protected:
    SLL<T> list;

public:
    Queue();
    ~Queue();
    void push(T item);
    T pop();
    T &peek();
    bool empty();
    int size();
    void clear();
    bool remove(T item);
    bool contains(T item);
    void print();
    string toString(string (*item2str)(T &));
};

template <class T>
Queue<T>::Queue()
{
}

template <class T>
Queue<T>::~Queue()
{
    list.clear();
}

template <class T>
void Queue<T>::push(T item)
{
    list.add(item);
}

template <class T>
T Queue<T>::pop()
{
    return list.removeAt(0);
}

template <class T>
T &Queue<T>::peek()
{
    return list.get(0);
}

template <class T>
bool Queue<T>::empty()
{
    return list.empty();
}

template <class T>
int Queue<T>::size()
{
    return list.size();
}

template <class T>
void Queue<T>::clear()
{
    list.clear();
}

template <class T>
bool Queue<T>::remove(T item)
{
    if (!list.contains(item))
    {
        return false;
    }
    else
    {
        return list.removeAt(list.indexOf(item));
    }
}

template <class T>
bool Queue<T>::contains(T item)
{
    return list.contains(item);
}

template <class T>
void Queue<T>::print()
{
    list.print();
}

template <class T>
string Queue<T>::toString(string (*item2str)(T &))
{
    return "";
}
#endif QUEUE_H