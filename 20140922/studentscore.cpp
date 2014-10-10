#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <fstream>
#include <queue>
#include <sstream>
using namespace std;
struct student
{
    string id;
    string name;
   string  score;
}Stu,*pStu;
struct cmp
{
    bool operator()(student a,student b)
    {
        if(a.score==b.score)
        {
            if(a.name==b.name)
            {
                return a.id>b.id;
            }
            else
                return a.name>b.name;
        }
        else
        {return a.score>b.score;}
    }
};
int main(int argc, const char *argv[])
{
    if(argc!=2)
        throw runtime_error("Usage argument");
    ifstream infile;
    string line;
    priority_queue<student,vector<student>,cmp> stu_ord;
   struct student stu_new;
    infile.open(argv[1]);
    if(!infile)
        throw runtime_error("cannot open file");
    while(infile >> line)
    {
        string temp;
        istringstream instream(line);
        instream >> temp;
        stu_new.id=temp;
        instream >> temp;
        stu_new.name=temp;
        instream >> temp;
      //  stu_new.score=atof(temp.c_str());
      //  stu_new.score=temp;
        stu_ord.push(stu_new);
    }
    while(!stu_ord.empty())
    {
        cout<< stu_ord.top().id << "  " << stu_ord.top().name
            <<"  "<< stu_ord.top().score<<endl;
        stu_ord.pop();
    }
    return 0;
}
