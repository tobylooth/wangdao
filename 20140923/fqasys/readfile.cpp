#include "fqa_head.h"
 using namespace std;

 void readfile(string &filename,vector<User> &user_)
{
    string line;
    User utemp;
    ifstream infile(filename.c_str());
    if(!infile)
        throw runtime_error("cannot open file");
    while(getline(infile,line))
    {
        istringstream in(line);
        in >> utemp.name;
        in >>utemp.passwd;
       // sscanf(line,"%s%s",utemp.name,&utemp.passwd);
        user_.push_back(utemp);
    }
    infile.close();
}
