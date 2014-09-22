#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <stdlib.h>
using namespace std;
class phone_book
{
    public :
        phone_book():phonenum_(""),name_(),address_()
    {}
        void addNewRecord(string phonenum,string name,string addr)
        {
            phonenum_=phonenum;
            name_.push_back(name);
            address_.push_back(addr);
        }
        void addToRecord(string name,string addr)
        {
            name_.push_back(name);
            address_.push_back(addr);
        }
        bool findByPhone(string phone ) const
        {
            return phonenum_==phone;
        }
        bool findByName(string name) const
        {
            for(vector<string>::const_iterator it=name_.begin();
                    it!=name_.end();
                    ++it)
            {
                if(*it==name)
                    return true;
            }
            return false;
        }
        bool findByAddr(string address) const
        {
            for(vector<string>::const_iterator it=address_.begin();
                    it!=address_.end();
                    ++it)
            {
                if(*it==address)
                    return true;
            }
            return false;
        }
        void showinfo()
        {
            cout <<" phone number" <<"\n"<< phonenum_ << endl;
            for(vector<string>::const_iterator name_it=name_.begin();
                    name_it!=name_.end();
                    ++name_it)
            {
                cout << *name_it <<endl;
            }

            for(vector<string>::iterator addr_it=address_.begin();
                    addr_it!=address_.end();
                    ++addr_it)
            {
                cout << *addr_it <<endl;
            }
            char c;
            while(cin>>c)
            {
                    return;
            }

        }
    private:
        string phonenum_;
        vector<string> name_;
        vector<string> address_;
};
int main(int argc, const char *argv[])
{
    vector<phone_book> pb;
    phone_book temp;
    string tempstr;
    while(1)
    {
        system("clear");
        cout << "select operation: 1 to add 2 to delet 3 to query"
            <<endl;
        int option;
        cin >> option;
        if(option==1)
        {
            system("clear");
            cout << "add option :"<< "\n"
                <<"input name ,phonenumber and address" << endl;
            string phone,name,address;
            cin>>name >> phone >>address;
            temp.addNewRecord(phone,name,address);
            vector<phone_book>::iterator it=pb.begin();
            int flag=0;
            while(it!=pb.end())
            {
                if((*it).findByPhone(phone))
                {
                    flag=1;
                    break;
                }
                ++it;
            }
            if(flag==0)
            {
                pb.push_back(temp);
            }
            else
            {
                (*it).addToRecord(name,address);
            }
        }
        if(option==2)
        {
            system("clear");
            cout << " delete operation " << "/n"
                <<"input the phone number"<<endl;
            string phone;
            int flag=0;
            vector<phone_book>::iterator it=pb.begin();
            while(it!=pb.end())
            {
                if((*it).findByPhone(phone))
                {
                    it=pb.erase(it);
                    flag=1;
                    break;
                }
                else
                    ++it;
            }
            if(flag==0)
            {
                cout << "cannot find " << endl;
            }
            else
            {
                cout <<" delete success" <<endl;
                system("pause");
                continue;
            }
        }
        if(option==3)
        {
            system("clear");
            cout << "query operation" << "\n"
                <<"1 by name,2 by addr,3 by phone" << endl;
            int opt,flag=0;
            cin >>opt;

            if(opt==1)
            {
                cout << "input name"<<endl;
                cin >>tempstr;
                vector<phone_book>::iterator pb_it=pb.begin();
                while(pb_it!=pb.end())
                {
                    if((*pb_it).findByName(tempstr))
                    {
                        (*pb_it).showinfo();
                        flag=1;
                        system("pause");
    return 0;
                        break;
                    }
                    ++pb_it;
                }
            }
            if(opt==2)
            {
                cout << "input address" <<endl;
                cin >> tempstr;
                vector<phone_book>::iterator pb_it=pb.begin();
                while(pb_it!=pb.end())
                {
                    if((*pb_it).findByAddr(tempstr))
                    {
                        (*pb_it).showinfo();
                        flag=1;
                        system("pause");
    return 0;
                        break;
                    }

                    ++pb_it;
                }
            }
            if(opt==3)
            {
                cout << "input phone number" <<endl;
                cin >> tempstr;
                vector<phone_book>::iterator pb_it=pb.begin();
                while(pb_it!=pb.end())
                {
                    if((*pb_it).findByPhone(tempstr))
                    {
                        flag=1;
                        (*pb_it).showinfo();
                        system("pause");
                        break;
    return 0;
                    }
                    ++pb_it;
                }
            }

            if(flag!=1)
            {
                cout << "record not found" <<endl;
            }
            system("pause");
        }
    }
    return 0;
}
