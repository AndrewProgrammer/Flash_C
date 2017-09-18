#pragma once

class Foo
{
private:
    int m_value;

public:
    Foo();
    Foo(const int value);
    Foo(const int value1, const int value2);

    int GetValue();
    void SetValue(const int value);
};