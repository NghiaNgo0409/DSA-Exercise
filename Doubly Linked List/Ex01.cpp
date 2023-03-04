#include <iostream>
#include <vector>
using namespace std;

class Deque
{
private:
    class Node
    {
    private:
        int value;
        Node *left;
        Node *right;
        friend class Deque;

    public:
        Node(int val = 0, Node *l = nullptr, Node *r = nullptr) : value(val), left(l), right(r) {}
    };

private:
    Node *head;
    Node *tail;
    int curSize;

public:
    Deque();
    ~Deque();
    int getSize();
    void pushFront(int item);
    void pushBack(int item);
    int popFront();
    int popBack();
    void clear();
    void printDequeReverse();
    void printDeque();
};

Deque::Deque()
{
    head = nullptr;
    tail = nullptr;
    curSize = 0;
}

Deque::~Deque()
{
    Node *deleteNode = nullptr;
    while (head != nullptr)
    {
        deleteNode = head;
        head = head->right;
        delete deleteNode;
    }
    tail = nullptr;
    curSize = 0;
}

void Deque::clear()
{
    Node *deleteNode = nullptr;
    while (head != nullptr)
    {
        deleteNode = head;
        head = head->right;
        delete deleteNode;
    }
    tail = nullptr;
    curSize = 0;
}

int Deque::getSize()
{
    return curSize;
}

void Deque::pushFront(int i)
{
    Node *item = new Node(i);
    if (head == nullptr && tail == nullptr)
    {
        head = item;
        tail = item;
    }
    else
    {
        item->right = head;
        head->left = item;
        head = item;
    }
    curSize++;
}

void Deque::pushBack(int i)
{
    Node *item = new Node(i);
    if (head == nullptr && tail == nullptr)
    {
        head = item;
        tail = item;
    }
    else
    {
        item->left = tail;
        tail->right = item;
        tail = item;
    }
    curSize++;
}

int Deque::popFront()
{
    if (head == nullptr)
        return -1;
    Node *item = head;
    int itemValue = head->value;
    head = head->right;
    if (head != nullptr)
    {
        head->left = nullptr;
    }
    else
    {
        tail = nullptr;
    }
    delete item;
    curSize--;
    return itemValue;
}

int Deque::popBack()
{
    if (tail == nullptr)
        return -1;
    Node *item = tail;
    int itemValue = tail->value;
    tail = tail->left;
    if (tail != nullptr)
    {
        tail->right = nullptr;
    }
    else
    {
        head = nullptr;
    }
    delete item;
    curSize--;
    return itemValue;
}

void Deque::printDeque()
{
    Node *tmp = head;
    while (tmp != nullptr)
    {
        cout << tmp->value << " ";
        tmp = tmp->right;
    }
    cout << endl;
}

void Deque::printDequeReverse()
{
    Node *tmp = tail;
    while (tmp != nullptr)
    {
        cout << tmp->value << " ";
        tmp = tmp->left;
    }
    cout << endl;
}

int main()
{
    Deque *deque = new Deque();
    vector<int> arr = {223, 1234, 43, 568, 90, 193, 2109};
    for (int i = 0; i < (int)arr.size(); i++)
    {
        if (i < (int)arr.size() / 2)
            deque->pushFront(arr[i]);
        else
        {
            deque->pushBack(arr[i]);
        }
    }
    deque->printDeque();
    cout << deque->getSize();
    delete deque;
}