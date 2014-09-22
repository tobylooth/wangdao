#include <iostream>
#include <string>
using namespace std;
int main()
{
    void uptolower(string &s);
    string s;
    cout<<"input a string"<<endl;
    cin>>s;
    uptolower(s);
    cout<<s<<endl;
    return 0;
}
void uptolower(string &s)

{
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>'A'&&s[i]<'Z')
            s[i]=s[i]-'A'+'a';
        else
            s[i]=s[i]-'a'+'A';
    }

}
