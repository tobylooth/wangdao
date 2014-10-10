#include "SmartPtr.h"
#include <iostream>
using namespace std;

int main(int argc, const char *argv[])
{
    SmartPtr ptr(new Animal);
    cout << ptr.getptr() <<endl;
    ptr->run();

    ptr.resetPtr();

    ptr.resetPtr(new Animal);
    cout << ptr.getptr() << endl;
    return 0;
}
