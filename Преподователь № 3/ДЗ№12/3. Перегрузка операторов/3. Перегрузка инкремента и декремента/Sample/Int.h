#pragma once

class Int
{
private:
    int m_number;

public:
    Int();
    Int(const int number);

    Int& operator++(); // Префиксный инкремент.
    Int& operator--(); // Префиксный декремент.
    Int operator+(const Int& number) const;
    Int operator++(int); // Постфиксный инкремент.
    Int operator--(int); // Постфиксный декремент.

    void Show() const;
};