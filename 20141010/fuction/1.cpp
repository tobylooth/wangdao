#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <functional>
using namespace std;
void foo(const string &s)
{
    cout << s << endl;
}

int main(int argc, const char *argv[])
{
    void (*pFunc) (const string &) = &foo;
    pFunc("adfgasgasg");

    function<void (const string &s) > f=&foo;
    f("eeeee");
    return 0;
}
