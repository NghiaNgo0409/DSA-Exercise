#include <iostream>

using namespace std;

class LinkedList
{
public:
    class Node;

private:
    Node *head;
    Node *tail;
    int size;

public:
    class Node
    {
    private:
        int value;
        Node *next;
        friend class LinkedList;

    public:
        Node()
        {
            this->next = NULL;
        }
        Node(Node *node)
        {
            this->value = node->value;
            this->next = node->next;
        }
        Node(int value, Node *next = NULL)
        {
            this->value = value;
            this->next = next;
        }
    };
    LinkedList() : head(NULL), tail(NULL), size(0){};
    void replace(LinkedList *linked_list, int low, int high);
};

void LinkedList::replace(LinkedList *linked_list, int low, int high)
{
    if (high < 0) return;
    Node *tmp = head;\
    Node *deleteNode = nullptr;
    int count;
    for (int i = low; i <= high; i++)
    {
        count = 0;
        while (count != i - 1)
        {
            tmp = tmp->next;
        }
        deleteNode = tmp->next;
        if (i == size - 1)
        {
            tmp->next = nullptr;
            tail = tmp;
        }
        else
        {
            tmp->next = tmp->next->next;
        }
        delete deleteNode;
        size--;
    }

    
}

int main()
{
}