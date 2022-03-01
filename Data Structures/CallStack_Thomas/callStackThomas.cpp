/**************************************************************
* Name        : Call Stack
* Author      : William Thomas
* Created     : 01/31/2022
* Course      : CIS 152 – Data Structures
* Version     : 1.0
* OS          : Windows 10
* Copyright   : This is my own original work based on
*               specifications issued by our instructor
* Description : This program is a play-around to understand the call-stack
*               Input:  list and describe
*               Output: list and describe
* Academic Honesty: I attest that this is my original work.
* I have not used unauthorized source code, either modified or
* unmodified. I have not given other fellow student(s) access to
* my program.
***************************************************************/
#include <iostream>
using namespace std;

void method1() {
    cout << "Entering method1." << endl;
    cout << "Exiting method1." << endl;
}

void method2() {
    cout << "Entering method2." << endl;
    cout << "Exiting method2." << endl;
}

void method3() {
    cout << "Entering method3." << endl;
    cout << "Exiting method3." << endl;
}

void method4() {
    cout << "Entering method4." << endl;
    method1();
    method2();
    method3();
    cout << "Exiting method4." << endl;
}

int main() {
    cout << "In Main Method." << endl;

    method1();
    method2();
    method3();
    method4();

    cout << "Exiting Main Method." << endl;
}
