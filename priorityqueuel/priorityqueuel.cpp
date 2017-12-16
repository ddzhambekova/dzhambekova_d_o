#include "priorityqueuel.h"

bool PriorityQueueL::isEmpty() const
{
    return (pHead_ == nullptr);
}

PriorityQueueL::PriorityQueueL(const PriorityQueueL& pq)
{
    Node *p = pq.pHead_;
    while (p != nullptr)
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

PriorityQueueL &PriorityQueueL::operator=(const PriorityQueueL &q) {
    if (q.isEmpty())
    {
        while (!isEmpty())
        {
            pop();
        }
    }
    if (isEmpty())
    {
        Node *pCopyFrom(q.pHead_);
        while (pCopyFrom != nullptr)
        {
            push(pCopyFrom->data_);
            pCopyFrom = pCopyFrom->pNext_;
        }
    }
    Node* pFrom(q.pHead_);
    Node* p(pHead_);
    while (pFrom->pNext_ != nullptr && p->pNext_ != nullptr)
    {

        p->data_ = pFrom->data_;
        pFrom = pFrom->pNext_;
        p = p->pNext_;
    }
    if (pFrom->pNext_ == nullptr && p->pNext_ != nullptr)
    {
        p->data_ = pFrom->data_;
        Node *pdeleted;
        while (p->pNext_ != nullptr)
        {
            pdeleted = p->pNext_;
            p->pNext_ = pdeleted->pNext_;
            delete pdeleted;
        }
    }
    if (p->pNext_ == nullptr && pFrom->pNext_ != nullptr)
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