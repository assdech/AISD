#ifndef TMATRIX_H
#define TMATRIX_H

class TMatrix
{

public:
    int** Mat;
    int size_m;
    TMatrix(int n);
    TMatrix operator * (int);
    TMatrix operator * (TMatrix);
    TMatrix operator = (TMatrix);
    TMatrix operator - (TMatrix);
    TMatrix operator + (TMatrix);
    void ShowResult();
    void deleteMatrix();
    void Podmatrix(int** Mat, int size_m, int order);
private:

};

#endif // TMATRIX_H
