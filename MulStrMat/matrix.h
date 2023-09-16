#ifndef TMATRIX_H
#define TMATRIX_H
#include "Number.h"

class TMatrix
{

public:
    TMatrix(number);
    double MulMat();
    void ShowResult();
private:
    number** MatA;
    number** MatB;
    number** MatAB;
    number size_m;
};

#endif // TMATRIX_H
