#include "priorityqueuear.h"

bool PriorityQueueAr::isEmpty() const
{
    return (nTail_ == -1);
}

int& PriorityQueueAr::front()
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

int& PriorityQueueAr::back()
{
    if (!isEmpty())
    {
        return pData_[nTail_];
    }
    else
    {
        throw 11;
    }
}

void PriorityQueueAr::push(const int& v)
{
    if (nTail_ == (size - 1))
    {
        int* newData = new int[size + 1];
        for (int i = 0; i <= nTail_; i++)
        {
            newData[i] = pData_[i];
        }
        delete[] pData_;
        pData_ = newData;
        size += 1;
    }
    int n;
    if (!isEmpty())
    {
        if (pData_[nHead_] > v)
        {
            for (int i = nTail_; i >= nHead_; i--)
            {
                pData_[i + 1] = pData_[i];
            }
            pData_[nHead_] = v;
            nTail_ += 1;
        }
        else
        {
            if (pData_[nTail_] < v)
            {
                nTail_ += 1;
                pData_[nTail_] = v;
            }
            else
            {
                n = nHead_;
                while (pData_[n + 1] <= v && n != (nTail_ + 1))
                {
                    n += 1;
                }
                int nnext = n + 1;

                for (int i = nTail_; i >= nnext; i--)
                {
                    pData_[i + 1] = pData_[i];
                }
                pData_[nnext] = v;
                nTail_ += 1;
            }
        }
    }
    else
    {
        pData_ = new int[size];
        nTail_ += 1;
        pData_[nTail_] = v;
    }
}

void PriorityQueueAr::pop()
{
    if (!isEmpty())
    {
        nHead_ += 1;
    }
    else
    {
        throw 12;
    }
}

PriorityQueueAr PriorityQueueAr::operator=(PriorityQueueAr& q)
{
    if (!q.isEmpty())
    {
        if (isEmpty())
        {
            pData_ = new int[q.size];
            nHead_ = q.nHead_;
            nTail_ = q.nTail_;
            for (int i = nHead_; i <= nTail_; i += 1)
            {
                pData_[i] = q.pData_[i];
            }
        }
        else
        {
            if (size > q.size)
            {
                pData_ = new int[q.size];
                nHead_ = q.nHead_;
                nTail_ = q.nTail_;
                for (int i = nHead_; i <= nTail_; i += 1)
                {
                    pData_[i] = q.pData_[i];
                }
            }
            else
            {
                delete[] pData_;
                size = q.size;
                pData_ = new int[size];
                nHead_ = q.nHead_;
                nTail_ = q.nTail_;
                for (int i = nHead_; i <= nTail_; i += 1)
                {
                    pData_[i] = q.pData_[i];
                }
            }
        }
    }
    else
    {
        delete[] pData_;
        nTail_ = -1;
    }
    return *this;
}

PriorityQueueAr::PriorityQueueAr(const PriorityQueueAr& q)
{
    if (!q.isEmpty())
    {
        pData_ = new int[q.size];
        nHead_ = q.nHead_;
        nTail_ = q.nTail_;
        for (int i = nHead_; i <= nTail_; i += 1)
        {
            pData_[i] = q.pData_[i];
        }
    }
    else
    {
        delete[] pData_;
        nTail_ = -1;
    }
}

PriorityQueueAr::~PriorityQueueAr()
{
    delete[] pData_;
}

std::ostream& PriorityQueueAr::writeTo(std::ostream& ostrm) const
{
    if (!isEmpty())
    {
        for (int i = nHead_; i <= nTail_; i += 1)
        {
            ostrm << pData_[i] << std::endl;
        }
    }
    else
    {
        ostrm << "Queue is empty";
    }
    return ostrm;
}