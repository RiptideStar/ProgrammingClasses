#include "list.h"
#include <iostream>

using namespace std;

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

bool LinkedList::addAtBeginning(int val)
{
    bool flag = false;
    Node *headNode;
    if (head)
    {
        headNode = head;
        flag = true;
    }
    Node *node = new Node;
    node->data = val;
    node->next = head;
    head = node;
    if (flag)
    {
        headNode->prev = node;
    }

    return true;
}

bool LinkedList::addAtEnd(int val)
{
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
        //node will point to the last node at this moment
        node->prev = current;
        //assign the end after to the node
        current->next = node;
    }
    else
    {
        //assign head to node
        node->prev = NULL;
        head = node;
    }

    return true;
}

//check for index out of bounds, if out of bounds, just add to beginning/end boundary
bool LinkedList::addAtIndex(int val, int index)
{
    Node *node = new Node;
    node->data = val;
    if (head)
    {
        Node *current = head;
        for (int i = 0; i < index; i++)
        {
            if (current->next != NULL)
            {
                current = current->next;
            }
        }
        //assign node's previous and next
        node->prev = current->prev;
        node->next = current;

        //the previous node's "next" must point to node
        if (current->prev)
            current->prev->next = node;
        //the new previous node for the current node is now this node
        current->prev = node;
    }
    else
    {
        //assign head to node
        node->prev = NULL;
        node->next = NULL;
        head = node;
    }

    return true;
}

bool LinkedList::remove(int val)
{
    if (head)
    {
        Node *current = head;
        while (current->next != NULL)
        {
            if (current->data == val)
            {

                //check if it is the first element being removed
                if (current == head)
                {
                    head = head->next;
                    head->prev = NULL;
                }
                else
                {
                    current->next->prev = current->prev;
                    current->prev->next = current->next;
                }

                //deallocate memory
                delete current;

                return true;
            }
            current = current->next;
        }

        //above loop won't check last node, let's check it
        if (current->data == val)
        {
            current->prev->next = NULL;
            //deallocate memory
            delete current;

            cout << "Found" << endl;

            return true;
        }
    }

    return false;
}

void LinkedList::printForward() const
{
    if (head)
    {
        Node *current = head;
        cout << current->data << " --> ";
        //loop to keep printing the node data
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

void LinkedList::printBackward()
{
    return printBackwardR(head);
}

void LinkedList::printBackwardR(Node *current) const
{
    //base cases
    //if there is no list
    if (!current)
    {
        cout << "NULL" << endl;
        return;
    }
    //once at the end of the list
    if (current->next == NULL)
    {
        cout << current->data << " --> ";
        return;
    }
    //recursive call up until the end of the list
    printBackwardR(current->next);
    //then print everything starting from the back
    if (current == head) //if the current we are printing is the start of the list, then we must put an newline
        cout << current->data << " START" << endl;
    else
        cout << current->data << " --> ";
}