#include "fqa_head.h"
using namespace std;
void readproblem( string &filename,vector<Prob> &prob_v)
{

    ifstream infil;
    infil.open("problem.txt");
    if(!infil)
        throw runtime_error("cannot  open problem file");
    int count=1;
    string pro_id;
    Prob probnew;
    string line;
    while(infil >> pro_id && count<=N)
    {
        probnew.showid=count;
        probnew.probId=atoi(pro_id.c_str());
        getline(infil,line);
        probnew.probBody=line;
        getline(infil,line);
        probnew.opt_A=line;
        getline(infil,line);
        probnew.opt_B=line;
        getline(infil,line);
        probnew.opt_C=line;
        getline(infil,line);
        probnew.opt_D=line;
        prob_v.push_back(probnew);
        count++;
    }
    cout << "readout "<< count-1 << "problems" <<endl;
    infil.close();
}
