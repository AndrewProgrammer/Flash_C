#pragma once

class A
{
private:
    int m_fieldA;

public:
    A();
    A(const int valueA);

    ~A();

    int GetField() const;
};