/*
 * stack.h
 *
 *  Created on: 
 *      Author: 
 */
#include <string>
#include "StackEmptyException.h"
#include "StackFullException.h"
#include <list>
#include <iterator>
#ifndef STACK_H_
#define STACK_H_
using namespace std;

class stack {

private:
	// Members
    //int top;  //top is not needed as it is controlled in the list implementation
    //int maxSize; // max size is not needed because we are not using a size defined array
    list<string> sList; 
public:
	stack();
	stack(int s);
	virtual ~stack();
    void push(string);
    string pop();
	bool isFull();
	bool isEmpty();
    string peek();
	int size();
    string printStackUp();
};

#endif /* STACK_H_ */
