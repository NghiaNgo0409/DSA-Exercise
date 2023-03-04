#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *left;
    ListNode *right;
    ListNode(int x = 0, ListNode *l = nullptr, ListNode *r = nullptr) : val(x), left(l), right(r) {}
};

ListNode *reverse(ListNode *head, int a, int b)
{
    if (a == b)
    {
        return head;
    }

    ListNode *cur = head;
    ListNode *prev = nullptr;
    for (int i = 1; i < a; i++)
    {
        prev = cur;
        cur = cur->right;
    }

    ListNode *first = cur;
    ListNode *second = cur->right;
    ListNode *third = nullptr;
    for (int i = a; i < b; i++)
    {
        third = second->right;
        second->right = first;
        first->left = second;
        first = second;
        second = third;
    }

    if (prev != nullptr)
    {
        prev->right = first;
    }
    first->left = prev;
    cur->right = second;
    if (second != nullptr)
    {
        second->left = cur;
    }

    if (a == 1)
    {
        return first;
    }
    else
    {
        return head;
    }
}