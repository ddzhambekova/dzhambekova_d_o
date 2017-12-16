#ifndef STACKAR_H_20171205
#define STACKAR_H_20171205

#include<iostream>

class StackAr
{
public:
    StackAr() = default;
    ~StackAr();
    StackAr operator=(StackAr& s);
    StackAr(const StackAr& s);
    void push(const int& v);
    void pop();
    int& top();
    const int& top() const;
    bool isEmpty() const;

    std::ostream& writeTo(std::ostream& ostrm) const;
private:
    ptrdiff_t size{ 5 };
    int* pData_{ nullptr };
    ptrdiff_t nHead_{ -1 };
};

inline std::ostream& operator<<(std::ostream& ostrm, const StackAr& rhs)
{
    return rhs.writeTo(ostrm);
}

#endif // !STACKAR_H_20171205