#include <iostream>
#include <boost/scoped_ptr.hpp>
using namespace std;
using namespace boost;

class Test
{
    public:
        Test() { cout << "Test "<< endl; }
        ~Test()
          { cout << "~Test " << endl; }
};
int main(int argc, const char *argv[])
{
    scoped_ptr<Test> ptr( new Test);
    return 0;
}
