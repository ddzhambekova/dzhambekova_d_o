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

bool MatrixR::isSizeEqual(const MatrixR& m)
{
    return (nRow_ == m.nRow_ && nCol_ == m.nCol_);
}

MatrixR MatrixR::operator+=(const MatrixR& m)
{
    MatrixR w(nRow_, nCol_);
    if (1 == w.isSizeEqual(m))
    {
        for (ptrdiff_t i = 0; i < nRow_; i++)
            for (ptrdiff_t j = 0; j < nCol_; j++)
                pRows_[i][j] += m.pRows_[i][j];
        return *this;
    }
    else
    {
        throw std::range_error("Error: different size");
    }
}

MatrixR MatrixR::operator-=(const MatrixR& m)
{
    MatrixR w(nRow_, nCol_);
    if (1 == w.isSizeEqual(m))
    {
        for (ptrdiff_t i = 0; i < nRow_; i++)
            for (ptrdiff_t j = 0; j < nCol_; j++)
                pRows_[i][j] -= m.pRows_[i][j];
        return *this;
    }
    else
    {
        throw std::range_error("Error: different size");
    }
}

const bool MatrixR::isMultiplicationPossible(const MatrixR& m) const
{
    return (nCol_ == m.nRow_);
}

ptrdiff_t MatrixR::getnRow()
{
    return nRow_;
}
ptrdiff_t MatrixR::getnCol()
{
    return nCol_;
}

MatrixR operator*(MatrixR& m, MatrixR& n)
{
    if (1 == m.isMultiplicationPossible(n))
    {
        MatrixR res(m.getnRow(), n.getnCol());
        for (ptrdiff_t i = 0; i < res.getnRow(); i++)
        {
            for (ptrdiff_t j = 0; j < res.getnCol(); j++)
            {
                for (ptrdiff_t t = 0; t < m.getnCol(); t++)
                    res.at(i, j) += m.at(i, t) * n.at(t, j);
            }
        }
        return res;
    }
    else
    {
        throw std::range_error("Error: matrix multiplication is impossible");
    }
}

std::ostream& MatrixR::writeTo(std::ostream& ostrm) const
{
    for (ptrdiff_t i = 0; i < nRow_; i++)
    {
        for (ptrdiff_t j = 0; j < nCol_; j++)
        {
            ostrm << pRows_[i][j] << ' ';
        }
        ostrm << "\n";
    }
    return ostrm;
}