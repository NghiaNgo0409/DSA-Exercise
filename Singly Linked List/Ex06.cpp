#include <iostream>

using namespace std;

template <class T>
class SLinkedList
{
public:
    class Node; // Forward declaration
protected:
    Node *head;
    Node *tail;
    int count;

public:
    SLinkedList();
    ~SLinkedList();
    void add(T e);
    void add(int index, T e);
    int size();
    void clear();
    bool empty();
    T get(int index);
    void set(int index, T e);
    int indexOf(T item);
    bool contains(T item);
    T removeAt(int index);
    bool removeItem(T item);
    void print();

public:
    class Node
    {
    private:
        T data;
        Node *next;
        friend class SLinkedList<T>;

    public:
        Node()
        {
            next = 0;
        }
        Node(Node *next)
        {
            this->next = next;
        }
        Node(T data, Node *next)
        {
            this->data = data;
            this->next = next;
        }
    };
};

template <class T>
SLinkedList<T>::SLinkedList()
{
    head = nullptr;
    tail = nullptr;
    count = 0;
}
template <class T>
SLinkedList<T>::~SLinkedList()
{
    Node *current = head;
    while (current != nullptr)
    {
        Node *next = current->next;
        delete current;
        current = next;
    }
}

template <class T>
void SLinkedList<T>::add(T e)
{
    Node *newNode = new Node(e, nullptr);
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
    count++;
}

template <class T>
void SLinkedList<T>::add(int index, T e)
{
    if (index < 0 || index > size())
    {
        return;
    }
    else
    {
        Node *newNode = new Node(e, 0);
        if (index == 0)
        {
            if (head == nullptr && tail == nullptr)
            {
                head = newNode;
                tail = newNode;
            }
            else
            {
                newNode->next = head;
                head = newNode;
            }
        }
        else if (index == size())
        {
            add(newNode->data);
            return;
        }
        else
        {
            int i = 0;
            Node *tmp = head;
            while (i < index - 1)
            {
                tmp = tmp->next;
                i++;
            }
            newNode->next = tmp->next;
            tmp->next = newNode;
        }
        count++;
    }
}

template <class T>
int SLinkedList<T>::size()
{
    return count;
}

template <class T>
void SLinkedList<T>::clear()
{
    if (head == nullptr && tail == nullptr)
        return;
    Node *tmp = head;
    while (tmp != nullptr)
    {
        Node *next = tmp->next;
        delete tmp;
        tmp = next;
    }
}

template <class T>
bool SLinkedList<T>::empty()
{
    return count == 0;
}

template <class T>
T SLinkedList<T>::get(int index)
{
    if (index < 0 || index >= size())
        throw std::out_of_range("Index out of range");
    Node *tmp = head;
    for (int i = 0; i < index; i++)
    {
        tmp = tmp->next;
    }
    return tmp->data;
}

template <class T>
void SLinkedList<T>::set(int index, T e)
{
    if (index < 0 || index >= size())
        throw std::out_of_range("Index out of range");
    Node *tmp = head;
    for (int i = 0; i < index; i++)
    {
        tmp = tmp->next;
    }
    tmp->data = e;
}

template <class T>
int SLinkedList<T>::indexOf(T item)
{
    Node *tmp = head;
    int i = 0;
    while (tmp != nullptr)
    {
        if (tmp->data == item)
            return i;
        tmp = tmp->next;
        i++;
    }
    return -1;
}

template <class T>
bool SLinkedList<T>::contains(T item)
{
    return indexOf(item) != -1;
}

template <class T>
T SLinkedList<T>::removeAt(int index)
{
    if (count == 0)
    {
        throw std::out_of_range("List is empty");
    }
    else
    {
        Node *tmp = head;
        if (index == 0)
        {
            T data = head->data;
            head = head->next;
            delete tmp;
            count--;
            return data;
        }
        else
        {
            for (int i = 0; i < index - 1; i++)
            {
                tmp = tmp->next;
            }
            T data = tmp->next->data;
            Node *current = tmp->next;
            if (index == count - 1)
            {
                tmp->next = nullptr;
                tail = tmp;
            }
            else
            {
                tmp->next = tmp->next->next;
            }
            delete current;
            count--;
            return data;
        }
    }
}

template <class T>
bool SLinkedList<T>::removeItem(T item)
{
    int index = indexOf(item);
    if (index == -1)
    {
        return false;
    }
    else
    {
        removeAt(index);
        return true;
    }
}

template <class T>
void SLinkedList<T>::print()
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
    SLinkedList<int> list;

    for (int i = 0; i < 10; i++)
    {
        list.add(i);
    }
    list.removeItem(9);
    list.print();
}