
#include <iostream>
#include <string>
#include <vector>
using namespace std;
void bubble_sort(vector<int>  &arr,bool (*cmp)(int ,int))
{
    for(vector<int>::size_type ix=0;ix!=arr.size();ix++)
    {
        for(vector<int>::size_type iy=0;iy!=arr.size()-ix-1;iy++)
        {
            if(!cmp(arr[iy],arr[iy+1]))
           // if(arr[iy]>arr[iy+1])
            {
                int temp;
                temp=arr[iy];
                arr[iy]=arr[iy+1];
                arr[iy+1]=temp;
            }
        }
    }
}
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    vector<int>  arr;
    int n;
    while(cin>>n)
    {
        arr.push_back(n);
    }
    bool (*p)(int ,int);
    p=cmp;
    bubble_sort(arr,p);
    for(vector<int>::size_type ix=0;ix!=arr.size();++ix)
        cout<<arr[ix]<<"  ";
    cout<<"  "<<endl;

}

