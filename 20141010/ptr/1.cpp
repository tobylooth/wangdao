#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <memory>
using namespace std;
class Test
{
    public:
        Test() { cout << "Test " << endl; }
        ~Test() { cout << " ~Test " << endl; }
};

int main(int argc, const char *argv[])
{
    unique_ptr<Test> ptr(new Test);

    unique_ptr<Test> ptr2(std::move(ptr));
    unique_ptr<Test> ptr3;
    ptr3=std::move(ptr2);
    return 0;
}
