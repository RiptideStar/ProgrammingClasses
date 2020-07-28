#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList()
{
    head = NULL;
}

LinkedList::~LinkedList()
{
    //if there is a list
    if (head) {
        Node * current = head;
        //delete everything going up until final element
        while(current->next != NULL) {
            Node * temp = current;
            current = current->next;
            delete temp;
        }
        //final element deletion
        delete current;
    }
}

void LinkedList::addToHead(int val)
{
    Node *node = new Node;
    node->data = val;
    node->next = head;
    head = node;
}

void LinkedList::addToTail(int val) {
    //populate our new Node
    Node * node = new Node;
    node->data = val;
    node->next = NULL;

    if (head) {
        //get to the end
        Node * current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        //assign the end to the node
        current->next = node;
    }
    else {
        head = node;
    }
}

void LinkedList::printAll()
{
    if (head != NULL)
    {
        Node *current = head;
        cout << current->data << " --> ";
        while (current->next != NULL)
        {
            current = current->next;
            cout << current->data << " --> ";
        }
        cout << "NULL" << endl;
    }
    else
    {
        cout << "NULL" << endl;
    }
}

int LinkedList::removeFromHead()
{
    if (head)
    {
        int val = head->data;
        Node * current = head;
        head = head->next;
        delete current;
        return val;
    }
    return 0;
}

int LinkedList::removeFromTail() {
    //list has a size
    if(head) {
        Node * current = head; 
        Node * tail = current -> next; //current will always be one node behind tail
        //list has a size of 2+
        if (tail) {
            while(tail->next != NULL) {
                current = current->next;
                tail = tail->next;
            }
            int val = tail->data;
            delete tail; //deallocate the tail
            current->next = NULL; //current's next variable was pointing to tail, but it's gone
        }
        //list size 1
        else {
            head = NULL;
            int val = current->data;
            delete current;
            return val;
        }
    }
    return 0; //if there isn't a size
}