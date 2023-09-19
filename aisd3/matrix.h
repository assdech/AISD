#ifndef TMATRIX_H
#define TMATRIX_H

class TMatrix
{
public:
    TMatrix();
    TMatrix(int n);
    TMatrix operator *(int size_m);
    TMatrix operator *(TMatrix);
    TMatrix operator =(TMatrix);
    TMatrix operator -(TMatrix);
    TMatrix operator +(TMatrix);
    void ShowResult();
    void deleteMatrix();
    void initMatrix();
    void SetZero();
    int** Mat;
    int size_m;
private:

};

#endif // TMATRIX_H
