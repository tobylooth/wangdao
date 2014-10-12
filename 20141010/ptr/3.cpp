#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <memory>
using namespace std;

class Test
{
    public:
        Test() { cout << " Test " << endl; }
        ~Test() { cout << "~Test " << endl; }

        Test ( Test &&t)
        { cout << "move " << endl; }
        Test & operator=(Test &&t)
        {}
    private:
        Test( const Test &);
        void operator=(const Test &);
};

int main(int argc, const char *argv[])
{
    vector<Test> coll;
    coll.push_back(Test());
    return 0;
}
