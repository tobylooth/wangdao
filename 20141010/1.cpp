#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;
int main(int argc, const char *argv[])
{
    vector<string> coll;
    coll.push_back("hello");
    coll.push_back("world");
    coll.push_back("hell");
    coll.push_back("hell");
    coll.push_back("hell");
    coll.push_back("hell");
    coll.push_back("hell");

    for( auto it = coll.begin();
            it != coll.end();
            ++it)
    {
        cout << *it << endl;
    }
    cout << endl;

    for( const auto &i : coll)
    {
        cout << i << " :";

    }

    cout << endl;
    return 0;
}
