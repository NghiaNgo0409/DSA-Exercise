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
    void add(int value);
    void print();
    void replace(LinkedList *linked_list, int low, int high);
};

void LinkedList::add(int value)
{
    Node *item = new Node(value);
    if (head == nullptr && tail == nullptr)
    {
        head = item;
        tail = item;
    }
    else
    {
        tail->next = item;
        tail = item;
    }
    size++;
}

void LinkedList::print()
{
    Node *tmp = head;
    while (tmp)
    {
        cout << tmp->value << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

void LinkedList::replace(LinkedList *linked_list, int low, int high)
{
    // If the low value is less than zero, set it to zero
    if (low < 0)
    {
        low = 0;
    }
    // If the high value is greater than or equal to the size, set it to size - 1
    if (high >= size)
    {
        high = size - 1;
    }
    // If the low value is greater than the high value, return without doing anything
    if (low > high)
    {
        return;
    }

    // Delete nodes from position low to position high
    Node *current = head;
    Node *previous = NULL;
    int index = 0;
    while (current != NULL && index < low)
    {
        previous = current;
        current = current->next;
        index++;
    }
    while (current != NULL && index <= high)
    {
        Node *next_node = current->next;
        delete current;
        current = next_node;
        index++;
    }
    if (previous == NULL)
    {
        // Delete from head
        head = current;
    }
    else
    {
        previous->next = current;
    }
    if (current == NULL)
    {
        // Delete to tail
        tail = previous;
    }

    // Add linked_list to the position after position (low - 1)
    if (low <= 0)
    {
        // Delete from the head of this linked list
        linked_list->tail->next = head;
        head = linked_list->head;
        if (tail == NULL)
        {
            // If the original linked list was empty, the tail is the tail of linked_list
            tail = linked_list->tail;
        }
    }
    else if (previous == NULL)
    {
        // Delete from the head of linked_list
        tail = linked_list->tail;
        linked_list->tail->next = current;
        head = linked_list->head;
    }
    else
    {
        // Delete from the middle of linked list
        previous->next = linked_list->head;
        linked_list->tail->next = current;
        if (tail == previous)
        {
            // If the last node was deleted, set tail to the tail of linked_list
            tail = linked_list->tail;
        }
    }

    // Update size of the linked list
    size += linked_list->size - (high - low + 1);
}

int main()
{
    LinkedList *l1 = new LinkedList();
    LinkedList *l2 = new LinkedList();
    l1->add(10);
    l1->add(20);
    l1->add(30);
    l1->add(40);
    l1->add(50);
    l2->add(55);
    l2->add(45);
    l2->add(42);
    l1->replace(l2, 1, 3);
    l1->print();
}