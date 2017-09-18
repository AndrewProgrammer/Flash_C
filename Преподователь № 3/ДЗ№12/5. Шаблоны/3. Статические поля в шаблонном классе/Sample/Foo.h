#pragma once

template <typename TItem>
class Foo
{
public:
    static TItem s_count;
};

int Foo<int>::s_count = 20;
double Foo<double>::s_count = 7.5;