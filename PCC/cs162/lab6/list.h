#ifndef LIST_H
#define LIST_H

#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node * next;//Double Linked
	Node * prev;//Double Linked
};

class LinkedList
{
private:
	Node * head;
public:
	LinkedList();
	~LinkedList();
	
	bool addAtBeginning(int val);
	bool addAtEnd(int val);
	bool addAtIndex(int val, int index);//Count indices starting at 0
	
	//Remove the first instance of val. return false if val is not found
	bool remove(int val);

	void printForward() const;
	void printBackward();//This function should call printBackwardR
	void printBackwardR(Node * curr) const;//Must be implemented with RECURSION
};


#endif
