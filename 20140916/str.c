#include <string>
#include <iostream>
using namespace std;
int main()
{
    string s="hello world";
    int i;
    for(i=0;i<s.size();i++)
    {
        cout<<s[i]<<"  ";
    }
    cout<<endl;
    return 0;
}

