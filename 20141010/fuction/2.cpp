#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <functional>
using namespace std;
void foo(int i,double d)
{
    cout << i << d << endl;
}

int main(int argc, const char *argv[])
{
    function<void (int,double) > f=&foo;
    f(12,12.3);
    return 0;
}
