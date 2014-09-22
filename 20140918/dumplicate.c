#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <fstream>

using namespace std;
int main()
{
   string ifilename="infile.txt";
   string ofilename="outfile.txt";
   ifstream infile(ifilename.c_str());
   ofstream outfile(ofilename.c_str());
   if(!infile)
        throw runtime_error("cannot open file");
   if(!outfile)
       throw runtime_error("cannot open file");
   char  buf[200];
   while(!infile.eof())
   {
       infile >> buf;
       outfile << buf;
   }
   infile.close();
   outfile.close();

}
