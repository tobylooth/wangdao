#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <time.h>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <sys/time.h>
using namespace std;
class Timestamp_t {
public:
    Timestamp_t ()
    {
        struct timeval tv;
        gettimeofday(&tv,NULL);
        sec_=tv.tv_sec;
        usec_=tv.tv_usec;
    }
    string itostring(int64_t a)
    {
        string s;
        string::iterator s_it=s.begin();
        while(a>0)
        {
            s_it=s.insert(s_it,a%10+'0');
            a/=10;
        }
        return s;

    }
    string toString()
    {
        return Timestamp_t::itostring(sec_)+"."+Timestamp_t::itostring(usec_);
    }
    string toFormalString()
    {
        time_t tm;
        struct tm *ptm;
        tm=sec_;
        ptm=localtime(&tm);
        string Fstring;
        Fstring=Timestamp_t::itostring(ptm->tm_year+1900)+"/"
            +Timestamp_t::itostring(ptm->tm_mon+1)+"/"
            +Timestamp_t::itostring(ptm->tm_mday)+"   "
            +Timestamp_t::itostring(ptm->tm_hour)+":"
            +Timestamp_t::itostring(ptm->tm_min)+":"
            +Timestamp_t::itostring(ptm->tm_sec)+"."
            +itostring(usec_);
        return Fstring;
    }
     string now()
    {
        struct timeval tm_v;
        gettimeofday(&tm_v,NULL);
        return Timestamp_t::itostring(tm_v.tv_sec)+"."
            +Timestamp_t::itostring(tm_v.tv_usec);
    }

private:
    int64_t usec_;
    int64_t sec_;
    /* data */
};
int main(int argc, const char *argv[])
{
    Timestamp_t time_;
    cout << time_.toString() <<endl;
    cout << "time now" << time_.now() << endl;
    cout << time_.toFormalString() <<endl;
    return 0;
}
