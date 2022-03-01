/**************************************************************
* Name        : List based Stack
* Author      : William Thomas
* Created     : 02/21/2022
* Course      : CIS 152 – Data Structures
* Version     : 1.0
* OS          : Windows 10
* Copyright   : This is my own original work based on
*               specifications issued by our instructor
* Description : Stack.cpp skeleton provided by instructor. Methods filled in
*               by William. Utilizing STL list library.
*               Input:  list and describe
*               Output: list and describe
* Academic Honesty: I attest that this is my original work.
* I have not used unauthorized source code, either modified or
* unmodified. I have not given other fellow student(s) access to
* my program.
***************************************************************/

#include <iostream>
#include "stack.cpp"

using namespace std;


/*DRIVER
 * tests for isFull were not included because a full list has 768,614,336,404,564,650 elements and filling to that size takes a while...
*/
int main() {
    int ELEMENTS = 10;
    stack myStack = stack();
    stack myStack2 = stack();
    string item = "test-";
    cout << "Using push method to fill list with number of elements defined in constant.\n" << endl;
    for (int i = 1; i <= ELEMENTS; i++) {
        myStack.push(item + to_string(i));
    }
    cout << "Print stack up for filled stack" << endl;
    cout << myStack.printStackUp() << endl << endl;
    cout << "Print stack size" << endl;
    cout << myStack.size() << endl << endl;
    cout << "Utilize try/catch. Print empty stack (should catch exception)" << endl;
    try {
        cout << myStack2.printStackUp() << endl << endl;
    }
    catch (StackEmptyException e) {
        cout << "Exception encountered: " << e.getMessage() << endl << endl;;
    }
    cout << "Print empty stack size" << endl;
    cout << myStack2.size() << endl << endl;
    cout << "Check empty stack is empty (should return true)" << endl;
    cout << boolalpha << myStack2.isEmpty() << endl << endl;
    cout << "Check filled stack is empty (should return false)" << endl;
    cout << boolalpha << myStack.isEmpty() << endl << endl;
    cout << "Check peek method and reprint list to verify no removal occurs" << endl;
    cout << myStack.peek() << endl << endl;
    cout << "Print List:\n" << myStack.printStackUp() << endl << endl;
    cout << "Pop element from stack. Displays popped item and reprints stack" << endl;
    cout << "Popped: " << myStack.pop() << endl;
    cout << "\nPrint List:\n" << myStack.printStackUp() << endl;
    cout << "Push element onto stack. 'AABBCC'" << endl;
    myStack.push("AABBCC");
    cout << "\nPrint List:\n" << myStack.printStackUp() << endl << endl;
    return 0;
}
