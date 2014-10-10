#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
using namespace std;
class textQuery {
public:
    textQuery ()
    {}
    typedef std::vector<std::string>::size_type line_no;
    void readfile(const string filename)
    {
        cout << "in readfile " <<endl;

        string linetemp;
        ifstream infile(filename.c_str());
        if(!infile)
            throw runtime_error("cannot open file");
        while(infile >> linetemp)
        {
            vec.push_back(linetemp);
        }
        infile.close();
        cout << "out readfile " <<endl;
    }
    void tomap()
    {
        cout << "in tomap " <<endl;
        string wordtemp;
        line_no i;
        for(  i=0; i!=vec.size(); ++i )
        {
            istringstream instream(vec[i]);
            while(instream >> wordtemp)
            {
                word_map[wordtemp].insert(i);
            }
        }
        cout << "out to map " <<endl;
    }
    void queryWord()
    {
        cout << "in queryword " <<endl;
        string word_;
        while(1)
        {
            cout << "input query word : ";
            cin >> word_;
            line_no count_word;
            multiset<line_no> set1;
            set1=retfrommap(word_);
            line_no word_count;
            for(line_no i=0;i!=vec.size();i++)
            {
                multiset<line_no>::iterator set_it=set1.find(i);
                count_word=set1.count(i);
                if(set_it!=set1.end())
                {
                    cout << "line " << *set_it << "   "
                        << vec[*set_it] << endl;
                    cout << word_ <<" appears " << count_word << "times"<<endl;
                }

            }
            word_count=word_map[word_].size();
            cout << "sum times " << word_count <<endl;
        }
        cout << "out queryword" <<endl;
    }
    multiset<textQuery::line_no>  retfrommap(const string word)
    {
        cout << "in multiset " <<endl;
        map<string,multiset<line_no> >::iterator map_it=word_map.find(word);
        if(map_it==word_map.end())
            return multiset<textQuery::line_no>();
        else
            return map_it->second;
        cout << "out multiset" << endl;


    }
    void doit(const string s)
    {
        readfile(s);
        tomap();
        queryWord();

    }


private:
    vector<string> vec;
    map<string,multiset<line_no> > word_map;
    /* data */
};
int main(int argc, const char *argv[])
{
    if(argc!=2)
        throw runtime_error("Usage argument error");
    textQuery wordquery;
    string s1=argv[1];
    wordquery.doit(s1);

    return 0;
}
