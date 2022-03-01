/**************************************************************
* Name        : InFix to PostFix Notation using Stacks
* Author      : William Thomas
* Created     : 02/06/2022
* Course      : CIS 152 – Data Structures
* Version     : 1.0
* OS          : Windows 10
* Copyright   : This is my own original work based on
*               specifications issued by our instructor
* Description : This program will take an input and create a
*               postfix notation using order of operations
*               derived from a stack
*               Input:  infix notation without spaces
*               Output: order of operations postfix
* Academic Honesty: I attest that this is my original work.
* I have not used unauthorized source code, either modified or
* unmodified. I have not given other fellow student(s) access to
* my program.
***************************************************************/


#include<stack>
#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

//checks if character is an operator
bool isOperator(char inVar) {
    if (inVar == '+' || inVar == '-' || inVar == '*' || inVar == '/' || inVar == '^') {
        return true;
    }
    else return false;
}

//creates precedence via order of operations PEMDAS returns integer value for comparison
int orderOfOperations(char inVar) {
    if (inVar == '^') return 3;
    else if (inVar == '*' || inVar == '/') return 2;
    else if (inVar == '+' || inVar == '-') return 1;
    else return -1;
}

//takes input string and references each character using order of operations and outputs postfix notation
string InfixToPostfix(stack<char> s, string input) {
    string inFix = input;
    string postFix;
    //loop through each character in input string
    for (unsigned int i = 0; i < inFix.size(); i++) {
        //checks to see if character is alphabetical and if so adds to postfix string
        if (isalpha(inFix.at(i))) {
            postFix += inFix.at(i);
        }
        //checks to see if character is numerical and if so adds to postfix string
        else if (isdigit(inFix.at(i))) {
            postFix += inFix.at(i);
        }
        //if character is opening parenthesis add to the stack - the P in PEMDAS
        else if (inFix.at(i) == '(') {
            s.push(inFix.at(i));
        }
        //if character is closing parenthesis
        else if (inFix.at(i) == ')') {
            //checks to see that opening parenthesis is not at top of stack and stack is not empty
            while ((s.top() != '(') && (!s.empty())) {
                //temp used to hold variable value from stack and add to postfix string
                char tempVar = s.top();
                postFix += tempVar;
                s.pop();
            }
            //checks stack for opening bracket and pops if found
            if (s.top() == '(') {
                s.pop();
            }
        }
        //checking for remaining operators - EMDAS of the PEMDAS
        else if (isOperator(inFix.at(i))) {
            //if stack is empty add operator to the stack
            if (s.empty()) {
                s.push(inFix.at(i));
            }
            //uses function to check precedence via returned integer value
            else {
                //if precedence is higher, pushes the variable onto the stack
                if (orderOfOperations(inFix.at(i)) > orderOfOperations(s.top())) {
                    s.push(inFix.at(i));
                }
                else {
                    //while stack is not empty and variable is less than or equal to top of stack, pop from stack and add to postfix string
                    while ((!s.empty()) && (orderOfOperations(inFix.at(i)) <= orderOfOperations(s.top()))) {
                        postFix += s.top();
                        s.pop();
                    }
                    //add variable to stack
                    s.push(inFix.at(i));
                }
            }
        }
    }
    //empty the remaining contents of stack until empty
    while (!s.empty()) {
        postFix += s.top();
        s.pop();
    }
    //return string
    return postFix;
}

//DRIVER
int main() {
    //using an array of predefined variables for output
    string inSolve[6] = {"2+3*4", "a*b+5", "(1+2)*7", "a*b/c", "(a/(b-c+d))*(e-a)*c", "a/b-c+d*e-a*c"};
    string inFix, postFix;
    stack <char> postfixStack;
    //loop through array to output each predefined set
    for (auto var: inSolve) {
        cout << "*************************" << endl;
        cout << "Infix: " << var << endl;
        cout << "Postfix: " << InfixToPostfix(postfixStack, var) << endl; //utilizing the code, we process each part of array for consistent output

    }
    cout << "\nEnter infix notation with no spaces:" << endl;
    cin >> inFix;

    postFix = InfixToPostfix(postfixStack, inFix);
    cout << "*************************" << endl;
    cout << "Infix: " << inFix << endl;
    cout << "Postix: " << postFix << "\n\n";
    return 0;
}
