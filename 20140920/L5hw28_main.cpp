#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <sstream>
using namespace std;
void find_word(const vector<string> &vec,const string s)
{
    for(vector<string>::const_iterator it=vec.begin();
        it!=vec.end();
        ++it)
    {
        if(strstr((*it).c_str(),s.c_str())!=NULL)
            cout << *it <<endl;
    }


}
int main(int argc, const char *argv[])
{
    if(argc!=2)
        throw runtime_error("argument error");

    vector<string> vec_file,vec_query;
    string tempstr,line;
    ifstream infile;
    infile.open(argv[1]);
    if(!infile)
        throw runtime_error("cannot open file");
    while(infile >> tempstr)
    {
        vec_file.push_back(tempstr);
    }
    infile.close();
    cout << "input what you are want to query"<<endl;
    while(getline(cin,line))
    {
        cout << "input what you are want to query"<<endl;
        istringstream instream(line);
        while(instream >> tempstr)
        {
            find_word(vec_file,tempstr);
        }

    }
    return 0;
}
