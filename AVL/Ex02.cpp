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

    // Helping functions
    Node *insertUtil(Node *head, T x)
    {
        if (head == NULL)
        {
            Node *temp = new Node(x);
            return temp;
        }
        if (x < head->data)
            head->pLeft = insertUtil(head->pLeft, x);
        else if (x > head->data)
            head->pRight = insertUtil(head->pRight, x);
        int bal = getHeightRec(head->pLeft) - getHeightRec(head->pRight);
        if (bal > 1)
        {
            if (x < head->pLeft->data)
            {
                return rightRotate(head);
            }
            else
            {
                head->pLeft = leftRotate(head->pLeft);
                return rightRotate(head);
            }
        }
        else if (bal < -1)
        {
            if (x > head->pRight->data)
            {
                return leftRotate(head);
            }
            else
            {
                head->pRight = rightRotate(head->pRight);
                return leftRotate(head);
            }
        }
        return head;
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

    void insert(const T &value)
    {
        // TODO
        root = insertUtil(root, value);
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