#ifndef QUEUE_H
#define QUEUE_H
#include <string>
#include <list>
#include <iterator>
using namespace std;

class queue
{
private:
    // Members
    //int head; //head and tail not needed as they are controlled in list library functions begin(), end(), pop_front(), etc
    //int tail;
    //int queueSize; //not needed as a list method will return this value
    //int maxSize;  //maxSize not used on a list based queue as it is very large
    list<string> qList;
public:
    queue();
    queue(int s);
    virtual ~queue();
    void enqueue(string);
    string dequeue();
    bool isFull();
    bool isEmpty();
    string peek();
    int size();
    string printQueue();
};

#endif // QUEUE_H
