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

    void printAll();

    int removeFromHead();
    int removeFromTail();
private:
    Node * head;
};

#endif