//#include <QCoreApplication>
#include <iostream>
#include <cmath>

#include "matrix.h"

using namespace std;

int main()
{
    for(int i=1; i<=11;i++){
        TMatrix matrix(pow(2,i));

        printf("i = %4d;  time = %f\n",i,matrix.MulMat());
        //matrix.ShowResult();
    }



    return 0;
}
