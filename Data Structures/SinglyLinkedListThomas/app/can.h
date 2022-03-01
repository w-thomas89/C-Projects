#ifndef CAN_H
#define CAN_H
#include <string>

using namespace std;

class Can
{
private:
    string company;
    string contents;
    double size;
    double price;
public:
    Can();
    Can(string, string, double, double);
    string getCompany();
    void setCompany(string);
    string getContents();
    void setContents(string);
    double getSize();
    void setSize(double);
    double getPrice();
    void setPrice(double);
    string toString();
};

#endif // CAN_H
