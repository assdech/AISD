//#include <QCoreApplication>
#include <iostream>
#include <cmath>
#include "matrix.h"

using namespace std;

int main()
{
    for(int i=1; i<=11;i++){
        unsigned int _start = 0;
        unsigned int _end = 0;
        double time = 0;
        TMatrix First_M(pow(2,i));
        TMatrix Second_M(pow(2,i));
        TMatrix Result(pow(2,i));
        _start = clock();
        Result = First_M * Second_M;
        _end = clock();
        time += (double) (_end - _start)/1000;
        printf("i = %4d;  time = %f\n",i,time);
        //matrix.ShowResult();
    }



    return 0;
}
