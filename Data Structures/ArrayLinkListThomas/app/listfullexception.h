#ifndef LISTFULLEXCEPTION_H
#define LISTFULLEXCEPTION_H
#include <string>
using namespace std;
class listFullException
{
private:
    string msg_;
public:
    listFullException(const string& msg) :
        msg_(msg) {
    }
    listFullException();
    ~listFullException() {}

    string getMessage() const {
        return (msg_);
    }
};

#endif // LISTFULLEXCEPTION_H
