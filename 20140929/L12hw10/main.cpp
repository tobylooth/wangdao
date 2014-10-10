#include "stack.hpp"
#include <iostream>
using namespace std;
int main(int argc, const char *argv[])
{
    try
    {
        Stack_t<string> ss;
        ss.push("hellop");
        cout << ss.top() <<endl;
        Stack_t<int> s1;
        s1.push(7);

        cout <<  s1.top() << endl;
        s1.pop();

        s1.pop();

    }
    catch  (out_of_range &e)
    {
        cout << e.what() <<endl;
    }
    return 0;
}
