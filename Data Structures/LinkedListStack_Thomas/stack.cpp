/*
 * stack.cpp
 *
 *  Created on: 
 *      Author: 
 */

#include "stack.h"
#include <string>
using namespace std;

stack::stack() {
    list<string> sList;
}
//parametrized constructor to define a size of the list
stack::stack(int s) {
    sList.resize(s);
}

stack::~stack() {
}

bool stack::isFull() {
    return size() == (int)sList.max_size(); //list library using max_size returns true if list is full (lists in C++ hold 768614336404564650 items)
}

bool stack::isEmpty() {
    return sList.empty(); //returns true is list is empty
}

int stack::size() {
    return sList.size();    //returns list method size()
}

string stack::peek() {
    if (isEmpty()) {
        throw StackEmptyException("Stack is empty");
    }
    return sList.front(); //returns the value of front element of list
}

string stack::pop() {
    string item;
    if (isEmpty()) {
        throw StackEmptyException("Stack is empty");
    }
    item = sList.front();   //assigns data to variable to return
    sList.pop_front();      //deletes the element from the list
    return item;
}

void stack::push(string item) {
    if (isFull()) {
        throw StackFullException("Stack is full");
    }
    sList.push_front(item); //push data onto stack
}

string stack::printStackUp() {
    string stackString = "";
    if (isEmpty()) {
        throw StackEmptyException("Stack is empty");
    }
    //decrement through list using list's methods to print stack
    for (auto it = sList.begin(); it != sList.end(); it++) {
        stackString += *it + "\n";
    }
	return stackString; 
}


