#pragma once

class Int
{
private:
    int m_number;

public:
    Int();
    Int(const int number);

    Int operator*(const Int& number) const;
    Int operator/(const Int& number) const;
    Int operator+(const Int& number) const;
    Int operator-(const Int& number) const;

    void Show() const;
};