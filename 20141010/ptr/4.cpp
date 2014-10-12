#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <memory>
using namespace std;
class Test
{
    public:
        Test() { cout << "Test" << endl; }
        ~Test() { cout << "~Test " << endl; }

    private:
        Test( const Test &) ;
        void operator=( const Test &);
};
int main(int argc, const char *argv[])
{
    vector<unique_ptr<Test> > coll;
    coll.push_back(unique_ptr<Test> (new Test));
    return 0;
}
