#ifndef PRIORUTYQUEUE_H_20171216
#define PRIORUTYQUEUE_H_20171216

#include <iostream>

class PriorityQueueAr
{
public:
    PriorityQueueAr() = default;
    ~PriorityQueueAr();
    PriorityQueueAr operator=(PriorityQueueAr& q);
    PriorityQueueAr(const PriorityQueueAr& q);
    void push(const int& v);
    void pop();
    int& front();
    int& back();
    bool isEmpty() const;

    std::ostream& writeTo(std::ostream& ostrm) const;
private:
    ptrdiff_t size{ 5 };
    int* pData_{ nullptr };
    ptrdiff_t nHead_{ 0 };
    ptrdiff_t nTail_{ -1 };
};

inline std::ostream& operator<<(std::ostream& ostrm, const PriorityQueueAr& rhs)
{
    return rhs.writeTo(ostrm);
}

#endif