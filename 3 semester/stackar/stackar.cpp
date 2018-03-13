#include"stackar.h"

bool StackAr::isEmpty() const
{
    return (nHead_ == -1);
}

int& StackAr::top()
{
    if (!isEmpty())
    {
        return pData_[nHead_];
    }
    else
    {
        throw 10;
    }
}

const int& StackAr::top() const
{
    if (!isEmpty())
    {
        return pData_[nHead_];
    }
    else
    {
        throw 11;
    }
}

void StackAr::push(const int& q)
{
    if (isEmpty())
    {
        pData_ = new int[size];
    }
    if (nHead_ == (size - 1))
    {
        int* newData = new int[size+1];
        for (int i(0); i <= nHead_; i++)
        {
            newData[i] = pData_[i];
        }
        delete[] pData_;
        pData_ = newData;
        size += 1;
    }
    nHead_ += 1;
    pData_[nHead_] = q;
}

void StackAr::pop()
{
    if (!isEmpty())
    {
        nHead_ -= 1;
    }
    else
    {
        throw 12;
    }
}

StackAr StackAr::operator=(StackAr& s)
{
    if (!s.isEmpty())
    {
        if (isEmpty())
        {
            pData_ = new int[s.size];
            for (int i = 0; i <= s.nHead_; i++)
            {
                pData_[i] = s.pData_[i];
            }
            nHead_ = s.nHead_;
        }
        else
        {
            int* t(pData_);
            pData_ = s.pData_;
            s.pData_ = t;
            nHead_ = s.nHead_;
        }
    }
    else
    {
        delete[] pData_;
        nHead_ = -1;
    }
    return *this;
}

StackAr::StackAr(const StackAr& s)
{
    if (!s.isEmpty())
    {
        pData_ = new int[s.size];
        for (int i = 0; i <= s.nHead_; i+=1)
        {
            pData_[i] = s.pData_[i];
        }
        nHead_ = s.nHead_;
    }
    else
    {
        delete[] pData_;
        nHead_ = -1;
    }
}

StackAr::~StackAr()
{
    delete[] pData_;
}

std::ostream& StackAr::writeTo(std::ostream& ostrm) const
{
    if (!isEmpty())
    {
        for (int i = nHead_; i >= 0; i--)
        {
            ostrm << pData_[i] << std::endl;
        }
    }
    else
    {
        ostrm << "Stack is empty";
    }
    return ostrm;
}

