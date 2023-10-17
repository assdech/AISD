#include "matrix.h"
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main()
{
    int ch;
    cout<<"Enter operation:" << endl;
    cout<<"1 - Multiplie of matrix(for lab)" << endl;
    cout<<"2 - Multiplie of matrix" << endl;
    cout<<"3 - Multiplie in value" << endl;
    cout<<"4 - Summation of matrix" << endl;
    cout<<"5 - Subtraction of matrix" << endl;
    cout<<"6 - Select a submatrix in the matrix" << endl;
    cout<<"7 - Write the matrix to a file" << endl;
    cout<<"8 - Read an array from a file" << endl;
    cout<<"0 - Exit"<<endl<<"> ";
    cin >> ch;
    switch(ch)
    {
    case 1:
    {

        for(int i=6; i<=10;i++)
        {
            unsigned int _start = 0;
            unsigned int _end = 0;
            double time = 0;
            TMatrix First_M(pow(2,i),pow(2,i));
            TMatrix Second_M(pow(2,i),pow(2,i));
            for(int j=0;j<1;j++)
            {
                _start = clock();
                (First_M * Second_M);
                _end = clock();
                time += (double) (_end - _start)/1000;
            }
            int n = pow(2,i);
            printf("%1d) str = %4d; time = %f;\n",i-5,n,time);
        }
        break;
    }
    case 2:
    {
        int str1,col1,col2;
        cout << "Enter size of matrix:\n\n"
        "number of rows of the first matrix: ";
        cin >> str1;
        cout << "number of columns of the first matrix"
        " (number of rows of the second): ";
        cin >> col1;
        cout << "number of columns of the second matrix: ";
        cin >> col2;
        TMatrix First_M(str1,col1);
        First_M.initMatrix();
        TMatrix Second_M(col1,col2);
        Second_M.initMatrix();
        First_M.ShowResult();
        Second_M.ShowResult();

        (First_M * Second_M).ShowResult();
        break;
    }
    case 3:
    {
        int str, col, val;
        cout << "Enter size of matrix:\n\n"
        "number of rows of the matrix: ";
        cin >> str;
        cout << "number of columns of the matrix: ";
        cin >> col;
        cout << "Enter value:";
        cin >> val;
        TMatrix First_M(str,col);
        First_M.initMatrix();
        First_M.ShowResult();
        (First_M * val).ShowResult();
        break;
    }
    case 4:
    {
        int str,col;
        cout << "Enter size of matrix:\n\n"
        "number of rows of the matrix: ";
        cin >> str;
        cout << "number of columns of the matrix: ";
        cin >> col;
        TMatrix First_M(str,col);
        First_M.initMatrix();
        TMatrix Second_M(str,col);
        Second_M.initMatrix();
        First_M.ShowResult();
        Second_M.ShowResult();
        (First_M + Second_M).ShowResult();
        break;
    }
    case 5:
    {
        int str,col;
        cout << "Enter size of matrix:\n\n"
        "number of rows of the matrix: ";
        cin >> str;
        cout << "number of columns of the matrix: ";
        cin >> col;
        TMatrix First_M(str,col);
        First_M.initMatrix();
        TMatrix Second_M(str,col);
        Second_M.initMatrix();
        First_M.ShowResult();
        Second_M.ShowResult();
        (First_M - Second_M).ShowResult();
        break;
    }
    case 6:
    {
        int str,col,strdel = 1,coldel = 1;
        cout << "Enter size of matrix:\n\n"
        "number of rows of the matrix: ";
        cin >> str;
        cout << "number of columns of the matrix: ";
        cin >> col;
        TMatrix First_M(str,col);
        First_M.initMatrix();
        First_M.ShowResult();
        cout << "number of rows in the submatrix: ";
        cin >> strdel;
        if(strdel <= 0) cout << "Error";
        cout << "number of columns in the submatrix: ";
        cin >> coldel;
        if(coldel <= 0) cout << "Error";
        if(First_M.selsubmatrix(strdel,coldel) != 0) cout << "Error";
        break;
    }
    case 7:
    {
        int str,col;
        cout << "Enter size of matrix:\n\n"
        "number of rows of the matrix: ";
        cin >> str;
        cout << "number of columns of the matrix: ";
        cin >> col;
        TMatrix First_M(str,col);
        First_M.initMatrix();
        First_M.wrmattofile();
        break;
    }

    case 8:
    {
        int str,col;
        ifstream inputFile("test.txt");
        inputFile >> str;
        inputFile >> col;
        inputFile.close();
        TMatrix First_M(str,col);
        First_M.rematfromfile();
        First_M.ShowResult();
        break;
    }
    case 0:
    {
        return 0;
    }
    }
}

