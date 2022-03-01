/**************************************************************
* Name        : List Based Stack Lab
* Author      : William Thomas
* Created     : 02/21/2022
* Course      : CIS 152 – Data Structures
* Version     : 1.0
* OS          : Windows 10
* Copyright   : This is my own original work based on
*               specifications issued by our instructor
* Description : Queue.cpp skeleton provided by Instructor Ruse. Methods filled in
*               by William.
*               Input:  N/A
*               Output: N/A
* Academic Honesty: I attest that this is my original work.
* I have not used unauthorized source code, either modified or
* unmodified. I have not given other fellow student(s) access to
* my program.
***************************************************************/

#include <iostream>
#include "queue.cpp"

using namespace std;

int main() {
    cout << "Creating queue." << endl;
    queue myQueue = queue();
    cout << "\nTesting if queue is empty (should return true)" << endl;
    cout << boolalpha << myQueue.isEmpty() << endl;
    cout << "\nAdding 5 elements to the queue" << endl;
    for (int i = 0; i < 5; i++) {
        myQueue.enqueue("Test" + to_string(i));
    }
    cout << "\nTesting if queue is empty (should return false)" << endl;
    cout << boolalpha << myQueue.isEmpty() << endl;
    cout << "\nPrint Queue:\n" << myQueue.printQueue() << endl;
    cout << "\nChecking for queue size (should be 5)" << endl;
    cout << "Size: " << myQueue.size() << endl;
    cout << "\nTesting peek" << endl;
    cout << "Peek: " << myQueue.peek() << endl;
    cout << "\nVerify peek did not remove item from queue" << endl;
    cout << myQueue.printQueue() << endl;
    cout << "\nTesting dequeue" << endl;
    cout << "\nDequeued item: " << myQueue.dequeue() << endl;
    cout << "\nPrint Queue:\n" << myQueue.printQueue() << endl;
    cout << "\nCreated another queue to test dequeue on empty" << endl;
    queue emptyQueue = queue();
    cout << "\nTesting dequeue on empty queue (should catch exception)" << endl;
    try {
        emptyQueue.dequeue();
    }  catch (queueEmptyException e) {
        cout << "Exception caught: " << e.getMessage() << endl;
    }
    cout << "\nDequeueing twice and enqueue once to verify FIFO" << endl;
    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.enqueue("NEW");
    cout << "\nPrint Queue:\n" << myQueue.printQueue() << endl;
    return 0;

}
