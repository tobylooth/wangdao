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
    void toFormatString()
    {
        vector<string> vec;
        vec.push_back("January");
        vec.push_back("February");
        vec.push_back("March");
        vec.push_back("April");
        vec.push_back("May");
        vec.push_back("June");
        vec.push_back("July");
        vec.push_back("August");
        vec.push_back("September");
        vec.push_back("October");
        vec.push_back("November");
        vec.push_back("December");
        cout << vec[month_-1] << " " << day_ <<" " <<year_<<endl;
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
int main(int argc, const char *argv[])
{
    Date date,date2;
    date.setToday();
    date.toString();
    date.toFormatString();
    date2.setDate(2014,9,20);
    date2.toString();
   cout<<"difference:"<< differenceDate(date,date2)<<endl;
   today().toString();
    return 0;
}
