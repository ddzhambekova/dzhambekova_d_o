#ifndef ARRAY_H_20171025
#define ARRAY_H_20171025

#include <cstddef>
#include <iostream>

class Array
{
public:
    int& operator[](const ptrdiff_t index);
    const int& operator[](const ptrdiff_t index) const;
    Array() //конструктор без параметров
    {
        size_ = 1;
        pdata_ = new int[size_];
        for (int i = 0; i < size_; i++)
            pdata_[i] = 0;
    }
    ~Array() //деструктор
    {
        delete[] pdata_;
    }
    Array(const Array& a) //конструктор копирования
    {
        size_ = a.size_;
        pdata_ = new int[size_];
        for (int i = 0; i < size_; i++)
            pdata_[i] = a.pdata_[i];
    }
    Array(int n) //создание массива с заданным размером
    {
        size_ = n;
        pdata_ = new int[size_];
        for (int i = 0; i < size_; i++)
            pdata_[i] = 0;
    }
    Array operator=(const Array& a) //оператор присваивания
    {
        for (int i = 0; i < size_; i++)
        {
            a.pdata_[i] = pdata_[i];
        }
        return *this;
    }
    int getsize(); //размер массива
    void resize(const int& nsize);
    void insert(const int ind, const int s);
    void remove(const int ind);
    void insertAr(const int ind, Array ar);
    void removeAr(const int ind, const int k);

    static const char leftBrace{'['};
    static const char separator{ ',' };
    static const char rightBrace{ ']' };

    std::ostream& writeTo(std::ostream& ostrm) const;

private:
    ptrdiff_t size_{ 0 };
    int* pdata_{ nullptr };
};

inline std::ostream& operator<<(std::ostream& ostrm, const Array& rhs)
{
    return rhs.writeTo(ostrm);
}

#endif