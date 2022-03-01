/**************************************************************
* Name        : Singly Linked List
* Author      : William Thomas
* Created     : 4/24/2019
* Course      : CIS 152 – Data Structures
* Version     : 1.0
* OS          : Windows 10
* Copyright   : This is my own original work based on
*               specifications issued by our instructor
* Description : Create a linked list using Nodes. Tests included.
*               Input:  N/A
*               Output: Testing of implementation with a test suite
* Academic Honesty: I attest that this is my original work.
* I have not used unauthorized source code, either modified or
* unmodified. I have not given other fellow student(s) access to
* my program.
***************************************************************/
#include "linkedlist.h"
#include "can.h"

#include <iostream>

using namespace std;

int main()
{
    LinkedList ll = LinkedList();
    Can can = Can();
    Can can2 = Can("Blue", "Beans", 5.25, 19.99);
    Can can3 = Can("Red", "Sauce", 15.50, 4.99);
    cout << "Inserting default object" << endl;
    ll.insert(can);
    cout << "Inserting args object" << endl;
    ll.insert(can2);
    cout << "Inserting second args object" << endl;
    ll.insert(can3);
    cout << "Using LinkedList printList() method to call object toString()" << endl;
    cout << ll.printList() << endl;
    cout << "Testing size() function (should be 3 as we have added 3 objects)" << endl;
    cout << ll.size() << endl;
    cout << "Removing first object (removal runs by index location in list)" << endl;
    ll.remove(0);
    cout << "List after removal:" << endl;
    cout << ll.printList() << endl;
    cout << "Perform another removal and output." << endl;
    ll.remove(0);
    cout << ll.printList() << endl;
    LinkedList empty = LinkedList();
    cout << "Testing for empty exception throw during print" << endl;
    cout << empty.printList() << endl;


}
