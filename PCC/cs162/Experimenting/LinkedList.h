#ifndef LinkedList_h
#define LinkedList_h

using namespace std;

struct Node
{
    int data;
    Node *next;
};

class LinkedList
{
public:
    LinkedList();
    ~LinkedList();

    void addToHead(int val);
    void addToTail(int val);
    void addToTailRecursive(Node *curr, int val);

    int sum();
    int sumRecursive(Node *curr);

    void printAll();

    int removeFromHead();
    int removeFromTail();
    int removeFromTailRecursive(Node * curr);

private:
    Node *head;
};

#endif