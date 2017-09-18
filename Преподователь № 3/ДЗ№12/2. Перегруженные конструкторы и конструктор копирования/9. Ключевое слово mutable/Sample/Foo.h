#pragma once

class Foo
{
private:
    mutable double m_floatingValue;
    int m_integerValue;

public:
    Foo();

    double GetMutableValue() const;
    int GetValue() const;
    void SetValue(const int value);
    void Show() const;
};