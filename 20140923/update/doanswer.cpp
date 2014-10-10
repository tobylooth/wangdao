#include "fqa_head.h"
using namespace std;
void doanswer(vector<Prob> &prob_v,vector<Answer> &answer_v,Rec &record,const string &user)
{
    int count =0, flag=N;
    int ith;
    record.count=0;
    while(flag>0)
    {
        ith=rand()%N;
        if(prob_v[ith].showid==0)
            continue;
        cout << prob_v[ith].probBody << "\n"
            << prob_v[ith].opt_A << "\n"
            << prob_v[ith].opt_B << "\n"
            << prob_v[ith].opt_C << "\n"
            << prob_v[ith].opt_D << endl;
        cout << ":";
        char select;
        int loopflag=0;
        while(cin >> select)
        {
            switch(select)
            {
                case 'a':
                case 'A':loopflag=1;break;
                case 'b':
                case 'B':loopflag=1;break;
                case 'c':
                case 'C':loopflag=1;break;
                case 'D':
                case 'd':loopflag=1;break;
                default:break;
            }
            if(loopflag==1)
                break;
            else
                cout << "input right option" << endl;
        }
        for(vector<Answer>::iterator an_it=answer_v.begin();
                an_it!=answer_v.end();
                ++an_it)
        {
            if(prob_v[ith].probId==(*an_it).probId)
            {
                if(select==(*an_it).answer_)
                {
                    record.count++;
                    cout << "correct" << endl;
                }
                flag--;
                break;
            }
        }
        prob_v[ith].showid=0;
    }
    record.name_=user;
    record.score=record.count*(100/N);
    record.percent=record.score;
    cout << "submit complete " << endl;
}
