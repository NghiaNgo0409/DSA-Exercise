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

LLNode *replaceFirstGreater(LLNode *head)
{
    LLNode *pivot = head;
    while (pivot != nullptr)
    {
        LLNode *tmp = pivot->next;
        bool found = false;
        while (tmp != nullptr)
        {
            if (pivot->val < tmp->val)
            {
                pivot->val = tmp->val;
                found = true;
                break;
            }
            tmp = tmp->next;
        }
        if (found == false)
        {
            pivot->val = 0;
        }
        pivot = pivot->next;
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
    // LLNode *l0 = new LLNode(2, new LLNode(9));
    // LLNode *l1 = new LLNode(0, new LLNode(5));
    // LLNode *head = addLinkedList(l0, l1);
    LLNode *head = new LLNode(0, new LLNode(3,
                                            new LLNode(2,
                                                       new LLNode(1,
                                                                  new LLNode(5)))));
    head = replaceFirstGreater(head);
    print(head);
}