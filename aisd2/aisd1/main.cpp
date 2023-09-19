#include "matrix.h"
#include <iostream>
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
        cout<<"0 - exit"<<endl<<"> ";
        cin >> ch;
        switch(ch)
        {
        case 1:
        {
            for(int i=1; i<=11;i++)
            {
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
            }
            break;
        }
        case 2:
        {
            cout << "Enter size of matrix:";
            int i;
            cin >> i;
            TMatrix First_M(i);
            First_M.initMatrix();
            TMatrix Second_M(i);
            Second_M.initMatrix();
            TMatrix Result(i);
            Result = First_M * Second_M;
            cout << Result.Mat[2][2];
            //Result.ShowResult();
            break;
        }
        case 3:
        {
            int i, c;
            cout << "Enter size of matrix:";
            cin >> i;
            cout << "Enter value:";
            cin >> c;
            TMatrix First_M(i);
            First_M.initMatrix();
            TMatrix Result(i);
            Result = First_M * c;
            Result.ShowResult();
            break;
        }
        case 4:
        {
            cout << "Enter size of matrix:";
            int i;
            cin >> i;
            TMatrix First_M(i);
            First_M.initMatrix();
            TMatrix Second_M(i);
            Second_M.initMatrix();
            TMatrix Result(i);
            Result = First_M + Second_M;
            Result.ShowResult();
            break;
        }
        case 5:
        {
            cout << "Enter size of matrix:";
            int i;
            cin >> i;
            TMatrix First_M(i);
            First_M.initMatrix();
            TMatrix Second_M(i);
            Second_M.initMatrix();
            TMatrix Result(i);
            Result = First_M - Second_M;
            Result.ShowResult();
            break;
        }
        case 0:
        {
            return 0;
        }
        }
}

