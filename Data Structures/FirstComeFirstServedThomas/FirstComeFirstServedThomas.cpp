/**************************************************************
* Name        : First Come First Served
* Author      : William Thomas
* Created     : 02/13/2022
* Course      : CIS 152 – Data Structures
* Version     : 1.0
* OS          : Windows 10
* Copyright   : This is my own original work based on
*               specifications issued by our instructor
* Description : Using a Queue, generates random sales from a queue with
*               a defined total allotment of tickets/customers
*               Input:  Commented out code for input from user in DRIVER
*               Output: Output tickets sold and customers left over without
* Academic Honesty: I attest that this is my original work.
* I have not used unauthorized source code, either modified or
* unmodified. I have not given other fellow student(s) access to
* my program.
***************************************************************/



#include <iostream>
#include <queue>
#include <time.h>
#include <sstream>

using namespace std;

//ticket sales queue function
string ticketSales(int inTicketCount) {
    //constants
    const int MAX_CUST = 1000;  //Maximum number of customers in line
    const int MIN_CUST = 1;     //Minimum number of customers in line
    const int MAX_TKT = 4;      //Maximum number of tickets per customer
    const int MIN_TKT = 1;      //Minimum number of tickets per customer
    //variables
    int i, lineLength, ticketsPer, totalTickets;
    //initialize
    totalTickets = inTicketCount;
    queue<int> custLine;    //create queue object
    srand(time(NULL));  //seed randomizer
    lineLength = rand() % (MAX_CUST + 1 - MIN_CUST) + MIN_CUST; //randomize line length minimum to maximum inclusive
    //populate the queue
    for(i = 1; i <= lineLength; i++) {
        custLine.push(i);
    }
    //ticketsPer = 0; //initialize to zero, to be randomized inside loop
    while ((totalTickets > 0) && (!custLine.empty())) {
        //generate random tickets per customer
        ticketsPer = rand() % (MAX_TKT + 1 - MIN_TKT) + MIN_TKT; //randomized ticket per minimum to maximum inclusive
        if (totalTickets >= ticketsPer) {
            totalTickets -= ticketsPer;
            //cout << "Customer " << custLine.front() << " is purchasing " << ticketsPer << "." << endl;
            //cout << "Remaining: " << totalTickets << " tickets." << endl;
        }
        else {
            //cout << "Not enough tickets for this customer. Moving on to next." << endl; //not enough tickets
            custLine.push(custLine.front()); //pushes current customer if not enough tickets to meet need. keeps unserved count.
        }
        custLine.pop(); //pops customer out of front of queue
        //cout << "Remaining customers: " << custLine.size() << endl;
    }
    //output final information to console
    /*cout << "Customers served: " << lineLength - custLine.size() << endl;
    *cout << "Remaining customers: " << custLine.size() << endl;
    *cout << "Leftover tickets: " << totalTickets << endl;
    *cout << "**************************\n";
    */
    stringstream out;
    out << "Customers served: " << (lineLength - custLine.size()) << "\n"
        << "Remaining customer: " << (custLine.size()) << "\n" << "Leftover tickets: "
        << (totalTickets) << "\n" << "*************************\n";
    return out.str();
}

//DRIVER
int main() {
    cout << "****10 Tickets****\n" << ticketSales(10);
    cout << "****100 Tickets****\n" << ticketSales(100);
    cout << "****1000 Tickets****\n" << ticketSales(1000);
    /* int tickets;
     * cout << "Input number of tickets to be sold" << endl;
     * cin >> tickets;
     * cout << "***USER INPUT***\n" << ticketSales(tickets);
    */
}
