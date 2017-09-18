#pragma once

class Foo
{
private:
    int* m_pointer;

public:
    Foo(const int value);
    Foo(const Foo& source);

    ~Foo();

    int GetValue();
};