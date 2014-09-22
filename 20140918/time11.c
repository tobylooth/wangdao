#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <stdexcept>
#include <stdio.h>
#include<string.h>
#include<fcntl.h>
#include <errno.h>
#include <sys/time.h>
#include <stdlib.h>
#define ERR_EXIT(m)\
    do{\
        perror(m);\
        exit(EXIT_FAILURE);\
    }while(0)
using namespace std;

//typedef long long  size64_int;
typedef struct Word
{
    string word;
    int count;
}WORD;

int64_t get_time()
{
    struct timeval tm;
    memset(&tm,0,sizeof(tm));
    if(gettimeofday(&tm,NULL)==-1)
        ERR_EXIT("gettimeofday");
    int64_t t=0;
    t +=tm.tv_sec * 1000 * 1000;
    t +=tm.tv_usec;
    return t;
}
void delPunct(string &s)
{
    string::iterator it=s.begin();
    while(it!=s.end())
    {
        if(ispunct(*it))
            it=s.erase(it);
        else
            ++it;
    }
}
void toLower(string &s)
{
    string::iterator it=s.begin();
    while(it!=s.end())
    {
       if(((*it)>='A')&&((*it)<='Z'))
        s.replace(it,it+1,1,(*it)-'A'+'a');
        ++it;
    }
}
void add_to_vector(vector<WORD> &vec,const string &temp)
{
    WORD wordtemp;
    for(vector<WORD>::iterator it=vec.begin();
            it!=vec.end();
            ++it)
    {
        if((*it).word==temp)
        {
            (*it).count++;
            return;
        }
    }
    wordtemp.word=temp;
    wordtemp.count=1;
    vec.push_back(wordtemp);
}
void del_from_vector(vector<WORD> &vec,const string &temp)
{
    int left,right,mid;
    left=0;
    right=vec.size();
    while(left<=right)
    {
        mid=(left+right)/2;
        if(vec[mid].word==temp)
        {
            vector<WORD>::iterator it=vec.begin();
            it=it+mid;
            it=vec.erase(it);
            return;
        }
        else
        {
            if(vec[mid].word<temp)
                left=mid+1;
            else
                right=mid-1;
        }


    }
}
bool cmp(const WORD &a,const WORD &b)
{
    return a.word<b.word;
}
int main(int argc,char *argv[])
{
    int time_main_begin,time_main_end;
    int time_readfile_begin,time_readfile_end;
    int time_sort_begin,time_sort_end;
    int time_print_begin,time_print_end;
    time_main_begin=get_time();//main time
    if(argc!=3)
    {
        printf("Usage");
        exit(EXIT_FAILURE);
    }
    string filename=argv[1];
    string tablename=argv[2];
    vector<WORD> vec;
    ifstream infile(filename.c_str());
    if(!infile)
        throw runtime_error("cannot open file");
    string temp;
    WORD wordtemp;
    ////
    time_readfile_begin=get_time();//readfile time
    while(infile >> temp)
    {
        delPunct(temp);
        toLower(temp);
        add_to_vector(vec,temp);
    }
    infile.close();
    time_readfile_end=get_time();  //end read

    time_sort_begin=get_time();///sort time
    sort(vec.begin(),vec.end(),cmp);            //////sort
    time_sort_end=get_time(); ////end sort

    infile.open(tablename.c_str());
    if(!infile)
        throw runtime_error("cannot open file");
    while(infile >> temp)
    {
        del_from_vector(vec,temp);
    }
    infile.close();

    time_print_begin=get_time(); ///print time
    for(vector<WORD>::iterator it=vec.begin();//print
            it!=vec.end();++it)
    {
        if((*it).count>500)
        cout << (*it).word <<"  :  "<<(*it).count << endl;
    }
    time_print_end=get_time();///end print
    time_main_end=get_time();  //end main

    cout << "time of main: "<< time_main_end-time_main_begin<<endl;
    cout << "time of read:"<< time_readfile_end-time_readfile_begin<<endl;
    cout << "time of sort: "<< time_sort_end-time_sort_begin<<endl;
    cout << "time of print: "<< time_print_end-time_print_begin<<endl;
    return 0;
}



























