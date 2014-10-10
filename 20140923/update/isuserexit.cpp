#include "fqa_head.h"
using namespace std;
bool isuserexit(const string username,const vector<User> &user_)
{
    vector<User>::const_iterator it=user_.begin();
    while(it!=user_.end())
    {
        if((*it).name==username)
            return true;
        ++it;
    }
    return false;
}
