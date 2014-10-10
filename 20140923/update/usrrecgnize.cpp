#include "fqa_head.h"
using namespace std;
string usrrecgnize(const vector<User> &user_)
{
    int count=0;
    string recg_username,recg_passwd;
    while(1)
    {
        while(1)
        {
        cout << "input username :";
        cin >> recg_username;

        if(!isuserexit(recg_username,user_))
        {
            cout << "user not exist" << endl;
        }
        else
            break;
        }
        while(1)
        {
        cout << "intput passwd :";
        cin >> recg_passwd;

        for(vector<User>::const_iterator rec_it=user_.begin();
                rec_it!=user_.end();
                ++rec_it)
        {
            if((*rec_it).name==recg_username)
            {
              if((*rec_it).passwd==recg_passwd)
                return recg_username;
            }
        }
        count++;
        if(count>=3)
        {
            cout << "wrong password 3 times " << endl;
            exit(EXIT_FAILURE);
        }
        else
        {
           cout << "password incorrect" << endl;
        }
        }
    }

}


























