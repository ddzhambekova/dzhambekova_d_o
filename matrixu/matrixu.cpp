#include "matrixu.h"

int& MatrixU::at(const ptrdiff_t iRow, const ptrdiff_t iCol)
{
    if (iRow >= 0 && iCol >= 0 && iRow < nRow_ && iCol < nCol_)
    {
        return pdata_[nCol_ * iRow + iCol];
    }
    else
    {
        throw std::out_of_range("Error: out of size");
    }
}
const int& MatrixU::at(const ptrdiff_t iRow, const ptrdiff_t iCol) const
{
    if (iRow >= 0 && iCol >= 0 && iRow < nRow_ && iCol < nCol_)
    {
        return pdata_[nCol_ * iRow + iCol];
    }
    else
    {
        throw std::out_of_range("Error: out of size");
    }
}

bool MatrixU::isSizeEqual(const MatrixU& m)
{
    return (nRow_ == m.nRow_ && nCol_ == m.nCol_);
}

MatrixU MatrixU::operator+=(const MatrixU& m)
{
    MatrixU w(nRow_, nCol_);
    if (1 == w.isSizeEqual(m))
    {
        for (ptrdiff_t i = 0; i < nRow_*nCol_; i++)
            pdata_[i] += m.pdata_[i];
        return *this;
    }
    else
    {
        throw std::range_error("Error: different size");
    }
}

MatrixU MatrixU::operator-=(const MatrixU& m)
{
    MatrixU w(nRow_, nCol_);
    if (1 == w.isSizeEqual(m))
    {
        for (ptrdiff_t i = 0; i < nRow_*nCol_; i++)
            pdata_[i] -= m.pdata_[i];
        return *this;
    }
    else
    {
        throw std::range_error("Error: different size");
    }
}

const bool MatrixU::isMultiplicationPossible(const MatrixU& m) const
{
    return (nCol_ == m.nRow_);
}

const ptrdiff_t MatrixU::getnRow() const
{
    return nRow_;
}
const ptrdiff_t MatrixU::getnCol() const
{
    return nCol_;
}


MatrixU operator*(const MatrixU& m, const MatrixU& n)
{
    if (1 == m.isMultiplicationPossible(n))
    {
        MatrixU res(m.getnRow(), n.getnCol());
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

std::ostream& MatrixU::writeTo(std::ostream& ostrm) const
{
    for (ptrdiff_t j = 0; j < nRow_*nCol_; j+=nCol_)
    {
        for (ptrdiff_t i = j; i < j + nCol_; i++)
        {
            ostrm << pdata_[i] << ' ';
        }
        ostrm << "\n";
    }
    return ostrm;
}