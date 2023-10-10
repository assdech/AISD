#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <ctime>
#include "matrix.h"

using namespace std;

TMatrix::TMatrix(int a,int b)
{
    srand(time(0));
    str = a;
    col = b;
    Mat = new long long*[a];
    for(int i=0;i<a;i++) Mat[i] = new long long[b];
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<b;j++)
        {
            Mat[i][j] = 16+rand()%16;
        }
    }
}

TMatrix::TMatrix(int size)
{
    this->size = size;
    str = size;
    col = size;
    Mat = new long long*[size];
}

TMatrix::TMatrix(const TMatrix  &a)
{
    str = a.str;
    col = a.col;
    Mat = new long long*[str];
    for(int i=0;i<col;i++) Mat[i] = new long long[col];
    for(int i=0;i<str;i++)
    {
        for(int j=0;j<col;j++)
        {
            Mat[i][j] = a.Mat[i][j];
        }
    }
}

void TMatrix::initMatrix()
{
    for(int i = 0; i < str; i++)
    {
        for(int j = 0; j < col; j++)
        {
            cout<<"mtrx["<<i<<"]["<<j<<"] = ";
            cin >> Mat[i][j];
        }
    }
}

void TMatrix::ShowResult()
{
    cout<<"\n";
    for(int i=0;i<str;i++){
        for(int j = 0;j < col; j++)
            cout<<Mat[i][j]<<"  ";
        cout<<"\n";
    }
    cout<<"\n";
}

TMatrix TMatrix::operator * (const int number)
{
    TMatrix mtrx1(str,col);
    for(int i = 0; i < str; i++)
    {
        for(int j = 0; j < col; j++)
        {
            mtrx1.Mat[i][j] = Mat[i][j] * number;
        }
    }
    return mtrx1;
}


TMatrix TMatrix::operator * (const TMatrix &a)
{
    TMatrix result(size);
    long long *row;

    for(int i = 0; i < size; i++)
    {
        row = new long long[size];
        for(int i=0; i<size;i++) row[i] = 0;

        for (int k = 0; k < size; k++)
        {
            for (int s = 0; s < size; s++)
            {
                row[s] += this->Mat[i][k] * a.Mat[k][s];
            }
        }
        printf("|%d|\n",row[0]);
        result.Mat[i] = row;
        printf("|%d|\n",result.Mat[i][0]);
        printf("delete |%d|\n",result.Mat[i][0]);
    }
    return result;
}

TMatrix TMatrix::operator =(const TMatrix &a)
{
    TMatrix mtrx3(str,col);
    for(int i = 0; i < str; i++)
    {
        for(int j = 0; j < col; j++)
        {
            mtrx3.Mat[i][j] = a.Mat[i][j];
        }
    }
    return mtrx3;
}

TMatrix TMatrix::operator + (const TMatrix &a)
{
    TMatrix mtrx4(str,col);
    for(int i = 0; i < str; i++)
    {
        for(int j = 0; j < col; j++)
        {
            mtrx4.Mat[i][j] = (Mat[i][j] + a.Mat[i][j]);
        }
    }
    return mtrx4;
}

TMatrix TMatrix::operator - (const TMatrix &a)
{
    TMatrix mtrx5(str,col);
    for(int i = 0; i < str; i++)
    {
        for(int j = 0; j < col; j++)
        {
            mtrx5.Mat[i][j] = (Mat[i][j] - a.Mat[i][j]);
        }
    }
    return mtrx5;
}

int TMatrix::selsubmatrix(int strdel,int coldel)
{
    if(str < strdel || col < coldel) return 1;
    TMatrix mtrx6(strdel,coldel);
    int strmas[strdel];
    int colmas[coldel];
    cout << "write the row numbers in ascending order: ";
    for(int i=0;i<strdel;i++)
    {
        cin >> strmas[i];
        if(str < strmas[i])
        {
            mtrx6.deleteMatrix();
            return 1;
        }
    }
    cout << "write the column numbers in ascending order: ";
    for(int i=0;i<coldel;i++)
    {
        cin >> colmas[i];
        if(col < colmas[i])
        {
            mtrx6.deleteMatrix();
            return 1;
        }
    }
    for(int i=0;i<strdel;i++)
    {
        for(int j=0;j<coldel;j++){
            mtrx6.Mat[i][j] = Mat[strmas[i]-1][colmas[j]-1];
        }
    }
    mtrx6.ShowResult();
    return 0;
}

void TMatrix::wrmattofile()
{
    ofstream fout;
    fout.open("test.txt");
    fout << str << " ";
    fout << col << endl;
    if (fout.is_open()) {
        for (int i = 0; i < str; i++){
            for(int j = 0; j < col; j++){
                fout << Mat[i][j] << " ";
            }
            fout << "\n";
        }
        fout.close();
        cout << "\nThe array has been successfully written to the file." <<endl;
    }
    else {
        cout << "Error opening the file." << endl;
    }
}

void TMatrix::rematfromfile()
{
    ifstream inputFile("test.txt");

    inputFile >> str;
    inputFile >> col;

    for (int i = 0; i < str; i++){
        for(int j = 0; j < col; j++)
        {
            inputFile >> Mat[i][j];
        }
    }
    inputFile.close();
}

void TMatrix::deleteMatrix()
{
    for(int i = 0; i < str; i++)
    {
        delete[] Mat[i];
    }
    delete[] Mat;
}

void TMatrix::SetZero()
{
    for(int i = 0; i < str; i++)
    {
        for(int j = 0; j < col; j++)
        {
            Mat[i][j] = 0;
        }
    }
}
