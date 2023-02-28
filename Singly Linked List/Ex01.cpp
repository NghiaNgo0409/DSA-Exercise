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

LLNode *addLinkedList(LLNode *l0, LLNode *l1)
{
    int carry = 0;
    LLNode *head = nullptr;
    LLNode *tail = nullptr;

    while (l0 || l1)
    {
        int sum = carry;
        if (l0)
        {
            sum += l0->val;
            l0 = l0->next;
        }

        if (l1)
        {
            sum += l1->val;
            l1 = l1->next;
        }

        carry = sum / 10; // If sum > 9 then carry will take care the extra
        sum %= 10;

        LLNode *node = new LLNode(sum);

        if (head == nullptr && tail == nullptr)
        {
            head = node;
            tail = node;
        }
        else
        {
            tail->next = node;
            tail = node;
        }
    }

    // Process carry
    if (carry > 0)
    {
        LLNode *node = new LLNode(carry);

        if (tail == nullptr)
        {
            head = node;
        }
        else
        {
            tail->next = node;
        }
    }
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
    LLNode *l0 = new LLNode(2, new LLNode(9));
    LLNode *l1 = new LLNode(0, new LLNode(5));
    LLNode *head = addLinkedList(l0, l1);
    print(head);
}