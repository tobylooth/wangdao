#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdexcept>
using namespace std;
int main()
{
    string s;
    string filename="output.txt";
    ofstream outfile(filename.c_str());
    if(!outfile)
    {
        throw runtime_error("cannot open file");
    }
    while(cin>>s)
    {
        outfile<<s<<endl;
    }
    outfile.close();


}

