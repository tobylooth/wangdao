#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;
class base
{
    public:
        base() {
            cout << "base " <<endl ;
        }
        ~base() {
            cout << "~base " << endl;
        }
};
class other
{
    public :
        other () { cout << "other " << endl; }
        ~other() {
            cout << "~other " << endl;
        }
};
class dirived:public base
{
    public :
        dirived()
        { cout << "derived " << endl;
        }
        ~dirived ()
        {
            cout <<" ~derived " <<endl ;
        }
    private:
        other other_;
};
int main(int argc, const char *argv[])
{
    dirived d;
    return 0;


}
