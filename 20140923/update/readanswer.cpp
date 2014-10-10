#include "fqa_head.h"
using namespace std;

void readanswer(string &filename,vector<Answer> &answer_v)
{
    ifstream infile(filename.c_str());
    if(!infile)
        throw runtime_error("cannot open answer file");
    Answer answer_temp;
    string line;
    while(getline(infile,line))
    {
       sscanf(line.c_str(),"%d %c",&answer_temp.probId,&answer_temp.answer_);
       answer_v.push_back(answer_temp);
    }
    infile.close();
}
