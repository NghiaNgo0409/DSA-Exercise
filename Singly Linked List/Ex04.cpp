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
    head = new Node(0);
    tail = new Node(0);
    head->next = tail;
    tail->next = head;
}

template <class T>
void SLinkedList<T>::add(T e)
{
    Node *newNode = new Node(e, tail);
    tail->next->next = newNode;
    tail->next = newNode;
}

template <class T>
int SLinkedList<T>::size()
{
    Node *tmp = head->next;
    int count = 0;
    while (tmp != tail)
    {
        count++;
        tmp = tmp->next;
    }
    return count;
}

template <class T>
void SLinkedList<T>::print()
{
    Node *tmp = head->next;
    while (tmp != tail)
    {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

int main()
{
    SLinkedList<int> *list = new SLinkedList<int>();
    list->add(10);
    list->print();
    cout << list->size();
}