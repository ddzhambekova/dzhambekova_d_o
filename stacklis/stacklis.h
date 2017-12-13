#ifndef STACKLIS_H_20171206
#define STACKLIS_H_20171206

#include <iostream>
#include <memory>

class StackLiS
{
public:
    StackLiS() = default;
    ~StackLiS() {}
    StackLiS operator=(const StackLiS& s);
    StackLiS(const StackLiS& s);
    void push(const int& v);
    void pop();
    int& top();
    const int& top() const;
    bool isEmpty() const;

    std::ostream& writeTo(std::ostream& ostrm) const;
private:
    struct Node
    {
        Node(std::shared_ptr<Node> pNext, const int& v)
            : pNext_(pNext)
            , data_(v)
        {
        }
        Node() = default;
        std::shared_ptr<Node> pNext_;
        int data_{ int(0) };
    };
    std::shared_ptr<Node> pHead_{ nullptr };
};

#endif