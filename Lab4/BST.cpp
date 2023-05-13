#include <iostream>
using namespace std;

template <class T>
class BST
{
public:
    class Node; // Forward declaration
private:
    Node *root;

public:
    BST()
    {
        root = nullptr;
    }
    Node *getRoot()
    {
        return root;
    }
    void Insert(T *array, int size);
    T findMaxLeft(Node *root);
    T findMinRight(Node *root);
    void NLR(Node *root);

    class Node
    {
        T data;
        Node *pLeft;
        Node *pRight;
        friend class BST;

    public:
        Node(T data, Node *pLeft = nullptr, Node *pRight = nullptr)
        {
            this->data = data;
            this->pLeft = pLeft;
            this->pRight = pRight;
        }
    };
};

template <class T>
void BST<T>::Insert(T *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        Node *newNode = new Node(array[i]);
        if (root == nullptr)
        {
            root = newNode;
        }
        else
        {
            Node *current = root;
            while (true)
            {
                if (array[i] < current->data)
                {
                    if (current->pLeft == nullptr)
                    {
                        current->pLeft = newNode;
                        break;
                    }
                    else
                    {
                        current = current->pLeft;
                    }
                }
                else
                {
                    if (current->pRight == nullptr)
                    {
                        current->pRight = newNode;
                        break;
                    }
                    else
                    {
                        current = current->pRight;
                    }
                }
            }
        }
    }
}

template <class T>
T BST<T>::findMaxLeft(Node *root)
{
    if (root->pLeft == nullptr)
    {
        __throw_out_of_range("Leaf node");
    }
    Node *nodeMaxLeft = root->pLeft;
    while (nodeMaxLeft->pRight != nullptr)
    {
        nodeMaxLeft = nodeMaxLeft->pRight;
    }
    return nodeMaxLeft->data;
}

template <class T>
T BST<T>::findMinRight(Node *root)
{
    if (root->pRight == nullptr)
    {
        __throw_out_of_range("Leaf node");
    }
    Node *nodeMinRight = root->pRight;
    while (nodeMinRight->pLeft != nullptr)
    {
        nodeMinRight = nodeMinRight->pLeft;
    }
    return nodeMinRight->data;
}

template <class T>
void BST<T>::NLR(Node *root)
{
    if (root == nullptr)
        return;
    cout << root->data << " ";
    NLR(root->pLeft);
    NLR(root->pRight);
}

int main()
{
    int arr[] = {5, 4, 10, 3, 7, 15};
    int size = 6;
    BST<int> tree;
    tree.Insert(arr, size);
    tree.NLR(tree.getRoot());
    cout << endl;
    cout << tree.findMaxLeft(tree.getRoot());
    cout << endl;
    cout << tree.findMinRight(tree.getRoot());
}