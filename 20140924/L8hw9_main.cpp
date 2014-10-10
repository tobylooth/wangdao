#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
#include <fstream>
using namespace std;
int main(int argc, const char *argv[])
{
    if(argc!=2)
        throw runtime_error("Usage wrong argument");
    ifstream infile;
    map<string,int> imap;
    multimap<int,string> sortmap;
    string s;
    int t;
    infile.open(argv[1]);
    if(!infile)
        throw runtime_error("cannot open file");
    while(infile >> s)
    {
        imap[s]++;
    }
    infile.close();
    map<string,int>::iterator it=imap.begin();
    while(it!=imap.end())
    {
        sortmap.insert(make_pair(it->second,it->first));
        ++it;
    }
    multimap<int,string>::reverse_iterator r_it=sortmap.rbegin();
    while(r_it!=sortmap.rend())
    {
        cout << r_it->second << "   " <<r_it->first << endl;
        ++r_it;
    }


    return 0;
}
