#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef struct student
{
    string name;
    float score;
}STU,*pSTU;
int main()
{
    vector<STU> stuinfo;
    STU student;
    while(cin >> student.name && cin >> student.score)
    {
        stuinfo.push_back (student);
    }
    int count=0;
    for( vector<STU>::iterator it = stuinfo.begin();
            it != stuinfo.end();
            ++it)
    {
        if((*it).score >= 60)
                count++;
    }
    cout << "the number of passed is:" << count << endl;
    return 0;
}

