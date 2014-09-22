#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <stdexcept>
using namespace std;

void delPunct(string &s)
{
    string::iterator it=s.begin();
    while(it!=s.end())
    {
        if(ispunct(*it))
            it=s.erase(it);
        else
            ++it;
    }
}
void add_to_vector(vector<WORD> &vec,const string &temp)
{
    WORD wordtemp;
    for(vector<WORD>::iterator it=vec.begin();
            it!=vec.end();
            ++it)
    {
        if((*it).word==temp)
        {
            (*it).count++;
            return;
        }
    }
    wordtemp.word=temp;
    wordtemp.count=1;
    vec.push_back(wordtemp);
}
void del_from_vector(vector<WORD> &vec,const string &temp)
{
    for(vector<WORD>::iterator it=vec.begin();
            it!=vec.end();
            )
    {
        if((*it).word==temp)
        {
            it=vec.erase(it);
        }
        else
        {
            ++it;
        }
    }
}
int main(int argc,char *argv[])
{
    if(argc!=3)
    {
        printf("Usage");
        exit(EXIT_FAILURE);
    }
    string filename=argv[1];
    string tablename=argv[2];
    vector<WORD> vec;
    ifstream infile(filename.c_str());
    if(!infile)
        throw runtime_error("cannot open file");
    string temp;
    WORD wordtemp;
    while(infile >> temp)
    {
        delPunct(temp);
        toLower(temp);
        add_to_vector(vec,temp);
    }
    infile.close();
    infile.open(tablename.c_str());
    if(!infile)
        throw runtime_error("cannot open file");
    while(infile >> temp)
    {
        del_from_vector(vec,temp);
    }
    infile.close();
    for(vector<WORD>::iterator it=vec.begin();
            it!=vec.end();++it)
    {
        if((*it).count>500)
        cout << (*it).word <<"  :  "<<(*it).count << endl;
    }
    return 0;
}



























