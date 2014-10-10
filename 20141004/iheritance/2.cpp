#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;
class person {
public:
    person () :name_(""),age_(0) {}
    person ( const string name,size_t age)
        : name_(name),age_(age)
    {}

 //   virtual ~person ();

    void  print() const
    {
        cout  << "name :" << name_ << "age :" <<age_<<endl;
    }

protected:
    string name_;
    size_t age_;
    /* data */
};
class student :public person
{
    public:
        void test()
        {
            cout << "test" <<endl;
        }
        void print() const
        {
            cout << "school :" << school_ <<endl;
        }
    private:
        string school_;
};
int main(int argc, const char *argv[])
{
    student stu;
    stu.print();
    stu.test();
    return 0;
}

