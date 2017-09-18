#pragma once

class Foo
{
private:
    int m_data;

    // Константа.
    const double m_const;

    // Ссылка.
    int& m_reference;

public:
    Foo(const int data);

    void Show();
};