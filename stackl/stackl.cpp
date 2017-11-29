#include"stackl.h"

bool StackL::isEmpty() const
{
    return (pHead_ == nullptr);
}

StackL StackL::operator=(const StackL& s)
{

    return *this;
}

StackL::StackL(const StackL& s)
{
    //Node* p = s.pHead_;
    //while (p != NULL)
    //{
    //    push(p->data_);
    //    p = p->pNext_;
    //}
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