#include <iostream>
#include <queue>
#include <stack>

using namespace std;

// template <class T>
// class BT
// {
// public:
//     class Node; // Forward declaration
// public:
//     Node *root;

// public:
//     BT();
//     ~BT();
//     void insert(T *arr, int size);
//     void postOrder(Node *root);
//     class Node
//     {
//     private:
//         T data;
//         Node *pLeft;
//         Node *pRight;
//         friend class BT;

//     public:
//         Node(T data, Node *pLeft = nullptr, Node *pRight = nullptr)
//         {
//             this->data = data;
//             this->pLeft = pLeft;
//             this->pRight = pRight;
//         }
//     };
// };

// template <class T>
// BT<T>::BT()
// {
//     root = nullptr;
// }

// template <class T>
// BT<T>::~BT()
// {
//     delete root;
// }

// template <class T>
// void BT<T>::insert(T *arr, int size)
// {
//     queue<T> q;
//     if (root == nullptr)
//     {
//         root = new Node(arr[0]);
//         q.push(root->data);
//     }
//     Node *tmp = root;
//     Node *parent = root;
//     int count = 0;
//     int i = 1;

//     while (i < size)
//     {
//         if (count == 0)
//         {
//             tmp->pRight = new Node(arr[i++]);
//             q.push(tmp->pRight->data);
//         }
//         if (count == 1)
//         {
//             tmp->pLeft = new Node(arr[i++]);
//             q.push(tmp->pLeft->data);
//         }
//         if (count == 2)
//         {
//             q.pop();
//             if (q.front() == parent->pRight->data)
//             {
//                 parent = tmp;
//                 tmp = tmp->pRight;
//             }
//             else if (q.front() == parent->pLeft->data)
//             {
//                 parent = tmp;
//                 tmp = tmp->pLeft;
//             }
//             count = 0;
//             continue;
//         }
//         count++;
//     }
// }

// template <class T>
// void BT<T>::postOrder(Node *root)
// {
//     if (root == nullptr)
//     {
//         return;
//     }
//     else
//     {
//         postOrder(root->pLeft);
//         postOrder(root->pRight);
//         cout << root->data << " ";
//     }
// }

// int main()
// {
//     int arr[] = {10, 2, 5, 7, 8, 9};
//     BT<int> tree;
//     tree.insert(arr, 6);
//     tree.postOrder(tree.root);
// }

template <typename T>
class BT
{
public:
    class Node; // Forward declaration
public:
    Node *root;

public:
    BT() : root(nullptr) {}
    ~BT() {}
    void insert(T *arr, int size)
    {
        for (int i = 0; i < size; i++)
        {
            Node *newNode = new Node(arr[i]);
            if (root == nullptr)
            {
                root = newNode;
            }
            else
            {
                Node *current = root;
                while (true)
                {
                    if (arr[i] < current->data)
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
    void postOrder(Node *root)
    {
        if (root != nullptr)
        {
            postOrder(root->pLeft);
            postOrder(root->pRight);
            std::cout << root->data << " ";
        }
    }

    void mirror(Node *root)
    {
        if (root != nullptr)
        {
            mirror(root->pLeft);
            mirror(root->pRight);
            Node *temp = root->pLeft;
            root->pLeft = root->pRight;
            root->pRight = temp;
        }
    }

    void printRightToLeft(Node *root)
    {
        if (root != nullptr)
        {
            printRightToLeft(root->pRight);
            std::cout << root->data << " ";
            printRightToLeft(root->pLeft);
        }
    }
    Node *findMaxHeightSubtree(Node *root)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        int leftHeight = getHeight(root->pLeft);
        int rightHeight = getHeight(root->pRight);
        if (leftHeight > rightHeight)
        {
            return findMaxHeightSubtree(root->pLeft);
        }
        else if (rightHeight > leftHeight)
        {
            return findMaxHeightSubtree(root->pRight);
        }
        else
        {
            return root;
        }
    }

    int getHeight(Node *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int leftHeight = getHeight(root->pLeft);
        int rightHeight = getHeight(root->pRight);
        return 1 + std::max(leftHeight, rightHeight);
    }
    class Node
    {
    private:
        T data;
        Node *pLeft;
        Node *pRight;
        friend class BT;

    public:
        Node(T data, Node *pLeft = nullptr, Node *pRight = nullptr)
        {
            this->data = data;
            this->pLeft = pLeft;
            this->pRight = pRight;
        }
    };
};

int main()
{
    int arr[] = {10, 2, 5, 7, 8, 9};
    BT<int> tree;
    tree.insert(arr, 6);
    tree.postOrder(tree.root);
}

/*
                10
            5        2
               9   8    7
*/