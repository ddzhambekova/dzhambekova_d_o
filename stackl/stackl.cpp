#include"stackl.h"

bool StackL::isEmpty() const
{
    return (pHead_ == nullptr);
}

StackL StackL::operator=(const StackL& s)
{
    Node* pCopyTo = pHead_;
    Node* pCopyFrom = s.pHead_;
    while ((pCopyTo->pNext_ != nullptr) && (pCopyFrom->pNext_ != nullptr))
    {
        pCopyTo->data_ = pCopyFrom->data_;
        pCopyTo = pCopyTo->pNext_;
        pCopyFrom = pCopyFrom->pNext_;
    }
    if ((pCopyTo->pNext_ == nullptr) && (pCopyFrom->pNext_ != nullptr))
    {
        pCopyTo->data_ = pCopyFrom->data_;
        pCopyFrom = pCopyFrom->pNext_;
        while (pCopyFrom != nullptr)
        {
            pCopyTo->pNext_ = new Node(nullptr, pCopyFrom->data_);
            pCopyTo = pCopyTo->pNext_;
            pCopyFrom = pCopyFrom->pNext_;
        }
    }
    else
    {
        if ((pCopyFrom->pNext_ == nullptr) && (pCopyTo->pNext_ != nullptr))
        {
            pCopyTo->data_ = pCopyFrom->data_;
            Node* pContinue(pCopyTo->pNext_);
            pCopyTo->pNext_ = nullptr;
            Node* pDelete;
            while (pContinue != nullptr)
            {
                pDelete = pContinue;
                pContinue = pDelete->pNext_;
                delete pDelete;
            }
        }
    }
    return *this;
}

StackL::StackL(const StackL& s)
{
    Node* pCopyFrom(s.pHead_->pNext_);
    Node* pCopyTo = new Node(nullptr, s.pHead_->data_);
    pHead_ = pCopyTo;
    while (pCopyFrom != nullptr)
    {
        pCopyTo->pNext_ = new Node(nullptr, pCopyFrom->data_);
        pCopyTo = pCopyTo->pNext_;
        pCopyFrom = pCopyFrom->pNext_;
    }
}

void StackL::pop()
{
    if (!isEmpty())
    {
        Node* pdeleted(pHead_);
        pHead_ = pdeleted->pNext_;
        delete pdeleted;
    }
    else
    {
        throw 200;
    }
}

void StackL::push(const int& v)
{
    pHead_ = new Node(pHead_, v);
}

int& StackL::top()
{
    if(!isEmpty())
    {
        return pHead_->data_;
    }
    throw 100;
}

const int& StackL::top() const
{
    if (!isEmpty())
    {
        return pHead_->data_;
    }
    throw 101;
}

std::ostream& StackL::writeTo(std::ostream& ostrm) const
{
    Node* p = pHead_;
    while (p != NULL)
    {
        ostrm << p->data_ << ' ';
        p = p->pNext_;
    }
    return ostrm;
}