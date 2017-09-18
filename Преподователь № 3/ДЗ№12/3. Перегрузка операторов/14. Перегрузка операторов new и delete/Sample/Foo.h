#pragma once

class Foo
{
private:
    int m_data;

public:
    Foo();
    Foo(const int data);

    void* operator new(const size_t size);
    void operator delete(void* data);
    void* operator new[](const size_t size);
    void operator delete[](void* data);

    void Show();
};