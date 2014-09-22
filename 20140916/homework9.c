#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    string integerToString(int a);
    int a;
    cout<<"intput a number"<<endl;
    while(cin>>a)
    {
        cout<<integerToString(a)<<endl;
    }
return 0;
}
string integerToString(int a)
{
    string s,s1="0",s2;
    int count=0;
    while(a>0)
    {
        s1[0]=a%10+'0';
        s=s+s1;
        a/=10;
    }
    s2=s;
    for(string::size_type ix=0;
            ix!=s.size();
            ++ix)
    {
        s2[ix]=s[s.size()-ix-1];
    }
    return s2;

    }


