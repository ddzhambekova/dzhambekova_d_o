#include"matrixr.h"

int& MatrixR::at(const ptrdiff_t iRow, const ptrdiff_t iCol)
{
    if (iRow >= 0 && iCol >= 0 && iRow < nRow_ && iCol < nCol_)
    {
        return pRows_[iRow][iCol];
    }
    else
    {
        throw std::out_of_range("Error: out of size");
    }
}
const int& MatrixR::at(const ptrdiff_t iRow, const ptrdiff_t iCol) const
{
    if (iRow >= 0 && iCol >= 0 && iRow < nRow_ && iCol < nCol_)
    {
        return pRows_[iRow][iCol];
    }
    else
    {
        throw std::out_of_range("Error: out of size");
    }
}