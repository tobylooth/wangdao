#ifndef _IF_WHITE_
#define _IF_WHITE_

#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <error.h>
#include <sys/time.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdexcept>
#include <stdio.h>
#include <fstream>
#include <string.h>
#include <algorithm>
#define N 1000000
#define SIZE1 1000000
#define SIZE2 10000000

void genfile(const std::string &filename,int n);
void findforce(FILE *fdw,FILE *fdf);

void findbi(const std::string &file1,const std::string &file2);
#endif
