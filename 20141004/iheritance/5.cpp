#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;
class parent
{
    public:
        parent() { cout << "parent " <<endl; }
        ~parent() { cout  << "~parent" << endl; }

};
class child : public parent
{
    public :
        child() {  cout << "child " << endl;
        }
        ~child() { cout << "~child " << endl;
        }
};
int main(int argc, const char *argv[])
{
    child d;

    return 0;

}
