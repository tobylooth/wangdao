#include <memory>
#include <iostream>
#include <string>
using namespace std;

class Parent;
class Child;
typedef shared_ptr<Parent> parentptr_;
typedef shared_ptr<Child> childptr_;

class Parent
{
    public:
        ~Parent () { cout << "~Parent " << endl; }
        childptr_ child_;
};
class Child
{
    public:
        Child( const parentptr_ parent)
            :parent_(parent)
        {

        }
        ~Child () { cout << "~Child " << endl; }
        std::weak_ptr<Parent> parent_;
};
int main(int argc, const char *argv[])
{
    {
        parentptr_  parent(new Parent);
        childptr_ child(new Child(parent));

        parent->child_= child;

        cout << "Parent count :" << parent.use_count()
            << endl;
        cout <<" Child count :"<< child.use_count()
            << endl;
    }




    return 0;
}
