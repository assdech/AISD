#include <iostream>
#include <stdlib.h>
#include <ctime>
#include "matrix.h"

using namespace std;

TMatrix::TMatrix(int n)
{
    size_m = n;
    Mat = new int*[n];
    for(int i=0;i<n;i++) Mat[i] = new int[n];
    for(int i=0;i<size_m;i++)
    {
        for(int j=0;j<size_m;j++)
        {
            Mat[i][j] = 16+rand()%16;
        }
    }
}

void TMatrix::initMatrix()
{
    for(int i = 0; i < size_m; i++)
    {
        for(int j = 0; j < size_m; j++)
        {
            cout<<"mtrx["<<i<<"]["<<j<<"] = ";
            cin >> Mat[i][j];
        }
    }
}

void TMatrix::ShowResult()
{
    for(int i=0;i<size_m;i++){
        for(int j=0;j<size_m;j++)
            cout<<Mat[i][j]<<"  ";
        cout<<"\t";
    }
}

TMatrix TMatrix::operator * (int number)
{
    TMatrix mtrx1(size_m);
    for(int i = 0; i < size_m; i++)
    {
        for(int j = 0; j < size_m; j++)
        {
            mtrx1.Mat[i][j] = Mat[i][j] * number;
        }
    }
    return mtrx1;
}

TMatrix TMatrix::operator * (TMatrix a)
{
    TMatrix mtrx2(size_m);
    for(int i = 0; i < size_m; i++)
    {
        for(int j = 0; j < size_m; j++)
        {
            for(int k = 0; k < size_m; k++)
            {
                mtrx2.Mat[i][j] += (Mat[i][k] * a.Mat[k][j]);
            }
        }
    }
    return mtrx2;
}

TMatrix TMatrix::operator = (TMatrix a)
{
    TMatrix mtrx(size_m);
    for(int i = 0; i < size_m; i++)
    {
        for(int j = 0; j < size_m; j++)
        {
            mtrx.Mat[i][j] = a.Mat[i][j];
        }
    }
    return mtrx;
}

TMatrix TMatrix::operator + (TMatrix a)
{
    TMatrix mtrx(size_m);
    for(int i = 0; i < size_m; i++)
    {
        for(int j = 0; j < size_m; j++)
        {
            mtrx.Mat[i][j] = Mat[i][j] + a.Mat[i][j];
        }
    }
    return mtrx;
}

TMatrix TMatrix::operator - (TMatrix a)
{
    for(int i = 0; i < a.size_m; i++)
    {
        for(int j = 0; j < a.size_m; j++)
        {
            a.Mat[i][j] = Mat[i][j] - a.Mat[i][j];
        }
    }
    return a;
}

void TMatrix::deleteMatrix()
{
    for(int i = 0; i < size_m; i++)
    {
        delete[] Mat[i];
    }
    delete[] Mat;
}
