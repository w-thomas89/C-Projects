#ifndef LISTEMPTYEXCEPTION_H
#define LISTEMPTYEXCEPTION_H
#include <string>
using namespace std;

class listEmptyException
{
private:
    string msg_;
public:
    listEmptyException(const string& msg) :
        msg_(msg) {}
    listEmptyException();
    ~listEmptyException() {}

    string getMessage() const {
        return (msg_);
    }
};

#endif // LISTEMPTYEXCEPTION_H
