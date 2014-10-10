#include "fqa_head.h"

using namespace std;

string  login()
{
    ///////////////recgnize user
    vector<User> user_;
    string s;
    s=PASSPATH;
    readfile(s,user_);

    return usrrecgnize(user_);
}
