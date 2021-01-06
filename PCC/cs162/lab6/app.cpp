#include "list.h"

int main()
{
	LinkedList aList;

	aList.addAtBeginning(3);
	aList.addAtBeginning(10);
	aList.addAtBeginning(1); //1 10 3
	aList.addAtEnd(7);
	aList.addAtEnd(9); //1 10 3 7 9
	aList.addAtBeginning(12); //12 1 10 3 7 9
	aList.addAtIndex(18, 2); // 12 1 18 10 3 7 9
	aList.addAtIndex(22, 5); // 12 1 18 10 3 22 7 9
	aList.printForward();  // 12 1 18 10 3 22 7 9
	aList.printBackward(); // 9 7 22 3 10 18 1 12
	aList.remove(3);
	aList.remove(1);
	aList.remove(7);
	aList.remove(12);
	aList.printForward();
	aList.printBackward();

	return 0;
}

