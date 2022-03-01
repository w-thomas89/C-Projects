#include "linkedlist.h"
#include "listfullexception.h"
#include "listemptyexception.h"

LinkedList::LinkedList()
{
    maxSize = 5;
    listSize = 0;
    head = 0;
    next = 0;
    listItems = new double[maxSize];
}

LinkedList::LinkedList(int size) {
    maxSize = size;
    listSize = 0;
    head = 0;
    next = 0;
    listItems = new double[maxSize];
}

LinkedList::~LinkedList() {}

bool LinkedList::isFull() {
    return size() == maxSize;
}

bool LinkedList::isEmpty() {
    return size() == 0;
}

void LinkedList::insert(double value, int index) {
    if (isFull()) {
        throw listFullException("List is full");
    }
    for (int i = listSize; i < index; ++i) {
        listItems[i] = listItems[i-1];
    }
    listItems[index] = value;
    listSize++;
}

void LinkedList::remove(double value) {
    if (isEmpty()) {
        throw listEmptyException("List is empty");
    }
    for (int i = head; i < listSize - 1; i++) {
        if (listItems[i] == value) {
            delete &listItems[i];
            while (i < listSize-1) {
                listItems[i] = listItems[i+1];
            }
        }
    }
}
//used for testing
double LinkedList::get(int index) {
    return listItems[index];
}

void LinkedList::replace(double value1, double value2) {
    if (isEmpty()) {
        throw listEmptyException("List is empty");
    }
    for (int i = head; i < listSize - 1; i++) {
        if (listItems[i] == value1) {
            listItems[i] = value2;
        }
    }
}

int LinkedList::size() {
    return listSize;
}

string LinkedList::printList() {
    string listString = "";
    int k = head;
    if (isEmpty()) {
        throw listEmptyException("List is empty");
    }
    do {
        listString += to_string(listItems[k]) + "\n";
        k++;
    }
    while (k <= listSize);
    return listString;
}




/*
A Linked List is a collection of objects of the same type that are arranged sequentially that does not allow for random access.
 Traversal and access is through the use of head, and next, (previous and tail for doubly-linked lists). Linked Lists have the following operations: .

createList(), return an empty List of a given object type NOTE: constructor(s) can used to create data structures
isFull(), returns a boolean value, determines whether List is full or not
isEmpty(), returns a boolean value, determines whether List is empty or not (only required for array-based implementations)
insert(e), nothing is returned, adds the item e at any position in the List
remove(e), removes the first occurence of an element from a non-empty List
replace(e1, e2), replace an item at any position by any item (optional)
size(), returns an integer, the number of items in the List
print(), returns a string, the items in the List

*/
