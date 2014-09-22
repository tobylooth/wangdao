#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <fstream>
using namespace std;
void delPunct(string &word)
{
    string::iterator it=word.begin();
    while(it!=word.end())
    {
        if(ispunct(*it))
            it=word.erase(it);
        else
            ++it;
    }
}
void stringToLower(string &word)
{
    for(string::iterator it=word.begin();
            it!=word.end();
            ++it)
    {
        if(isupper(*it))
        {
            *it=tolower(*it);
        }
    }

}
int main(int argc, const char *argv[])
{
    if(argc!=3)
        throw runtime_error("wrong number of arguments");
    map<string, int> word_count;
    string key,word;
    int cnt;
    ifstream infile;
    infile.open(argv[2]);
    if(!infile)
        throw runtime_error("open file fail");
    set<string> set_;
    while(infile >> word)
    {
        delPunct(word);
        stringToLower(word);
        set_.insert(word);
    }
    infile.close();
    infile.open(argv[1]);
    if(!infile)
        throw runtime_error("open file fail");
    while(infile >> word)
    {
        delPunct(word);
        stringToLower(word);
        if(!set_.count(word))
             ++word_count[word];
    }
    infile.close();
    map<string,int>::const_iterator map_it=word_count.begin();
    while (map_it!=word_count.end())
    {
        if(map_it->second>=500)
        cout << map_it->first << "   occurs  "
            << map_it->second << "  times "<<endl;
        ++map_it;
    }
    return 0;
}
