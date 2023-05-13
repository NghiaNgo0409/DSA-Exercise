#include <iostream>
#include <math.h>
#include <queue>
using namespace std;
#define SEPARATOR "#<ab@17943918#@>#"

enum BalanceValue
{
    LH = -1,
    EH = 0,
    RH = 1
};

void printNSpace(int n)
{
    for (int i = 0; i < n - 1; i++)
        cout << " ";
}

void printInteger(int &n)
{
    cout << n << " ";
}

template <class T>
class AVLTree
{
public:
    class Node;

private:
    Node *root;

protected:
    int getHeightRec(Node *node)
    {
        if (node == NULL)
            return 0;
        int lh = this->getHeightRec(node->pLeft);
        int rh = this->getHeightRec(node->pRight);
        return (lh > rh ? lh : rh) + 1;
    }

public:
    AVLTree() : root(nullptr) {}
    ~AVLTree() {}
    int getHeight()
    {
        return this->getHeightRec(this->root);
    }
    void printTreeStructure()
    {
        int height = this->getHeight();
        if (this->root == NULL)
        {
            cout << "NULL\n";
            return;
        }
        queue<Node *> q;
        q.push(root);
        Node *temp;
        int count = 0;
        int maxNode = 1;
        int level = 0;
        int space = pow(2, height);
        printNSpace(space / 2);
        while (!q.empty())
        {
            temp = q.front();
            q.pop();
            if (temp == NULL)
            {
                cout << " ";
                q.push(NULL);
                q.push(NULL);
            }
            else
            {
                cout << temp->data;
                q.push(temp->pLeft);
                q.push(temp->pRight);
            }
            printNSpace(space);
            count++;
            if (count == maxNode)
            {
                cout << endl;
                count = 0;
                maxNode *= 2;
                level++;
                space /= 2;
                printNSpace(space / 2);
            }
            if (level == height)
                return;
        }
    }

    Node *removeRec(Node *node, const T &value)
    {
        if (node == NULL)
            return NULL;
        if (value < node->data)
            node->pLeft = removeRec(node->pLeft, value);
        else if (value > node->data)
            node->pRight = removeRec(node->pRight, value);
        else
        {
            Node *leftChild = node->pLeft;
            Node *rightChild = node->pRight;
            delete node;
            if (rightChild == NULL)
                return leftChild;
            Node *minNode = findMin(rightChild);
            minNode->pRight = removeMin(rightChild);
            minNode->pLeft = leftChild;
            return balance(minNode);
        }
        return balance(node);
    }

    Node *findMin(Node *node)
    {
        while (node->pLeft != NULL)
            node = node->pLeft;
        return node;
    }

    Node *removeMin(Node *node)
    {
        if (node->pLeft == NULL)
            return node->pRight;
        node->pLeft = removeMin(node->pLeft);
        return balance(node);
    }

    Node *balance(Node *node)
    {
        if (node == NULL)
            return NULL;
        if (getHeightRec(node->pLeft) - getHeightRec(node->pRight) == 2)
        {
            if (getHeightRec(node->pLeft->pLeft) >= getHeightRec(node->pLeft->pRight))
                node = rightRotate(node);
            else
                node = leftRightRotate(node);
        }
        else if (getHeightRec(node->pRight) - getHeightRec(node->pLeft) == 2)
        {
            if (getHeightRec(node->pRight->pRight) >= getHeightRec(node->pRight->pLeft))
                node = leftRotate(node);
            else
                node = rightLeftRotate(node);
        }
        updateBalance(node);
        return node;
    }

    Node *rightRotate(Node *node)
    {
        Node *temp = node->pLeft;
        node->pLeft = temp->pRight;
        temp->pRight = node;
        updateBalance(node);
        updateBalance(temp);
        return temp;
    }

    Node *leftRotate(Node *node)
    {
        Node *temp = node->pRight;
        node->pRight = temp->pLeft;
        temp->pLeft = node;
        updateBalance(node);
        updateBalance(temp);
        return temp;
    }

    Node *leftRightRotate(Node *node)
    {
        node->pLeft = leftRotate(node->pLeft);
        return rightRotate(node);
    }

    Node *rightLeftRotate(Node *node)
    {
        node->pRight = rightRotate(node->pRight);
        return leftRotate(node);
    }

    void updateBalance(Node *node)
    {
        int leftHeight = getHeightRec(node->pLeft);
        int rightHeight = getHeightRec(node->pRight);
        if (leftHeight > rightHeight)
            node->balance = LH;
        else if (leftHeight < rightHeight)
            node->balance = RH;
        else
            node->balance = EH;
    }

    void remove(const T &value)
    {
        // TODO
        root = removeRec(root, value);
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
