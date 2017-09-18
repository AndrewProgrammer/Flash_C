#pragma once

#include "Foo.h"

class Bar
{
private:
    Foo m_obj;
    int m_value;

public:
    Bar(const int value, const int fooData);

    void Show();
};