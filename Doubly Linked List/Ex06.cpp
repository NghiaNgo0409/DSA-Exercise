#include <iostream>
#include <list>
#include <iterator>
#include <string>

using namespace std;

class LineStreet
{
public:
    class Node;

protected:
    Node *home;
    Node *currentElement;
    int count;

public:
    LineStreet(string homepage)
    {
        home = new Node(homepage);
        currentElement = home;
        count = 0;
    }

    void addNewElement(string url)
    {
        Node *newNode = new Node(url);
        newNode->previous = currentElement;
        currentElement->next = newNode;
        currentElement = newNode;
        count++;
    }

    string back(int steps)
    {
        while (steps > 0 && currentElement->previous)
        {
            currentElement = currentElement->previous;
            steps--;
        }
        return currentElement->content;
    }

    string forward(int steps)
    {
        while (steps > 0 && currentElement->next)
        {
            currentElement = currentElement->next;
            steps--;
        }
        return currentElement->content;
    }

public:
    class Node
    {
    private:
        string content;
        Node *next;
        Node *previous;
        friend class LineStreet;

    public:
        Node(string content, Node *next = nullptr, Node *previous = nullptr)
        {
            this->content = content;
            this->next = next;
            this->previous = previous;
        }
    };
};

int main()
{
    LineStreet *obj = new LineStreet("home");
    obj->addNewElement("Bob");
    obj->addNewElement("Smith");
    obj->addNewElement("Ann");
    cout << obj->back(1) << endl;
    cout << obj->back(1) << endl;
    cout << obj->forward(1) << endl;
    obj->addNewElement("Peter");
    cout << obj->forward(2) << endl;
    cout << obj->back(1) << endl;
}