#include <memory>
#include <iostream>
#include <string>
using namespace std;
class Test
{
    public:
        Test() { cout << "Test "<< endl; }
        ~Test () { cout << " ~Test "<< endl; }
    private:
        Test(const Test &);
        void operator=(const Test &);
};

int main(int argc, const char *argv[])
{
    shared_ptr<Test> ptr(new Test);

    shared_ptr<Test> ptr2(ptr);

    cout << ptr.use_count() << endl;
    return 0;
}
