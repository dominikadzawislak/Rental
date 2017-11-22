//klasa Status
#ifndef STATUS_H_
#define STATUS_H_
//#include <iostream>

using namespace std;

class Status
{
//skladniki prywatne
protected:
    int numer;

//skladniki publiczne
public:
    Status();
    virtual ~Status();
    virtual void zmienStatusT(int numer)=0;
    virtual void zmienStatusF()=0;
};

#endif // STATUS_H_
