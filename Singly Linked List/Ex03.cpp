#include <iostream>

using namespace std;

class Node
{
    int data;
    Node *next;

public:
    Node() : data(0), next(nullptr) {}

    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }

    int getData()
    {
        return this->data;
    }

    void setData(int data)
    {
        this->data = data;
    }

    Node *getNext()
    {
        return this->next;
    }

    void setNext(Node *next)
    {
        this->next = next;
    }
};

void reduceDuplicate(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    else
    {
        Node *tmp = root;
        while (tmp->getNext() != nullptr)
        {
            if (tmp->getData() == tmp->getNext()->getData())
            {
                Node *deleteNode = tmp->getNext();
                tmp->setNext(tmp->getNext()->getNext());
                delete deleteNode;
            }
            else
            {
                tmp = tmp->getNext(); // Else here because when delete the node at the end, the function will not run segmentation fault
            }
        }
    }
}

void print(Node *head)
{
    cout << "HEAD -> ";
    Node *tmp = head;
    while (tmp != nullptr)
    {
        cout << tmp->getData() << " -> ";
        tmp = tmp->getNext();
    }
    cout << "NULL";
}

int main()
{
    Node *node1 = new Node(1, nullptr);
    Node *node2 = new Node(1, node1);
    Node *node3 = new Node(0, node2);
    print(node3);
    reduceDuplicate(node3);
    print(node3);
}