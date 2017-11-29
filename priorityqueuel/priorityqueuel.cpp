#include "priorityqueuel.h"

bool PriorityQueueL::isEmpty() const
{
    return (pHead_ == nullptr);
}

void PriorityQueueL::pop()
{
    if (!isEmpty())
    {

        Node* pdeleted(pHead_);
        pHead_ = pdeleted->pNext_;
        delete pdeleted;
    }
    else
    {
        throw 10;
    }
}

void PriorityQueueL::push(const double& v)
{
    double ss = pow(10, -5);
    Node *p;
    if (!isEmpty())
    {
        if (pHead_->data_ - v > ss)
        {
            pHead_ = new Node(pHead_, v);
        }
        else
        {
            p = pHead_;
            while (p->pNext_ != nullptr && p->pNext_->data_ - v <= ss)
            {
                p = p->pNext_;
            }
            Node *pnext = p->pNext_;
            p->pNext_ = new Node(pnext, v);
        }
    }
    else
    {
        pHead_ = new Node(nullptr, v);
        pTail_ = pHead_;
    }
}

double& PriorityQueueL::front()
{
    if (!isEmpty())
    {
        return pHead_->data_;
    }
    else
    {
        throw 11;
    }
}

double& PriorityQueueL::back()
{
    if (!isEmpty())
    {
        return pTail_->data_;
    }
    else
    {
        throw 12;
    }
}

PriorityQueueL PriorityQueueL::operator=(const PriorityQueueL& p)
{
    return *this;
}

PriorityQueueL::PriorityQueueL(const PriorityQueueL& p)
{

}

std::ostream& PriorityQueueL::writeTo(std::ostream& ostrm) const
{
    Node* p = pHead_;
    while (p != NULL)
    {
        ostrm << p->data_ << ' ';
        p = p->pNext_;
    }
    return ostrm;
}