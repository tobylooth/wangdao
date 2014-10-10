#include "fqa_head.h"
using namespace std;
int main(int argc, const char *argv[])
{
    string user;
    user = login();
    cout << "user login" << endl;
    vector<Prob> prob_v;
    vector<Answer> answer_v;
    Rec record_;
    string s1=PROBLEMPATH;
    string s2=ANSWERPATH;
    cout << "before problem" << endl;
    readproblem(s1,prob_v);
    cout << "befor readanwer "<< endl;
    readanswer(s2,answer_v);
    cout << "before do answer "<<endl;
    doanswer(prob_v,answer_v,record_,user);

    cout << record_.name_ << "\n"
        << record_.score <<"\n"
        << record_.percent << "%%" <<endl;
    return 0;
}
