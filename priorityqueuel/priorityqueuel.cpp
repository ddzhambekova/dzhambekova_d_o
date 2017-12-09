#include "priorityqueuel.h"

bool PriorityQueueL::isEmpty() const
{
    return (pHead_ == nullptr);
}

PriorityQueueL::PriorityQueueL(const PriorityQueueL& pq)
{
    /*Head_ = pq.pHead_;
    Node *p = pHead_;
    Node *p1 = pHead_;
    while (p->pNext_ != nullptr)
    {
        p = p->pNext_;
    }
    Node *pnext = p->pNext_;
    pTail_ = pq.pTail_;*/
    Node *p;
    while (p)
    {
        push(p->data_);
        p = p->pNext_;
    }
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
            if (pTail_->data_ - v <= ss)
            {
                pTail_ = new Node(pnext, v);
            }
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