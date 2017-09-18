#pragma once

class Int
{
private:
    int m_data;

public:
    Int();
    Int(const int data);

    friend Int operator+(const Int& left, const Int& right);
    friend Int operator-(const Int& left, const Int& right);

    void Show();
};