#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <fstream>

using namespace std;
typedef struct word_tag
{
    string word;
    int count;
    struct word_tag *next;
}WORD_S,*pWORD_S;

void add_to_chain(pWORD_S *head,const string str)
{
    pWORD_S newword,findword;
    if(*head!=NULL)
    {
        findword=*head;
        while(findword!=NULL)
        {
           if( findword->word==str)
           {
               findword->count++;
               return;
           }
           findword=findword->next;
        }
    }
    newword=new WORD_S ;
    newword->word=str;
    newword->count=1;
    newword->next=*head;
    *head=newword;
}
int main(int argc,char *argv[])
{
    if(argc!=2)
        throw runtime_error("illegal input argument");
    string filename=argv[1];
    ifstream infile(filename.c_str());
    if(!infile)
        throw runtime_error("cannot open file");
    vector<string> vec;
    string temp;
    pWORD_S WordHead,showword;
    WordHead=NULL;
    int count=0;
    while ( infile >> temp )
    {
        vec.push_back ( temp );
        add_to_chain ( &WordHead,temp );
    }
    infile.close();
    cout << vec.size()<<endl;
    cout <<"---------------------"<<endl;
    showword=WordHead;
    while(showword!=NULL)
    {
        cout <<showword->word<<"  :  "<<showword->count<<endl;
        showword=showword->next;
    }

}

