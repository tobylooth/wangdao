#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
using namespace std;
class statistic {
public:
    void setfilename(const string filename)
    {
        filename_=filename;
    }
    void dostatistic()
    {
        cout << "in dostatistic " << endl;
        pair<string,int> wordpair;
        string str;
        ifstream infile(filename_.c_str());
        if(!infile)
            throw runtime_error("cannot open file");
         while(infile >> str)
         {
             int flag=0;
             vector<pair<string,int> >::iterator it=vec.begin();
             while(it!=vec.end())
             {
                 if(str==it->first)
                 {
                     it->second++;
                     flag=1;
                     break;
                 }
                 ++it;
             }
             if(flag==0)
             vec.push_back(make_pair(str,1));
         }
         infile.close();
         cout <<" dostatistic " << endl;
    }
    void word_sort()
    {
        cout << "int sort " << endl;
        sort(vec.begin(),vec.end(),Cmp);

        vector<pair<string,int> >::iterator it=vec.begin();
        while(it!=vec.end())
        {
            cout << it->first << "   "<< it->second << endl;
            ++it;
        }
        cout << "out sort "<< endl;

    }
   static bool Cmp(pair<string,int> &a,pair<string,int> &b)
    {
        return a.second>b.second;
    }
    void doit(const string name)
    {
        cout << "int doit "<< endl;
        setfilename(name);
        dostatistic();
        word_sort();
        cout << "out doit "<<endl;
    }

private:
    string filename_;
    vector<pair<string,int> > vec;
    /* data */
};
int main(int argc, const char *argv[])
{
    if(argc!=2)
        throw runtime_error("Usage argument error");
    statistic word_statis;
    string s=argv[1];
    word_statis.doit(s);
    return 0;
}
