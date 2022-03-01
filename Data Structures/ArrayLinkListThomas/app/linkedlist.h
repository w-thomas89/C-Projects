#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <string>

using namespace std;

class LinkedList
{
private:
    //variables
    double value;
    int maxSize, listSize, head, next;
    double *listItems{nullptr};
public:
    //default constructor
    LinkedList();
    //args passed constructor
    LinkedList(int size);
    virtual ~LinkedList();
    bool isFull();
    bool isEmpty();
    void insert(double, int);
    double get(int);
    void remove(double);
    void replace(double, double);
    int size();
    string printList();
};

#endif // LINKEDLIST_H
