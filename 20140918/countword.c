#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <fstream>

using namespace std;
int main(int argc,char *argv[])
{
    if(argc!=2)
        throw runtime_error("illegal input argument");
    string filename=argv[1];
    ifstream infile(filename.c_str());
    if(!infile)
        throw runtime_error("cannot open file");
    vector<string> vec;
    string temp;
    int count=0;
    while(!infile.eof())
    {
        infile >> temp;
        cout << temp << endl;
        vec.push_back(temp);
    }
    infile.close();
    cout << vec.size()<<endl;

}

