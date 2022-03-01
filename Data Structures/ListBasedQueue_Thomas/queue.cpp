/***************************************************************
* Name        : Queue
* Author      : Reed James
* Created     : 17 Feb 2021
***************************************************************/

#include "queue.h"
#include "queueemptyexception.h"
#include "queuefullexception.h"
#include <iostream>
#include <string>

using namespace std;

/**************************************************************
* Constructors
***************************************************************/
/**************************************************************
* Name: Queue
* Description: Default no-arg constructor
* Input parameters: none
***************************************************************/

queue::queue()
{
    list<string> qList;
}
/**************************************************************
* Name: Queue
* Description: Constructor that accepts s
* Input: input s (max size)
***************************************************************/
queue::queue(int s){
    qList.resize(s);
}
/**************************************************************
* Name: ~Queue
* Description: Destructor
* Input parameters: none
***************************************************************/
queue::~queue(){}
/***************************************************************
* Class Functions
***************************************************************/
/**************************************************************
* Name: Queue
* Description: methods
* Input: string
* Output: queue list
***************************************************************/
void queue::enqueue(string item){
    //if queue is full throw exception else push item to back
    if (isFull()) {
        throw queueFullException("Queue is full");
    }
    qList.push_back(item);
}

string queue::dequeue(){
    //if queue is empty, throw exception because there is nothing to dequeue
    if (isEmpty()) {
        throw queueEmptyException("Queue is empty");
    }
    //assign temp variable for return and remove from queue
    string item = peek();
    qList.pop_front();
    return item;
}

bool queue::isFull(){
    //will return true if list<> is full
    return size() == (int)qList.max_size();
}
bool queue::isEmpty(){
    //returns true if list is empty
    return size() == 0;
}

string queue::peek(){
    //if empty, throw exception, else return front of the queue
    if (isEmpty()) {
        throw queueEmptyException("Queue is empty");
    }
    return qList.front();
}

int queue::size(){
    //return int value of list size
    return qList.size();
}

string queue::printQueue(){
    string StackString = "";
    //iterate through queue and print first to last
    for (auto it = qList.begin(); it != qList.end(); it++) {
        StackString += *it + "\n";
    }
    return StackString;
}
