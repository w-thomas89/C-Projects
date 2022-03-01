//William Thomas, wdthomas2@dmacc.edu, 4-11-2021
//This program takes input from user to create Students names and grades and outputs data


#include <iostream>
#include <vector>
using namespace std;


//Student class
class Student   {
private:
    string firstName;
    string lastName;
    double GPA;
public:
    Student(){      //default constructor
        firstName = "";
        lastName = "";
        GPA = 0.0;
    }
    string getFirstName(){  //getter function for First Name
        return firstName;
    }
    void setFirstName(string first_name){   //setter function for First Name
        firstName = first_name;
    }
    string getLastName(){   //getter function for Last Name
        return lastName;
    }
    void setLastName(string last_name){     //setter function for Last Name
        lastName = last_name;
    }
    double getGPA(){        //getter function for GPA
        return GPA;
    }
    void setGPA(double grade){          //setter function for GPA
        GPA = grade;
    }
};


//MAIN PROGRAM BODY
int main(){
    int qty;
    string first;
    string last;
    double gradePoint;
    vector<Student> listOfNames;    //Student class vector

    cout << "Enter the number of students." << endl;
    cin >> qty;
    while (qty < 0){
        cout << "You must enter a valid number of students greater than zero." << endl;
        cin >> qty;
    }
    //loop to get input of all students designated
    for (int i = 0; i < qty; ++i){
        cout << "Enter first name of student " << i+1 << endl;
        cin >> first;
        cout << "Enter last name of student " << i+1 << endl;
        cin >> last;
        cout << "Enter the GPA of " << first << " " << last << " in decimal form." << endl;
        cin >> gradePoint;
        while ((gradePoint <= 0) || (gradePoint > 4)){
            cout << "GPA must be a valid number greater than 0 and less than 4." << endl;
            cin >> gradePoint;
        }
        Student *student1 = new Student;
        student1->setFirstName(first);
        student1->setLastName(last);
        student1->setGPA(gradePoint);
        listOfNames.push_back(*student1);
        }

    cout << endl;
    cout << "The data for all " << qty << " students is:" << endl;
    cout << endl;
    //iterator function to work through student vector for output of data
    vector<Student>::iterator step;

    //loop to output student vector information.
    for (step = listOfNames.begin(); step != listOfNames.end(); ++step){
        cout << step->getFirstName() << " " << step->getLastName() << endl;
        cout << "GPA is: " << step->getGPA() << endl;
        cout << endl;
    }


return 0;

}


//TESTING DATA
//Tested using Bill Thomas for name. GPA set to 3.9. expected output "Bill Thomas /n GPA is 3.9"    Worked as expected.
//Tested validity input of GPA with outlier (less than 0, and greater than 4). Expect endless loop until valid. Worked as expected.
//Tested validity input of number of student. Expect any number less than 0 to prompt new input. worked as expected.
//Tested using 5 names, with 5 random GPA.  Expect output to verify student name and GPA linked.    Worked as expected.
//Test student count of ZERO causes all to close. Worked as expected.


