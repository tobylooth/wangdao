#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main()
{
    string s;

    vector<string> vec;
    while(cin>>s)
    {
        vec.push_back(s);
    }
    for(vector<string>::size_type ix=0;ix<vec.size();ix++)
        cout<<vec[ix]<<endl;
    return 0;
}
