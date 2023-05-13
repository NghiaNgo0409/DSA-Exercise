#include <iostream>
#include <queue>
using namespace std;
#define SEPARATOR "#<ab@17943918#@>#"

enum BalanceValue
{
    LH = -1,
    EH = 0,
    RH = 1
};

template <class T>
class AVLTree
{
public:
    class Node;

private:
    Node *root;

public:
    AVLTree() : root(nullptr) {}
    ~AVLTree() {}

    bool searchRec(Node *node, const T &value)
    {
        if (node == nullptr)
            return false;

        if (node->data == value)
            return true;
        else if (value < node->data)
            return searchRec(node->pLeft, value);
        else
            return searchRec(node->pRight, value);
    }

    void printInorderRec(Node *node)
    {
        if (node != nullptr)
        {
            printInorderRec(node->pLeft);
            cout << node->data << " ";
            printInorderRec(node->pRight);
        }
    }

    void printInorder()
    {
        printInorderRec(root);
        cout << " ";
    }

    bool search(const T &value)
    {
        return searchRec(root, value);
    }

    class Node
    {
    private:
        T data;
        Node *pLeft, *pRight;
        BalanceValue balance;
        friend class AVLTree<T>;

    public:
        Node(T value) : data(value), pLeft(NULL), pRight(NULL), balance(EH) {}
        ~Node() {}
    };
};
