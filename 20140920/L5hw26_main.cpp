
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <time.h>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
using namespace std;
class Date {
public:
    Date()
        :year_(1900),month_(1),day_(1)
    {

    }
    Date(const int year,const int month,const int day)
    {
        year_=year;
        month_=month;
        day_=day;
    }
    void setDate(const int year,const int month,const int day)
    {
        year_=year;
        month_=month;
        day_=day;
    }
    void setToday()
    {
        time_t time_;
        time_=time(NULL);
        struct tm *p;
        p=localtime(&time_);
        year_+=p->tm_year;
        month_+=p->tm_mon;
        day_=p->tm_mday;
    }
    string itoa(int a)
    {
        string s;
        string::iterator it=s.begin();
        while(a>0)
        {
            it=s.insert(it,a%10+'0');
            a/=10;

        }
        return s;
    }
    void toString()
    {
        string s,temp;
        s=itoa(year_)+"/"+itoa(month_)+"/"+itoa(day_);
        cout<<s<<endl;
    }
    bool isLeapYear() const
    {
        return ((year_%4==0&&year_%100!=0)||year_%400==0);
    }
    int calDayOfYear() const
    {
        int dayth=day_;
        for(int i=1;i<month_;i++)
        {
            switch(i)
            {
                case 1:
                case 3:
                case 5:
                case 7:
                case 8:
                case 10:
                case 12: dayth += 31;   break;
                case 2: dayth += (isLeapYear()?29:28);    break;
                default :dayth += 30;  break;
            }
        }
        return dayth;
    }
    int getyear() const
    {
        return year_;
    }
    int getmonth() const
    {
        return month_;
    }
    int getday() const
    {
        return day_;
    }


private:
    int year_;
    int month_;
    int day_;
    /* data */
};
static int differenceDate(const Date &d1,const Date &d2)
{
    int date1,date2,y1,y2;
    date1= d1.calDayOfYear();
    date2=d2.calDayOfYear();
    y1=d1.getyear();
    y2=d2.getyear();
    for(int i=1900;i<y1;i++)
    {
        if((i%4==0&&i%100!=0)||i%400==0)
        {
            date1 += 366;
        }
        else
        {
            date1 +=365;
        }
    }
    for(int i=1900;i<y2;i++)
    {
        if((i%4==0&&i%100!=0)||i%400==0)
        {
            date2 += 366;
        }
        else
        {
            date2 +=365;
        }
    }
    return date1-date2;

}
static Date today()
{
    Date date;
    date.setToday();
    return date;
}
class Person {
public:
    Person():name_(""),address_(""),birth_(1900,1,1)
    {}
    Person(string name,string address,Date &birth)
    {
        name_=name;
        address_=address;
        birth_=birth;
    }
    void setPerson(string name,string address,Date &birth)
    {
        name_=name;
        address_=address;
        birth_.setDate(birth.getyear(),birth.getmonth(),birth.getday());

    }
    void live_day()
    {
        cout << "live " <<differenceDate(today(),birth_)<<endl;
    }

    void birthpass()
    {
        if(today().getmonth()<birth_.getmonth())
        {
            cout << "the birth still not pass" <<endl;
        }
        else
        {
            if(today().getday()<birth_.getday())
            {
                cout << "the birthday still not pass " << endl;
            }
            else
            {
                if(today().getday()==birth_.getday()&&
                        today().getmonth()==birth_.getmonth())
                    cout << "today is borthday "<<endl;
                else
                    cout << "birthday is passed "<< endl;
            }
        }
    }
    void printbitrh()
    {
        cout << "birth: " << birth_.getmonth() << "/" << birth_.getday()<<endl;
    }


private:

    string name_;
    string address_;
    Date birth_;
    /* data */
};
int main(int argc, const char *argv[])
{
    Person p1;
    Date birth;
    birth.setDate(1988,3,10);
    p1.setPerson("zhangsan","shenzhen",birth);
    p1.live_day();
    p1.birthpass();
    p1.printbitrh();
    Date date,date2;
    return 0;
}
