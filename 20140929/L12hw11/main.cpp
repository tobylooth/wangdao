#include "SmartPtr.hpp"

using namespace std;

int main(int argc, const char *argv[])
{
    SmartPtr_t<Animal> ptr(new Animal);
    cout << ptr.getptr() <<endl;
    ptr->run();

    ptr.resetPtr();

    cout << ptr.getptr()  << endl;
    ptr->run();



    return 0;
}
