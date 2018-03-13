#include "array.h"


int& Array::operator[](const ptrdiff_t index)
{
    return pdata_[index];
}

const int& Array::operator[](const ptrdiff_t index) const
{
    return pdata_[index];
}

ptrdiff_t Array::getsize()
{
    return size_;
}

void Array::resize(const ptrdiff_t& nsize)
{
    if (size_ < nsize)
    {
        int* newdata = new int[nsize];
        for (int i = 0; i < size_; i += 1)
        {
            newdata[i] = pdata_[i];
        }
        delete[] pdata_;
        pdata_ = newdata;
        size_ = nsize;
    }
    else
    {
        int* newdata = new int[nsize];
        for (int i = 0; i < nsize; i += 1)
        {
            newdata[i] = pdata_[i];
        }
        delete[] pdata_;
        pdata_ = newdata;
        size_ = nsize;
    }
}

void Array::insert(const int ind, const int s)
{
    int* newdata = new int[size_ + 1];
    for (int i = 0; i < size_; i += 1)
    {
        newdata[i] = pdata_[i];
    }
    for (int i = size_; i > ind; i -= 1)
    {
        newdata[i] = newdata[i - 1];
    }
    newdata[ind] = s;
    size_++;
    pdata_ = newdata;
}

void Array::insertAr(const int ind, Array ar)
{
    int* newdata = new int[size_ + ar.size_];
    for (int i = 0; i < size_; i += 1)
    {
        newdata[i] = pdata_[i];
    }
    for (int i = size_ + ar.size_ - 1; i > ind + ar.size_ - 1; i -= 1)
    {
        newdata[i] = newdata[i - ar.size_];
    }
    int t = 0;
    for (int i = ind; i < ind + ar.size_; i += 1)
    {
        newdata[i] = ar.pdata_[t];
        t += 1;
    }
    size_ += ar.size_;
    pdata_ = newdata;
}

void Array::remove(const int ind)
{
    int* newdata = new int[size_];
    for (int i = 0; i < size_; i += 1)
    {
        newdata[i] = pdata_[i];
    }
    for (int i = ind; i < size_ - 1; i += 1)
    {
        newdata[i] = newdata[i + 1];
    }
    size_--;
    pdata_ = newdata;
}

void Array::removeAr(const int ind, const int k)
{
    int* newdata = new int[size_];
    for (int i = 0; i < size_; i += 1)
    {
        newdata[i] = pdata_[i];
    }
    for (int i = ind; i < ind + k; i += 1)
    {
        newdata[i] = newdata[i + k];
    }
    size_ -= k;
    pdata_ = newdata;
}


std::ostream& Array::writeTo(std::ostream& ostrm) const
{
    ostrm << leftBrace;
    for (int i = 0; i < size_ - 1; i += 1)
    {
        ostrm << pdata_[i] << separator;
    }
    ostrm << pdata_[size_ - 1];
    ostrm << rightBrace;
    return ostrm;
}