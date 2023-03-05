#ifndef SLL_H
#define SLL_H

#include "D:\Study\DSC\dsaframework\dsacpp\include\list\IList.h"
#include <string>
using namespace std;
template <class T>
class SLL : public IList<T>
{
public:
    class Node;

protected:
    Node *head;
    Node *tail;
    int length;

public:
    SLL();
    ~SLL();
    void add(T e);
    void add(int index, T e);
    T removeAt(int index);
    bool removeItem(T item, void (*removeItemData)(T) = 0);
    bool empty();
    int size();
    void clear();
    T &get(int index);
    int indexOf(T item);
    bool contains(T item);
    void print();
    string toString(string (*item2str)(T &));

    class Node
    {
    private:
        T data;
        Node *next;
        friend class SLL<T>;

    public:
        Node()
        {
            next = nullptr;
        }
        Node(T data, Node *next = nullptr)
        {
            this->data = data;
            this->next = next;
        }
    };
};

template <class T>
SLL<T>::SLL()
{
    head = nullptr;
    tail = nullptr;
    length = 0;
}

template <class T>
SLL<T>::~SLL()
{
    clear();
}

template <class T>
void SLL<T>::add(T e)
{
    Node *newNode = new Node(e);
    if (head == nullptr && tail == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
    length++;
}

template <class T>
void SLL<T>::add(int index, T e)
{
    if (index < 0 || index > length)
    {
        __throw_out_of_range("Index is out of range");
    }
    else
    {
        Node *newNode = new Node(e);
        if (index == 0)
        {
            if (head != nullptr)
            {
                newNode->next = head;
            }
            head = newNode;
        }
        else if (index == length)
        {
            tail->next = newNode;
            tail = newNode;
        }
        else
        {
            Node *tmp = head;
            int count = 0;
            while (count != index - 1)
            {
                tmp = tmp->next;
                count++;
            }
            newNode->next = tmp->next;
            tmp->next = newNode;
        }
        length++;
    }
}

template <class T>
T SLL<T>::removeAt(int index)
{
    if (index < 0 || index >= length)
    {
        __throw_out_of_range("Index is out of range");
    }
    else
    {
        if (index == 0)
        {
            if (head == nullptr)
            {
                __throw_out_of_range("List is empty");
            }
            else
            {
                Node *deleteNode = head;
                T removeData = deleteNode->data;
                head = head->next;
                delete deleteNode;
                length--;
                return removeData;
            }
        }
        else
        {
            if (head == nullptr || tail == nullptr)
            {
                __throw_out_of_range("List is empty");
            }
            else
            {
                Node *tmp = head;
                int count = 0;
                while (count != index - 1)
                {
                    tmp = tmp->next;
                    count++;
                }
                Node *deleteNode = tmp->next;
                T removeData = deleteNode->data;
                tmp->next = tmp->next->next;
                delete deleteNode;
                length--;
                return removeData;
            }
        }
    }
}
template <class T>
bool SLL<T>::removeItem(T item, void (*removeItemData)(T))
{
    return false;
}

template <class T>
bool SLL<T>::empty()
{
    return length == 0;
}

template <class T>
int SLL<T>::size()
{
    return this->length;
}

template <class T>
void SLL<T>::clear()
{
    Node *deleteNode;
    while (head != nullptr)
    {
        deleteNode = head;
        head = head->next;
        delete deleteNode;
    }
    length = 0;
}

template <class T>
T &SLL<T>::get(int index)
{
    Node *tmp = head;
    int count = 0;
    if (index < 0 || index >= length)
    {
        __throw_out_of_range("Index out of range");
    }
    while (count != index)
    {
        tmp = tmp->next;
        count++;
    }
    return tmp->data;
}

template <class T>
int SLL<T>::indexOf(T item)
{
    Node *tmp = head;
    int count = 0;
    while (tmp != nullptr && tmp->data != item)
    {
        tmp = tmp->next;
        count++;
    }
    if (tmp != nullptr)
    {
        return count;
    }
    return -1;
}

template <class T>
bool SLL<T>::contains(T item)
{
    return indexOf(item) != -1;
}

template <class T>
void SLL<T>::print()
{
    Node *tmp = head;
    while (tmp != nullptr)
    {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

template <class T>
string SLL<T>::toString(string (*item2str)(T &))
{
    return "";
}
#endif SLL_H