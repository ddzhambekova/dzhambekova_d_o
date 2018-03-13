#ifndef MATRIXU_H_20171102
#define MATRIXU_H_20171102

#include<cstddef>
#include<iostream>

class MatrixU
{
public:
    MatrixU()
    {
        pdata_ = new int[nRow_*nCol_];
    }
    ~MatrixU()
    {
        delete[] pdata_;
    }
    int& at(const ptrdiff_t iRow, const ptrdiff_t iCol);
    const int& at(const ptrdiff_t iRow, const ptrdiff_t iCol) const;
    MatrixU(const ptrdiff_t nRow, const ptrdiff_t nCol)
    {
        nRow_ = nRow;
        nCol_ = nCol;
        pdata_ = new int[nRow_*nCol_];
        for (ptrdiff_t i = 0; i < nRow_ * nCol_; i += 1)
            pdata_[i] = 0;
    }
    MatrixU(const MatrixU& m)
    {
        nRow_ = m.nRow_;
        nCol_ = m.nCol_;
        pdata_ = new int[nRow_*nCol_];
        for (ptrdiff_t i = 0; i < nRow_ * nCol_; i += 1)
            pdata_[i] = m.pdata_[i];
    }
    MatrixU operator=(const MatrixU& m)
    {
        for (ptrdiff_t i = 0; i < nRow_*nCol_; i += 1)
            pdata_[i] = m.pdata_[i];
        return *this;
    }
    bool isSizeEqual(const MatrixU& m);
    MatrixU operator+=(const MatrixU& m);
    MatrixU operator-=(const MatrixU& m);
    const bool isMultiplicationPossible(const MatrixU& m) const;
    const ptrdiff_t getnRow() const;
    const ptrdiff_t getnCol() const;

    std::ostream& writeTo(std::ostream& ostrm) const;

private:
    ptrdiff_t nRow_{ 0 };
    ptrdiff_t nCol_{ 0 };
    int* pdata_{ nullptr };
};
MatrixU operator*(const MatrixU& m, const MatrixU& n);

inline std::ostream& operator<<(std::ostream& ostrm, const MatrixU& rhs)
{
    return rhs.writeTo(ostrm);
}

#endif