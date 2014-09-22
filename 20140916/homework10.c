#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
void flitcomma(string &s);
    string s;
    while(cin>>s)
    {
        flitcomma(s);
        cout<<s<<endl;
    }

}
void flitcomma(string &s)
{
    string s1,s2="a";
    for(string::size_type ix=0;
            ix!=s.size();
            ++ix)
    {
        if(s[ix]==' '||(s[ix]>='0'&&s[ix]<='9')||(s[ix]>='a'&&s[ix]<='z')||(s[ix]>='A'&&s[ix]<='Z'))
        {
            s2[0]=s[ix];
            s1+=s2;
        }
    }
    s=s1;
}
