#ifndef MATRIXR_H_20171105
#define MATRIXR_H_20171105

#include<cstddef>
#include<iostream>

class MatrixR
{
public:
    MatrixR()
    {
        pRows_ = new int*[nRow_];
        pRows_[0] = new int[nRow_ * nCol_];
        for (int i = 0; i < nRow_ * nCol_; i++)
        {
            pRows_[i + 1] = pRows_[i + nCol_];
        }
    }
    ~MatrixR()
    {
        for (int i = 0; i < nRow_; i++)
            delete[] pRows_[i];
        delete[] pRows_;
    }
    int& at(const ptrdiff_t iRow, const ptrdiff_t iCol);
    const int& at(const ptrdiff_t iRow, const ptrdiff_t iCol) const;
    MatrixR(const ptrdiff_t nRow, const ptrdiff_t nCol)
    {
        nRow_ = nRow;
        nCol_ = nCol;
        pRows_ = new int*[nRow];
        for (int i = 0; i < nRow; i++)
            pRows_[i] = new int[nCol];
    }
    MatrixR(const MatrixR& m)
    {
        nRow_ = m.nRow_;
        nCol_ = m.nCol_;
        pRows_ = new int*[nRow_];
        for (int i = 0; i < nRow_; i++)
            pRows_[i] = new int[nCol_];
    }
    MatrixR operator=(const MatrixR& m)
    {
        for (int i = 0; i < nRow_; i++)
            pRows_[i] = new int[nCol_];
        return *this;
    }

private:
    ptrdiff_t nRow_{ 0 };
    ptrdiff_t nCol_{ 0 };
    int** pRows_{ nullptr };
};


#endif