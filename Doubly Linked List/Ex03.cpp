#include <iostream>
using namespace std;

template <class T>
class DLinkedList
{
public:
    class Node; // Forward declaration
protected:
    Node *head;
    Node *tail;
    int count;

public:
    DLinkedList();
    ~DLinkedList();
    void add(const T &e);
    void add(int index, const T &e);
    int size();
    bool empty();
    T get(int index);
    void set(int index, const T &e);
    int indexOf(const T &item);
    bool contains(const T &item);
    void print();

public:
    class Node
    {
    private:
        T data;
        Node *next;
        Node *previous;
        friend class DLinkedList<T>;

    public:
        Node()
        {
            this->previous = NULL;
            this->next = NULL;
        }

        Node(const T &data)
        {
            this->data = data;
            this->previous = NULL;
            this->next = NULL;
        }
    };
};

template <class T>
DLinkedList<T>::DLinkedList()
{
    head = nullptr;
    tail = nullptr;
    count = 0;
}

template <class T>
DLinkedList<T>::~DLinkedList()
{
    while (head != nullptr)
    {
        Node *tmp = head;
        head = head->next;
        delete tmp;
    }
    tail = nullptr;
    count = 0;
}

template <class T>
void DLinkedList<T>::add(const T &e)
{
    Node *currentNode = new Node(e);
    if (head == nullptr && tail == nullptr)
    {
        head = currentNode;
        tail = currentNode;
    }
    else
    {
        tail->next = currentNode;
        currentNode->previous = tail;
        tail = currentNode;
    }
    count++;
}

template <class T>
void DLinkedList<T>::add(int index, const T &e)
{
    if (index < 0 || index > count)
    {
        return;
    }
    else
    {
        Node *currentNode = new Node(e);
        if (index == 0)
        {
            if (head == nullptr && tail == nullptr)
            {
                head = currentNode;
                tail = currentNode;
            }
            else
            {
                head->previous = currentNode;
                currentNode->next = head;
                head = currentNode;
            }
        }
        else if (index == count)
        {
            currentNode->previous = tail;
            if (tail != nullptr)
            {
                tail->next = currentNode;
            }
            else
            {
                head = currentNode;
            }
            tail = currentNode;
        }
        else
        {
            int pos = 0;
            Node *tmp = head;
            while (pos != index)
            {
                pos++;
                tmp = tmp->next;
            }
            currentNode->previous = tmp->previous;
            (tmp->previous)->next = currentNode;
            currentNode->next = tmp;
            tmp->previous = currentNode;
        }
        count++;
    }
}

template <class T>
int DLinkedList<T>::size()
{
    return count;
}

template <class T>
bool DLinkedList<T>::empty()
{
    return count == 0;
}

template <class T>
T DLinkedList<T>::get(int index)
{
    if (index < 0 || index > count)
    {
        throw std::out_of_range("Index out of range");
    }
    Node *tmp = head;
    int pos = 0;
    while (pos != index)
    {
        pos++;
        tmp = tmp->next;
    }
    return tmp->data;
}

template <class T>
void DLinkedList<T>::set(int index, const T &e)
{
    if (index < 0 || index > count)
    {
        throw std::out_of_range("Index out of range");
    }
    Node *tmp = head;
    int pos = 0;
    while (pos != index)
    {
        pos++;
        tmp = tmp->next;
    }
    tmp->data = e;
}

template <class T>
int DLinkedList<T>::indexOf(const T &item)
{
    if (head == nullptr && tail == nullptr)
    {
        return -1;
    }
    Node *tmp = head;
    int pos = 0;
    while (tmp != nullptr)
    {
        if (tmp->data == item)
        {
            return pos;
        }
        pos++;
        tmp = tmp->next;
    }
    return -1;
}

template <class T>
bool DLinkedList<T>::contains(const T &item)
{
    return indexOf(item) != -1;
}

template <class T>
void DLinkedList<T>::print()
{
    Node *tmp = head;
    while (tmp != nullptr)
    {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

int main()
{
}