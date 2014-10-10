#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
using namespace std;
class person {
public:
    person ():name_(""),age_(0){}
    void print()
    {
        cout << "name : " << name_ << "age :" << age_ <<endl;
    }

private:
    string name_;
    size_t age_;
    /* data */
};
class student:public person {
public:
    student ():school_(""){}
    void print()
    {
        cout << "school : " << school_ <<endl;
    }
private:
    string school_;
    /* data */
};


int main(int argc, const char *argv[])
{
    student stu;
    stu.person::print();
    stu.print();
    return 0;
}
