#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <stdio.h>

#define PASSPATH "passwd.txt"
#define PROBLEMPATH "problem.txt"
#define ANSWERPATH  "answer.txt"
#define RECORDPATH "record.txt"

#define N 2
class User_
{
    public:
        User_():name_(""),passwd_("")
    {}
        User_(const std::string &name,const std::string &passwd)
        {
            name_=name;
            passwd_=passwd;
        }
        void setUser(const std::string &name,
                const std::string &passwd)
        {
            name_=name;
            passwd_=passwd;
        }

        std::string getUsername()
        {  return name_; }
        std::string getPasswd()
        {  return passwd_;}

        void addUser()
        {
            using namespace std;
            std::string username,passwd;
            std::cout << "intput new User name :";
            std::cin >> username;
            while(1)
            {
                std::string pas1;
                std::cout << "intput passwd :";
                std::cin >> pas1;
                cout << "confirm the paddwd :";
                cin >> passwd;
                if(pas1==passwd)
                    break;
                else
                {
                    cout << "two passwd is different"<<endl;
                }
            }
            ofstream outfile;
            outfile.open("user.txt");
            if(!outfile)
                throw runtime_error("cannot opoen user.txt");
            string line;
            line=username+" "+ passwd +"\n";
            outfile << line;
            outfile.close();
        }

    private:
        std::string name_;
        std::string passwd_;

};
typedef struct user_ {
    std::string name;
    std::string passwd;
    /* data */
}User,*pUser /* optional variable list */;

typedef struct problem_
{
    int showid;
    int probId;
    std::string probBody;
    std::string opt_A;
    std::string opt_B;
    std::string opt_C;
    std::string opt_D;
}Prob,*pProb;
typedef struct answer_ {
    int probId;
    char answer_;
    /* data */
}Answer,*pAnswer /* optional variable list */;
typedef struct record_ {
    std::string name_;
    int count;
    int score;
    int percent;
    /* data */
} Rec,*pRec/* optional variable list */;

void doanswer(std::vector<Prob> &prob_v,std::vector<Answer> &answer_v,Rec &record,const std::string &user);
bool isuserexit(const std::string username,const std::vector<User> &user_);
std::string login();
void readanswer(std::string &filename,std::vector<Answer> &answer_v);
void readfile(std::string &filename,std::vector<User> &user_);
void readproblem(std::string &filename,std::vector<Prob> &prob_v);
std::string usrrecgnize(const std::vector<User> &user_);

