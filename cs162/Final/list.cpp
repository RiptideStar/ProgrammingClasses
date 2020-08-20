//Kyle Zhang
//8/19/2020

//Function definitions go in this file.
//Remmeber that the linked list is not in a class so you do not need any scope resolution
//i.e no: LinkedList::
#include <iostream>
#include <cstring>
#include <cctype>

#include "list.h"

int countEven(node *head)
{
    int count = 0;
    //check if there is a node in the list
    if (head)
    {
        node *current = head;
        //check current
        if (current->data % 2 == 0)
        {
            count++;
        }
        //check all the other nodes
        while (current->next != NULL)
        {
            current = current->next;
            if (current->data % 2 == 0)
            {
                count++;
            }
        }
        return count;
    }
    else
    {
        return 0;
    }
}

int removeSecondFinal(node *&head)
{
    //check if there are at least two nodes
    if (head && head->next)
    {
        node *current = head;
        node *afterCurrent = current->next;
        node *afterAfterCurrent = current->next->next;

        //if size of list is 2
        if (afterAfterCurrent == NULL)
        {
            node *delNode = head;
            int data = delNode->data;
            head = head->next;
            return data;
        }
        //get to the end of the list and set beforeCurrent to be the node to remove
        while (afterAfterCurrent->next)
        {
            afterAfterCurrent = afterAfterCurrent->next;
            afterCurrent = afterCurrent->next;
            current = current->next;
        }

        node *delNode = afterCurrent;
        int data = delNode->data;
        current->next = afterAfterCurrent;
        delete delNode;
        return data;
    }
    else
    {
        return -1;
    }
}

// int removeSecondFinal(node *&head)
// {
//     if (!head->next || !head) {
//         return -1;
//     }
//     if (head && head->next && head->next->next) {
//         node *delNode = head->next;
//         head->next = head->next->next;
//         int data = delNode->data;
//         delete delNode;
//         return data;
//     }
//     if (head && head->next) {
//         node *delNode = head;
//         head = head->next;
//         int data = delNode->data;
//         delete delNode;
//         return data;
//     }

// }
