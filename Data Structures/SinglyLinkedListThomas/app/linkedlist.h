#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <list>
#include "can.h"
#include "listemptyexception.h"
#include "listfullexception.h"

struct Node {
public:
    Can can;
    Node* next;
    Node();
};

class LinkedList
{
private:
    list<Can> listCans;
    Node *head,*tail;
public:
    LinkedList();
    //LinkedList(Can);
    bool isFull();
    bool isEmpty();
    void insert(Can);
    void remove(int);
    int size();
    string printList();
};

#endif // LINKEDLIST_H
