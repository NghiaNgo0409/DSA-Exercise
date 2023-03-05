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
    void partition(int k);
};

void LinkedList::partition(int k)
{
    // Edge case: If the list is empty or it has only 1 item, just return
    if (!head || !tail || size < 2)
    {
        return;
    }

    Node *group1_head = nullptr, *group1_tail = nullptr;
    Node *group2_head = nullptr, *group2_tail = nullptr;
    Node *group3_head = nullptr, *group3_tail = nullptr;

    // Traverse through the list and move each node to its corresponding group
    Node *current = head;
    while (current != nullptr)
    {
        Node *next = current->next;
        if (current->value < k)
        {
            if (group1_head == nullptr)
            {
                group1_head = current;
            }
            else
            {
                group1_tail->next = current;
            }
            group1_tail = current;
        }
        else if (current->value == k)
        {
            if (group2_head == nullptr)
            {
                group2_head = current;
            }
            else
            {
                group2_tail->next = current;
            }
            group2_tail = current;
        }
        else
        {
            if (group3_head == nullptr)
            {
                group3_head = current;
            }
            else
            {
                group3_tail->next = current;
            }
            group3_tail = current;
        }

        current->next = nullptr;
        current = next;
    }

    // Concatenate the three groups
    if (group1_head != nullptr)
    {
        head = group1_head;
        if (group2_head != nullptr)
        {
            group1_tail->next = group2_head;
            if (group3_head != nullptr)
            {
                group2_tail->next = group3_head;
                tail = group3_tail;
            }
            else
            {
                tail = group2_tail;
            }
        }
        else
        {
            if (group3_head != nullptr)
            {
                group1_tail->next = group3_head;
                tail = group3_tail;
            }
            else
            {
                tail = group1_tail;
            }
        }
    }
    else
    {
        if (group2_head != nullptr)
        {
            head = group2_head;
            if (group3_head != nullptr)
            {
                group2_tail->next = group3_head;
                tail = group3_tail;
            }
            else
            {
                tail = group2_tail;
            }
        }
        else
        {
            if (group3_head)
            {
                head = group3_head;
                tail = group3_tail;
            }
            else
            {
                return;
            }
        }
    }

    size = 0;
    current = head;
    while (current != nullptr)
    {
        ++size;
        current = current->next;
    }
}

int main()
{
}