#include "fqa_head.h"

void User_::addUser()
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
