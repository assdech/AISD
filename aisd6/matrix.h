#ifndef TMATRIX_H
#define TMATRIX_H

class TMatrix
{
public:
    TMatrix(const TMatrix  &);
    TMatrix(int, int);

    TMatrix operator *(const int size_m);
    TMatrix operator *(const TMatrix &);
    TMatrix operator =(const TMatrix &);
    TMatrix operator -(const TMatrix &);
    TMatrix operator +(const TMatrix &);
    int selsubmatrix(int,int);
    void wrmattofile();
    void rematfromfile();
    void ShowResult();
    void deleteMatrix();
    void initMatrix();
    void SetZero();
    long long** Mat;
    int col;
    int str;
};

#endif // TMATRIX_H
