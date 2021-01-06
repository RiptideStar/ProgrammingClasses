#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList()
{
    head = NULL;
}

LinkedList::~LinkedList()
{
    //if there is a list
    if (head)
    {
        Node *current = head;
        //delete everything going up until final element
        while (current->next != NULL)
        {
            Node *temp = current;
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

void LinkedList::addToTailRecursive(Node *curr, int val)
{
    if (curr)
    {
        //base case 1 (end of list)
        if (curr->next == NULL)
        {
            Node *node = new Node;
            node->data = val;
            node->next = NULL;
            curr = node;
        }
        else {
            addToTailRecursive(curr->next, val);  //keep going to the next node, recursively
        }
    }
    //base case 2 (empty list, assign head to node)
    else
    {
        Node *node = new Node;
        node->data = val;
        node->next = NULL;
        head = node;
    }
}

void LinkedList::addToTail(int val)
{
    //populate our new Node
    Node *node = new Node;
    node->data = val;
    node->next = NULL;

    if (head)
    {
        //get to the end
        Node *current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        //assign the end after to the node
        current->next = node;
    }
    else
    {
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
        Node *current = head;
        head = head->next;
        delete current;
        return val;
    }
    return 0;
}

int LinkedList::removeFromTail()
{
    //list has a size
    if (head)
    {
        Node *current = head;
        Node *tail = current->next; //current will always be one node behind tail
        //list has a size of 2+
        if (tail)
        {
            while (tail->next != NULL)
            {
                current = current->next;
                tail = tail->next;
            }
            int val = tail->data;
            delete tail;          //deallocate the tail
            current->next = NULL; //current's next variable was pointing to tail, but it's gone
        }
        //list size 1
        else
        {
            head = NULL;
            int val = current->data;
            delete current;
            return val;
        }
    }
    return 0; //if there isn't a size
}

int LinkedList::removeFromTailRecursive(Node * curr) {
    if (curr) {
        if (curr->next) {
            if (curr->next->next) 
                return removeFromTailRecursive(curr->next);
            else {
                int retVal = curr->next->data;
                delete curr->next;
                curr->next = NULL;
                return retVal;
            }
        }
        int retVal = curr->data;
        delete curr;
        head = NULL;
        return retVal;
    }
    else {
        return 0;
    }
}

int LinkedList::sum() {
    return sumRecursive(head);
}

int LinkedList::sumRecursive(Node *curr) {
    //once we reach no node, just return back 0 (doesn't affect sum and stops recursive)
    if(!curr) return 0;

    //if at tail of list
    if (curr->next == NULL) return curr->data;

    //recursive call, add the current node data into the previous
    return curr->data + sumRecursive(curr->next);
}