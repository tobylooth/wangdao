#include "head.h"

using namespace std;
void findbi(const string &file1,const string &file2)
{
    ifstream f1;
    f1.open(file1.c_str());
    if(!f1)
    {
        cerr<<"cannot open file1  "<<file1<<endl;
        return;
    }

    vector<string> words;
    string temp="";
    while(!f1.eof())

    {
        f1>>temp;
        words.push_back(temp);
        temp="";
    }
    f1.close();
    sort(words.begin(),words.end());
    int left,right,mid;
    f1.open(file2.c_str());
    if(!f1)
    {
        cerr<<"cannot open file2  "<<file2<<endl;
        return;
    }
    while(!f1.eof())
    {
        temp="";
        f1>>temp;
        int flag=0;
        left=0;
        right=words.size()-1;
        while(left<=right)
        {
            mid=(left+right)/2;
            if(strcmp(words[mid].c_str(),temp.c_str())<0)
            {
                left=mid+1;
            }
            else
            {
                if(strcmp(words[mid].c_str(),temp.c_str())>0)
                {
                    right=mid-1;
                }
                else
                {
                    flag=1;
                    break;
                }
            }
        }
  //      if(flag==0)
//            cout<<temp<<endl;
    }

    cout<<"over-----------------------"<<words.size()<<endl;



}

