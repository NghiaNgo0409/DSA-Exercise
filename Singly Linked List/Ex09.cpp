#include <iostream>
using namespace std;

class LLNode
{
public:
    int val;
    LLNode *next;
    LLNode(int data, LLNode *next = 0)
    {
        val = data;
        this->next = next;
    }
};

LLNode *reverseLinkedList(LLNode *head)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    LLNode *prev = nullptr;
    LLNode *curr = head;
    LLNode *next = nullptr;
    while (curr != nullptr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}

void print(LLNode *head)
{
    LLNode *tmp = head;
    while (tmp != nullptr)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

int main()
{
    LLNode *head = new LLNode(1, new LLNode(2, new LLNode(3, new LLNode(4))));
    head = reverseLinkedList(head);
    print(head);
}