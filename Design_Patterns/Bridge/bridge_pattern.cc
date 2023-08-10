#include <iostream>
#include <memory>

using namespace std;

//PImpl
// pointer to all private fields of class A 
// are abstracted to an implementation class AImpl.
// This allows for faster compilation and better coupling

class AImpl{
    int x = 0;
    int y = 1;
    string d = "test";
};

class A{
    unique_ptr<AImpl> pimpl;
    public:
        A():pimpl{unique_ptr<AImpl>()}{}
};

// bridge patter - factor out the implementation

int main(){
    A a;
    return 0;
}
