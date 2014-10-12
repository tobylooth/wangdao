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
        ~Parent() { cout << "~Parent " << endl; }
        childptr_ child_;
};
class Child
{
    public:
        ~Child() { cout << "~Child " << endl; }
        parentptr_ parent_;
};
int main(int argc, const char *argv[])
{
    {
        shared_ptr<Parent> parent(new Parent);
        childptr_ child(new Child);
        parent->child_ =child;
        child->parent_ = parent;

        cout << "parent count : "<< parent.use_count()
            << endl;
        cout << "child count : " << child.use_count()
            << endl;
    }
    return 0;
}
