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

LLNode *rotateLinkedList(LLNode *head, int k)
{
    // Handle the special case
    if (head == nullptr || head->next == nullptr || k == 0)
    {
        return head;
    }

    // Calculate the length of list
    int length = 0;
    LLNode *tmp = head;
    while (tmp != nullptr)
    {
        length++;
        tmp = tmp->next;
    }

    int rotateBy = k % length;
    // Another special case
    if (rotateBy == 0)
    {
        return head;
    }

    // Find the node at position length - rotateBy
    tmp = head;
    for (int i = 1; i < length - rotateBy; i++)
    {
        tmp = tmp->next;
    }

    // Set new head and tail after rotate
    LLNode *newHead = tmp->next;
    tmp->next = nullptr;
    LLNode *tail = newHead;
    while (tail->next != nullptr)
    {
        tail = tail->next;
    }
    tail->next = head;
    return newHead;
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
    LLNode *head = new LLNode(2, new LLNode(4, new LLNode(6, new LLNode(6, new LLNode(3)))));
    head = rotateLinkedList(head, 3);
    print(head);
}