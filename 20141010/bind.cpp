#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <functional>
using namespace std;
void test(int i,double d,const string  &s)
{
    cout <<"i= " <<i<<"d= "<<d<<"S= "<<s<<endl;
}
int main(int argc, const char *argv[])
{
    function<void (int,double,const string&)> f0=&test;
    f0(12,3.14,"hello");

    // void (*)(int,double)
    string f;
    function<void (int ,double) > f1=
        bind( &test,
                std::placeholders::_1,
                std::placeholders::_2,
                f);
    f1(12,1.34);
    //void (*)(double,int,const string &)
    function<void (double,int,const string &) >f2=
        bind( &test,
                std::placeholders::_2,
                std::placeholders::_1,
                std::placeholders::_3);
    f2(2.22,2,f);
    //3. void (*)(const string &,int)
    int i0;
    double d;
    function<void (const string &,int) > f3=
        bind(&test,
                std::placeholders::_2,
                d,
                std::placeholders::_1
                );
    f3(f,3);
    //4void (*)(cosnt string &,int,double)
    function<void (const string &,int,double)>f4=
        bind(&test,
                std::placeholders::_2,
                std::placeholders::_3,
                std::placeholders::_1);
    f4("444",4,4.4);
    //5.void (*)(int)
    function<void (int)>f5=
        bind(&test,
                std::placeholders::_1,
                5.5,
                f);
    f5(5);
    //6 void (*) (const string &)
    function<void (const string &)>f6=
        bind(&test,
                6,6.6,
                std::placeholders::_1);
    f6("hello");
    //7. void (*)()
    function<void ()>f7=
        bind(&test,
                7,7.7,"7"

                );
    f7();
        return 0;
}
