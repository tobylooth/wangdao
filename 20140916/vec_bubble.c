#include <iostream>
#include <string>
#include <vector>
using namespace std;
void bubble_sort(vector<int>  &arr)
{
    for(vector<int>::size_type ix=0;ix!=arr.size();ix++)
    {
        for(vector<int>::size_type iy=0;iy!=arr.size()-ix-1;iy++)
        {
            if(arr[iy]>arr[iy+1])
            {
                int temp;
                temp=arr[iy];
                arr[iy]=arr[iy+1];
                arr[iy+1]=temp;
            }
        }
    }
}
int main()
{
    vector<int>  arr;
    int n;
    while(cin>>n)
    {
        arr.push_back(n);
    }
    bubble_sort(arr);
    for(vector<int>::size_type ix=0;ix!=arr.size();++ix)
        cout<<arr[ix];
    cout<<endl;

}

