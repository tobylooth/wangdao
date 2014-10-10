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
#include <sstream>
#include <stdio.h>
using namespace std;
typedef struct student_s
{
    string id;
    string name;

    int score;
}Stu,*pStu;
     bool passstu(const Stu &a)
    {
        return a.score > 60;
    }
    bool getscore(const Stu  &a,const Stu &b)
    {
        return a.score < b.score ;
    }
class student {
public:
    void readfile(const string filename)
    {
        string line;
        Stu stu_temp;
        ifstream infile;
        infile.open(filename.c_str());
        if(!infile)
            throw runtime_error("cannot open file");
        while(getline(infile,line))
        {
            sscanf(line.c_str(),"%s %s %d",stu_temp.id.c_str(),stu_temp.name.c_str(),
                    &stu_temp.score);
            stu_.push_back(stu_temp);
        }
        infile.close();
    }
    void countpass()
    {
        int stucnt=0;
        stucnt=std::count_if(stu_.begin(),stu_.end(),passstu);
        cout << stucnt <<"students passed the exam" <<endl;
    }
    void findhighest()
    {
        vector<Stu>::iterator high_it;
        high_it=std::max_element(stu_.begin(),stu_.end(),getscore);
        cout << " the highest score is " << (*high_it).score <<  endl;
    }
    void dojob(const string name)
    {
        readfile(name);
        countpass();
        findhighest();
    }
private:
        string filename_;
        vector<Stu> stu_;
    /* data */
};
int main(int argc, const char *argv[])
{
    student student_c;
    student_c.dojob(argv[1]);
    return 0;
}
