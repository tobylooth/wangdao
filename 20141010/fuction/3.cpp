#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <functional>
using namespace std;
class Foo
{
    public:
        void foo( int i)
        { cout << i << endl; }
        static void bar (double d)
        { cout << d << endl; }

};
int main(int argc, const char *argv[])
{
    Foo f;
    (mem_fun(&Foo:: foo))(&f,123);

    function<void (int) > pf = bind(&Foo::foo,
                                    &f,
                                    std::placeholders::_1);
        pf(123);
    function< void (Foo*,int) >pf2 = bind(& Foo::foo,
                                     std::placeholders::_1,
                                     std::placeholders::_2);
    pf2(&f,234);

    function<void (int ,Foo*) > pf3= bind(&Foo::foo,
                                    std::placeholders::_2,
                                    std::placeholders::_1);
    pf3(567,&f);


    return 0;
}

