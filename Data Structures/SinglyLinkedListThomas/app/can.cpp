#include "can.h"
#include <sstream>
#include <iomanip>

using namespace std;

Can::Can()
{
    company = "";
    contents = "";
    size = 0;
    price = 0;
}

Can::Can(string company, string contents, double size, double price) {
    this->company = company;
    this->contents = contents;
    this->size = size;
    this->price = price;
}

string Can::getCompany() {
    return company;
}
void Can::setCompany(string company) {
    this->company = company;
}
string Can::getContents(){
    return contents;
}
void Can::setContents(string contents){
    this->contents = contents;
}
double Can::getSize(){
    return size;
}
void Can::setSize(double size){
    this->size = size;
}
double Can::getPrice(){
    return price;
}
void Can::setPrice(double price){
    this->price = price;
}
string Can::toString(){
    ostringstream ss;
        ss << fixed << setprecision(2);
        ss << "Company - " << company << ". Contents - " << contents << " Size - " << size << ". Price $" << price;
        //return stringstream using string conversion
        return ss.str();
}
