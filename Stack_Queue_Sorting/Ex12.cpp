#include <iostream>
#include <sstream>
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
    SLinkedList()
    {
        this->head = nullptr;
        this->tail = nullptr;
        this->count = 0;
    }
    ~SLinkedList(){};
    void add(T e)
    {
        Node *pNew = new Node(e);

        if (this->count == 0)
        {
            this->head = this->tail = pNew;
        }
        else
        {
            this->tail->next = pNew;
            this->tail = pNew;
        }

        this->count++;
    }
    int size()
    {
        return this->count;
    }
    void printList()
    {
        stringstream ss;
        ss << "[";
        Node *ptr = head;
        while (ptr != tail)
        {
            ss << ptr->data << ",";
            ptr = ptr->next;
        }

        if (count > 0)
            ss << ptr->data << "]";
        else
            ss << "]";
        cout << ss.str() << endl;
    }

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
        Node(T data)
        {
            this->data = data;
            this->next = nullptr;
        }
    };

    void bubbleSort();
};

template <class T>
void SLinkedList<T>::bubbleSort()
{
    if (count <= 1)
        return;

    bool swapped;
    Node *curr;
    Node *prev = nullptr;

    do
    {
        if (head->next == prev && head->data <= head->next->data)
        {
            return;
        }
        swapped = false;
        curr = head;

        while (curr->next != prev)
        {
            if (curr->data > curr->next->data)
            {
                // Swap data
                T temp = curr->data;
                curr->data = curr->next->data;
                curr->next->data = temp;
                swapped = true;
            }

            curr = curr->next;
        }

        prev = curr;
        printList(); // Print the list after each bubble
    } while (swapped);
}