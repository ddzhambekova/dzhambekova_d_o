#include"stackl.h"

bool StackL::isEmpty() const
{
    return (pHead_ == nullptr);
}

StackL StackL::operator=(const StackL& s)
{
    Node* p = pHead_;
    Node* pFrom = s.pHead_;
    while ((p->pNext_ != nullptr) && (pFrom->pNext_ != nullptr))
    {
        p->data_ = pFrom->data_;
        p = p->pNext_;
        pFrom = pFrom->pNext_;
    }
    if ((p->pNext_ == nullptr) && (pFrom->pNext_ != nullptr))
    {
        p->data_ = pFrom->data_;
        pFrom = pFrom->pNext_;
        while (pFrom != nullptr)
        {
            p->pNext_ = new Node(nullptr, pFrom->data_);
            p = p->pNext_;
            pFrom = pFrom->pNext_;
        }
    }
    else
    {
        if ((pFrom->pNext_ == nullptr) && (p->pNext_ != nullptr))
        {
            p->data_ = pFrom->data_;
            Node* p1(p->pNext_);
            p->pNext_ = nullptr;
            Node* pdeleted;
            while (p1 != nullptr)
            {
                pdeleted = p1;
                p1 = pdeleted->pNext_;
                delete pdeleted;
            }
        }
    }
    return *this;
}

StackL::StackL(const StackL& s)
{
    Node* pFrom(s.pHead_->pNext_);
    Node* p = new Node(nullptr, s.pHead_->data_);
    pHead_ = p;
    while (pFrom != nullptr)
    {
        p->pNext_ = new Node(nullptr, pFrom->data_);
        p = p->pNext_;
        pFrom = pFrom->pNext_;
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