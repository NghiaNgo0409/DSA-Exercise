#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Heap
{
public:
    class Node;

private:
    vector<Node *> elements;
    int count;
    void reheapUp(int position);
    void reheapDown(int position);
    void swap(int a, int b);

public:
    Heap()
    {
        count = 0;
    }
    void buildHeap_insert(T *arr, int size);
    void push(Node *item);
    T pop();
    void Delete(T x);
    void print();
    class Node
    {
    private:
        T data;
        friend class Heap;

    public:
        Node(T data)
        {
            this->data = data;
        }
    };
};

template <class T>
void Heap<T>::swap(int a, int b)
{
    T temp = this->elements[a]->data;
    this->elements[a]->data = this->elements[b]->data;
    this->elements[b]->data = temp;
}

template <class T>
void Heap<T>::reheapUp(int position)
{
    if (position <= 0)
        return;
    int parent = (position - 1) / 2;
    if (this->elements[position]->data < this->elements[parent]->data)
    {
        this->swap(position, parent);
        reheapUp(parent);
    }
}

template <class T>
void Heap<T>::reheapDown(int position)
{
    int leftChild = position * 2 + 1;
    int rightChild = position * 2 + 2;
    int lastPosition = this->count - 1;

    if (leftChild <= lastPosition)
    {
        int smallChild = leftChild;
        if (rightChild <= lastPosition)
        {
            if (this->elements[leftChild]->data < this->elements[rightChild]->data)
            {
                smallChild = leftChild;
            }
            else
            {
                smallChild = rightChild;
            }
        }

        if (this->elements[smallChild]->data < this->elements[position]->data)
        {
            swap(smallChild, position);
            reheapDown(smallChild);
        }
    }
}

template <class T>
void Heap<T>::push(Node *item)
{
    elements.push_back(item);
    count = elements.size();
    reheapUp(count - 1);
}

template <class T>
T Heap<T>::pop()
{
    T item = elements[0];
    elements[0] = elements[count - 1];
    elements.pop_back();
    reheapDown(0);
    return item;
}

template <class T>
void Heap<T>::Delete(T x)
{
    int foundIdx = -1;
    for (int i = 0; i < elements.size(); i++)
    {
        if (x == elements[i])
        {
            foundIdx = 0;
        }
    }

    if (foundIdx == -1)
        return;
    if (foundIdx == 0)
    {
        pop();
    }
}

template <class T>
void Heap<T>::buildHeap_insert(T *root, int size)
{
    Node *newNode;
    for (int i = 0; i < size; i++)
    {
        newNode = new Node(root[i]);
        push(newNode);
    }
}

template <class T>
void Heap<T>::print()
{
    for (int i = 0; i < count; i++)
    {
        cout << elements[i]->data << " ";
    }
    cout << endl;
}

int main()
{
    Heap<int> heap;
    int arr[] = {7, 19, 5, 13, 4, 8, 11};
    heap.buildHeap_insert(arr, sizeof(arr) / sizeof(int));
    heap.print();

    /*
        4
    5       7
19    13  8   11
    */
}