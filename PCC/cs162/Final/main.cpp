#include "list.h"
using namespace std;

int main()
{
    //This variable is essentially your Linked List
    node * head = NULL;

    build(head);
    display(head);

    //PLEASE PUT YOUR CODE HERE to call the function assigned

    int count = countEven(head);
    cout << "Count of Evens: " << count << endl;

    cout << "Removal of second to final node: " << endl;
    removeSecondFinal(head);
    display(head);

    //You may place extra calls to display to help with debugging
    // display(head);
    destroy(head);
    
    return 0;
}
