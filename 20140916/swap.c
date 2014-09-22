#include <iostream>
using namespace std;
int main()
{
    void swap(int* &a,int* &b);
    int *a,*b,c,d;
    c=1;d=2;
    a=&c;
    b=&d;
    cout<<*a<<"\n"<<*b<<endl;
    swap(a,b);
    cout<<*a<<"\n"<<*b<<endl;
    return 0;

}
void swap(int* &a,int* &b)
{
    int *temp;
    temp=a;
    a=b;
    b=temp;
}
