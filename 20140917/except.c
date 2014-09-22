#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

int main()
{
    float a,b;
    while(1)
    {
        try
        {
            cout<<"intput a and b:";
            cin>>a>>b;
            if(b==0.0)
                throw runtime_error("runtime error,divisor cannot be 0");
            cout<<a/b<<endl;
        }
        catch(exception &e)
        {
            cout<<"exception:  "<<e.what()<<endl;
        }
    }
    return 0;

}
