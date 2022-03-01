/**************************************************************
* Name        : Library Based Priority Queue
* Author      : William Thomas
* Created     : 02/28/2022
* Course      : CIS 152 – Data Structures
* Version     : 1.0
* OS          : Windows 10
* Copyright   : This is my own original work based on
*               specifications issued by our instructor
* Description : STL Priority Queue
*               Input:  N/A
*               Output: N/A
* Academic Honesty: I attest that this is my original work.
* I have not used unauthorized source code, either modified or
* unmodified. I have not given other fellow student(s) access to
* my program.
***************************************************************/

//  rand() % min + max;


#include <queue>
#include <iostream>
#include <list>
#include <string>
#include <cstdlib>
#include <time.h>

using namespace std;


int main()
{
    srand(time(NULL));
    const int MAX = 100;
    //create list of 100 customers
    list<int> myList;
    cout << "Filling list with customers" << endl;
    for (int i = 0; i < MAX; i++) {
        myList.push_back(i);
    }
    //create priority queue
    priority_queue<int> pq;
    cout << "Creating and filling priority_queue" << endl;
    for (int i = 0; i < MAX; i++) {
        int temp = rand() % 5 + 1;
        pq.push(temp);
    }
    cout << endl;
    cout << "My List Size: " << myList.size() << endl;
    cout << "Print list" << endl;
    for (auto const &a: myList) {
        cout << a << " ";
    }
    cout << endl << endl;
    cout << "Priority Queue Size: " << pq.size() << endl;
    cout << "Print Priority Queue" << endl;
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}


