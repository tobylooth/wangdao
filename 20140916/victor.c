#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> vec;
    vec.push_back(12);//apend element
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(15);
    vec.push_back(16);
    for(vector <int>::size_type ix=0;ix<vec.size();ix++)
        cout << vec[ix] << endl;
    return 0;

}
