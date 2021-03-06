#include"matrixr.h"

int& MatrixR::at(const ptrdiff_t iRow, const ptrdiff_t iCol)
{
    if (iRow >= 0 && iCol >= 0 && iRow < nRow_ && iCol < nCol_)
    {
        return pRows_[iRow][iCol];
    }
    else
    {
        throw 123;
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
        throw 124;
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
        for (ptrdiff_t i = 0; i < nRow_; i += 1)
            for (ptrdiff_t j = 0; j < nCol_; j += 1)
                pRows_[i][j] += m.pRows_[i][j];
        return *this;
    }
    else
    {
        throw 202;
    }
}

MatrixR MatrixR::operator-=(const MatrixR& m)
{
    MatrixR w(nRow_, nCol_);
    if (1 == w.isSizeEqual(m))
    {
        for (ptrdiff_t i = 0; i < nRow_; i += 1)
            for (ptrdiff_t j = 0; j < nCol_; j += 1)
                pRows_[i][j] -= m.pRows_[i][j];
        return *this;
    }
    else
    {
        throw 203;
    }
}

const bool MatrixR::isMultiplicationPossible(const MatrixR& m) const
{
    return (nCol_ == m.nRow_);
}

const ptrdiff_t MatrixR::getnRow() const
{
    return nRow_;
}
const ptrdiff_t MatrixR::getnCol() const
{
    return nCol_;
}

MatrixR operator*(const MatrixR& m, const MatrixR& n)
{
    if (m.isMultiplicationPossible(n))
    {
        MatrixR res(m.getnRow(), n.getnCol());
        for (ptrdiff_t i = 0; i < res.getnRow(); i += 1)
        {
            for (ptrdiff_t j = 0; j < res.getnCol(); j += 1)
            {
                res.at(i, j) = 0;
                for (ptrdiff_t t = 0; t < m.getnCol(); t += 1)
                    res.at(i, j) += m.at(i, t) * n.at(t, j);
            }
        }
        return res;
    }
    else
    {
        throw 505;
    }
}

std::ostream& MatrixR::writeTo(std::ostream& ostrm) const
{
    for (ptrdiff_t i = 0; i < nRow_; i += 1)
    {
        for (ptrdiff_t j = 0; j < nCol_; j += 1)
        {
            ostrm << pRows_[i][j] << ' ';
        }
        ostrm << "\n";
    }
    return ostrm;
}