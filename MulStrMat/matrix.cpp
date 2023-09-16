#include <iostream>
#include <stdlib.h>
#include <ctime>
#include "matrix.h"

using namespace std;

TMatrix::TMatrix(number n)
{
    size_m = n;

    MatA = (number**)malloc(n * sizeof(number*));
    for(int i=0;i<n;i++) MatA[i] = (number*)malloc(sizeof(number)*n);

    MatB = (number**)malloc(n * sizeof(number*));
    for(int i=0;i<n;i++) MatB[i] = (number*)malloc(sizeof(number)*n);

    MatAB = (number**)malloc(n * sizeof(number*));
    for(int i=0;i<n;i++) MatAB[i] = (number*)malloc(sizeof(number)*n);

    srand(time(0));

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            MatA[i][j] = 16+rand()%16;
            MatB[i][j] = 16+rand()%16;
            MatAB[i][j] = 0;
        }
}

double TMatrix::MulMat()
{
    unsigned int _start = 0;
    unsigned int _end = 0;
    double time = 0;
    _start = clock();
    for(int i=0;i<size_m;i++)
        for(int j=0;j<size_m;j++)
            for(int k=0;k<size_m;k++)
                MatAB[i][j] += MatA[i][k]*MatB[k][j];
    _end = clock();
    time += (double) (_end - _start)/1000;
    return time;
}

void TMatrix::ShowResult()
{
    for(int i=0;i<size_m;i++){
        for(int j=0;j<size_m;j++)
            cout<<MatA[i][j]<<"  ";
        cout<<"\t";
        for(int j=0;j<size_m;j++)
            cout<<MatB[i][j]<<"  ";
        cout<<"\t";
        for(int j=0;j<size_m;j++)
            cout<<MatAB[i][j]<<"\t";
        cout<<"\n";
    }
}
