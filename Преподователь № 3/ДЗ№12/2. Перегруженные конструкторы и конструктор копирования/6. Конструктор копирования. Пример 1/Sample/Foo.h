#pragma once

class Foo
{
private:
    int m_value;

public:
    Foo(const int value);

    ~Foo();

    int GetValue();
};