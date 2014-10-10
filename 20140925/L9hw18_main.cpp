#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
using namespace std;
class Queue {
public:
    Queue ();
    Queue(const int value_,const Queue *head_,const Queue *tail_);
    Queue(const Queue &dup);
    Queue &operator=(const Queue &dup);
     ~Queue ();
     int getbvalue(){return value_;}
     Queue *gethead(){return head;}
     Queue *gettail(){return tail;}

     void setvalue(const int value_){ value=value_; }
     void sethead(const Queue *phead){ head=phead; }
     void settail(const Queue *ptail) { tail = ptail; }

     void push(const int value_);
     void pop();


private:
    int value_;
    Queue *head;
    Queue *tail;
    /* data */
};
Queue::Queue():value_(0),head(NULL),tail(NULL){}

Queue::Queue(const int value_,const Queue *head_,const Queue *tail_)
    :value_(0),head(NULL),tail(NULL){}

Queue::Queue(const Queue &dup)
    :value_(0),head(new Queue),tail(new Queue)
{
    value_=dup.getvalue();
    head=dup.gethead();
    tail=dup.gettail();
}
Queue &Queue::operator=(const Queue &dup)
{
    if(this== &dup) return ;
    while(head!=tail)
    {
       pop();
    }

    return *this;
}
~Queue::Queue ()
{
    while(head!=tail&&head!=NULL)
    {
        Queue *temp;
        temp=head;
        head=head->next;
        delete temp;
    }
}
Queue::push(const int value_)
{
    Queue *newnode,*temp;
    newnode = new Queue;
    newnode.setvalue(value);
    newnode->next=NULL;
    if(head == NULL)
    {
        head=newnode;
        tail=newnode;
    }
    else
    {
        tail->next=newnode;
        tail=newnode;
    }
}
Queue::pop()
{
    Queue *temp;
    temp=head;
    head=head->next;
    delete temp;
}
