#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <time.h>
#include <stdio.h>
using namespace std;

class Date
{
    private:
        int year;
        int month;
        int day;
        int hour;
        int minute;
        int second;
    public:
        Date():year(1900),month(1),day(1),hour(0),minute(0),second(0){}

        void setdate()
        {
            cin>>year>>month>>day>>hour>>minute>>second;
        }
        void printTime()
        {
            cout<<year<<"/"<<month<<"/"<<day<<" "<<hour<<":"<<minute
                <<":"<<second<<endl;
        }
        void setNow()
        {
            time_t rawtime;
            rawtime=time(NULL);
            struct tm *ptm;

            ptm=localtime(&rawtime);
            year+=ptm->tm_year;
            month+=ptm->tm_mon;
            day=ptm->tm_mday;
            hour=ptm->tm_hour;
            minute=ptm->tm_min;
            second=ptm->tm_sec;

        }
};
int main()
{
    Date date;
    date.setdate();
    date.printTime();
    date.setNow();
    date.printTime();

}
